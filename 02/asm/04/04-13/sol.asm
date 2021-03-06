%include 'io.inc'

section .bss
n       resd 1
arr     resd 1000000
k       resd 1

section .text
global CMAIN
CMAIN:

    GET_UDEC 4, n

    cmp DWORD[n], 0
    jg NONTRIVIA
        mov eax, 0
        ret
    NONTRIVIA:

    mov ecx, DWORD[n]
    mov eax, arr
    LREAD:
        GET_UDEC 4, [eax]
        add eax, 4
    loop LREAD

    GET_UDEC 4, k

    BIGLOOP:
        cmp DWORD[k], 0
        jle sBIGLOOP

        mov eax, 0
        mov ebx, arr
        mov ebp, 0
        ERCR:
            cmp eax, DWORD[n]
            je sERCR
            mov ecx, DWORD[ebx]
            mov edx, ecx
            and edx, 1
            ror edx, 1
            shr ecx, 1
            or  ecx, ebp
            mov DWORD[ebx], ecx
            mov ebp, edx
            inc eax
            add ebx, 4
            jmp ERCR
        sERCR:
        mov ecx, DWORD[arr]
        or  ecx, ebp
        mov DWORD[arr], ecx

        dec DWORD[k]
    jmp BIGLOOP
    sBIGLOOP:


    mov eax, arr
    mov ecx, DWORD[n]
    LPRINT:
        PRINT_UDEC 4, [eax]
        PRINT_CHAR " "
        add eax, 4
        dec ecx
        cmp ecx, 0
    jg LPRINT

    NEWLINE

    mov eax, 0
    ret
