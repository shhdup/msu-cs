%include 'io.inc'

section .bss
    n resd 1

section .data
    val     dw '23456789TJQKA'
    lear    dw 'SCDH'

section .text
global CMAIN
CMAIN:
    GET_UDEC 4, eax
    dec eax
    mov ebx, 13
    mov edx, 0
    div ebx

    PRINT_CHAR val+edx
    PRINT_CHAR lear+eax
    NEWLINE

    mov eax, 0
    ret
