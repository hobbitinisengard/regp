import argparse
import os
import re
import struct


PRINTABLE_PATH = re.compile(rb"[A-Za-z0-9_./\\-]{4,}\x00")


def read_c_string(data, offset):
    end = data.find(b"\x00", offset)
    if end < 0:
        return None
    return data[offset:end].decode("ascii", errors="replace")


def find_entries(data):
    entries = []
    scan_start = max(0, len(data) - 256 * 1024)
    tail = data[scan_start:]

    for match in PRINTABLE_PATH.finditer(tail):
        name_offset = scan_start + match.start()
        if name_offset < 8:
            continue

        name = read_c_string(data, name_offset)
        if not name or "\\" not in name or "." not in name:
            continue

        file_offset, file_size = struct.unpack_from("<II", data, name_offset - 8)
        if file_size == 0:
            continue
        if file_offset >= len(data) or file_offset + file_size > len(data):
            continue
        if file_offset >= name_offset:
            continue

        entries.append((name, file_offset, file_size, name_offset))

    seen = set()
    unique = []
    for entry in entries:
        key = entry[0].lower()
        if key in seen:
            continue
        seen.add(key)
        unique.append(entry)

    return unique


def find_entry(data, wanted_name):
    wanted_name = wanted_name.lower()
    for name, file_offset, file_size, name_offset in find_entries(data):
        if name.lower() == wanted_name:
            return name, file_offset, file_size, name_offset
    return None


def main():
    parser = argparse.ArgumentParser(description="Inspect Stunt GP WAD directory entries.")
    parser.add_argument("wad")
    parser.add_argument("--limit", type=int, default=25)
    parser.add_argument("--extract")
    parser.add_argument("--out")
    args = parser.parse_args()

    with open(args.wad, "rb") as file:
        data = file.read()

    if args.extract:
        entry = find_entry(data, args.extract)
        if not entry:
            raise SystemExit(f"not found: {args.extract}")

        name, file_offset, file_size, _ = entry
        out_path = args.out or os.path.basename(name)
        with open(out_path, "wb") as file:
            file.write(data[file_offset : file_offset + file_size])
        print(f"extracted {name} -> {out_path} ({file_size} bytes)")
        return

    print(f"{args.wad}")
    print(f"size: {len(data)}")
    print(f"magic: {data[:4]!r}")

    entries = find_entries(data)
    print(f"entries: {len(entries)}")
    for name, file_offset, file_size, name_offset in entries[: args.limit]:
        print(f"{file_offset:08x} {file_size:8d} dir@{name_offset:08x} {name}")

    if len(entries) > args.limit:
        print(f"... {len(entries) - args.limit} more")


if __name__ == "__main__":
    main()
