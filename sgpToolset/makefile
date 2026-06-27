all: asm pcconvert.c
	gcc -Wall -ffreestanding pcconvert.c image.c dec.o -m32 -o pcconvert.out

asm: dec.asm
	nasm -f elf dec.asm
