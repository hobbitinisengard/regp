[bits 32]
;global _decompress -> for windows
global decompress

section .data

section .text
; =============== S U B R O U T I N E =======================================

; Attributes: bp-based frame

decompress:
 _decompress:
section .text

	push edx
	push ecx
	mov   edx, [esp+12]   ; argument 1 in buffer
    mov   ecx, [esp+16]   ; argument 2 out buffer
   push    ebp
   mov     ebp, esp
   sub     esp, 8
   mov     ax, [edx]
   push    ebx
   push    esi
   mov     esi, ecx
   mov     [ebp-8], esi
   push    edi
   mov     [esi], ax
   add     esi, 2
   add     edx, 2
loc_42017A:
   mov     ax, [edx]
   test    ah, 80h
   jz      loc_420193
loc_420182:
   add     edx, 2
   mov     [esi], ax
   add     esi, 2
   mov     ax, [edx]
   test    ah, 80h
   jnz     loc_420182
loc_420193:
   mov     cx, [edx]
   add     edx, 2
   test    ch, 40h
   jz      loc_42023B
   and     ecx, 0FFFFh
   mov     eax, ecx
   and     eax, 7FFh
   shr     ecx, 0Bh
   lea     eax, [eax+eax+2]
   and     ecx, 7
   mov     edi, eax
   mov     eax, esi
   sub     eax, edi
   inc     ecx
   cmp     ecx, 8
   ja      loc_420264
   jmp     [off_420538+ecx*4]
loc_4201D0:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4201DC:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4201E8:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4201F4:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_420200:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_42020C:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_420218:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_420224:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_420230:
   mov     ax, [eax]
   mov     [esi], ax
   add     esi, 2
   jmp     loc_420264
loc_42023B:
   and     ecx, 3FFFh
   mov     [ebp-4], ecx
   jz      loc_420526
   add     ecx, ecx
   xor     eax, eax
   mov     ebx, ecx
   mov     edi, esi
   shr     ecx, 2
   rep stosd
   mov     ecx, ebx
   and     ecx, 3
   rep stosb
   mov     ecx, [ebp-4]
   lea     esi, [esi+ecx*2]
loc_420264:
   mov     ax, [edx]
   test    ah, 80h
   jz      loc_42027D
loc_42026C:
   add     edx, 2
   mov     [esi], ax
   add     esi, 2
   mov     ax, [edx]
   test    ah, 80h
   jnz     loc_42026C
loc_42027D:
   mov     cx, [edx]
   add     edx, 2
   test    ch, 40h
   jz      loc_420325
   and     ecx, 0FFFFh
   mov     eax, ecx
   and     eax, 7FFh
   shr     ecx, 0Bh
   lea     eax, [eax+eax+2]
   and     ecx, 7
   mov     edi, eax
   mov     eax, esi
   sub     eax, edi
   inc     ecx
   cmp     ecx, 8
   ja      loc_42034E
   jmp     [off_42055C+ecx*4]
loc_4202BA:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4202C6:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4202D2:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4202DE:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4202EA:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4202F6:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_420302:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_42030E:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_42031A:
   mov     ax, [eax]
   mov     [esi], ax
   add     esi, 2
   jmp     loc_42034E
loc_420325:
   and     ecx, 3FFFh
   mov     [ebp-4], ecx
   jz      loc_420526
   add     ecx, ecx
   xor     eax, eax
   mov     ebx, ecx
   mov     edi, esi
   shr     ecx, 2
   rep stosd
   mov     ecx, ebx
   and     ecx, 3
   rep stosb
   mov     ecx, [ebp-4]
   lea     esi, [esi+ecx*2]
loc_42034E:
   mov     ax, [edx]
   test    ah, 80h
   jz      loc_420367
loc_420356:
   add     edx, 2
   mov     [esi], ax
   add     esi, 2
   mov     ax, [edx]
   test    ah, 80h
   jnz     loc_420356
loc_420367:
   mov     cx, [edx]
   add     edx, 2
   test    ch, 40h
   jz      loc_42040F
   and     ecx, 0FFFFh
   mov     eax, ecx
   and     eax, 7FFh
   shr     ecx, 0Bh
   lea     eax, [eax+eax+2]
   and     ecx, 7
   mov     edi, eax
   mov     eax, esi
   sub     eax, edi
   inc     ecx
   cmp     ecx, 8
   ja      loc_420438
   jmp     [off_420580+ecx*4]
loc_4203A4:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4203B0:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4203BC:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4203C8:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4203D4:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4203E0:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4203EC:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4203F8:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_420404:
   mov     ax, [eax]
   mov     [esi], ax
   add     esi, 2
   jmp     loc_420438
loc_42040F:
   and     ecx, 3FFFh
   mov     [ebp-4], ecx
   jz      loc_420526
   add     ecx, ecx
   xor     eax, eax
   mov     ebx, ecx
   mov     edi, esi
   shr     ecx, 2
   rep stosd
   mov     ecx, ebx
   and     ecx, 3
   rep stosb
   mov     ecx, [ebp-4]
   lea     esi, [esi+ecx*2]
loc_420438:
   mov     ax, [edx]
   test    ah, 80h
   jz      loc_420451
loc_420440:
   add     edx, 2
   mov     [esi], ax
   add     esi, 2
   mov     ax, [edx]
   test    ah, 80h
   jnz     loc_420440
loc_420451:
   mov     cx, [edx]
   add     edx, 2
   test    ch, 40h
   jz      loc_4204FC
   and     ecx, 0FFFFh
   mov     eax, ecx
   and     eax, 7FFh
   shr     ecx, 0Bh
   lea     eax, [eax+eax+2]
   and     ecx, 7
   mov     edi, eax
   mov     eax, esi
   sub     eax, edi
   inc     ecx
   cmp     ecx, 8
   ja      loc_42017A
   jmp     [off_4205A4+ecx*4]
loc_42048E:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_42049A:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4204A6:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4204B2:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4204BE:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4204CA:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4204D6:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4204E2:
   mov     cx, [eax]
   mov     [esi], cx
   add     esi, 2
   add     eax, 2
loc_4204EE:
   mov     ax, [eax]
   mov     [esi], ax
   add     esi, 2
   jmp     loc_42017A
loc_4204FC:
   and     ecx, 3FFFh
   mov     [ebp-4], ecx
   jz      loc_420526
   add     ecx, ecx
   xor     eax, eax
   mov     ebx, ecx
   mov     edi, esi
   shr     ecx, 2
   rep stosd
   mov     ecx, ebx
   and     ecx, 3
   rep stosb
   mov     ecx, [ebp-4]
   lea     esi, [esi+ecx*2]
   jmp     loc_42017A
loc_420526:
   mov     edx, [ebp-8]
   mov     eax, esi
   sub     eax, edx
   pop     edi
   pop     esi
   pop     ebx
   sar     eax, 1
   mov     esp, ebp
   pop     ebp
   pop ecx
   pop edx
   retn 
   
align 4
off_420538:     dd  loc_420230,    ; DATA XREF:
                dd  loc_420224    ; jump table for switch statement
                dd  loc_420218
                dd  loc_42020C
                dd  loc_420200
                dd  loc_4201F4
                dd  loc_4201E8
                dd  loc_4201DC
                dd  loc_4201D0
off_42055C      dd  loc_42031A    ; DATA XREF:
                dd  loc_42030E    ; jump table for switch statement
                dd  loc_420302
                dd  loc_4202F6
                dd  loc_4202EA
                dd  loc_4202DE
                dd  loc_4202D2
                dd  loc_4202C6
                dd  loc_4202BA
off_420580      dd  loc_420404    ; DATA XREF: 
                dd  loc_4203F8    ; jump table for switch statement
                dd  loc_4203EC
                dd  loc_4203E0
                dd  loc_4203D4
                dd  loc_4203C8
                dd  loc_4203BC
                dd  loc_4203B0
                dd  loc_4203A4
off_4205A4      dd  loc_4204EE    ; DATA XREF: 
                dd  loc_4204E2    ; jump table for switch statement
                dd  loc_4204D6
                dd  loc_4204CA
                dd  loc_4204BE
                dd  loc_4204B2
                dd  loc_4204A6
                dd  loc_42049A
                dd  loc_42048E
                align 10h
