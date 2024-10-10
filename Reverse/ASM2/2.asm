section .text
global main

main:
    MOV eax, 0x58
    XOR ebx, ebx
    MOV ebx, eax
    XOR eax, 0xF0
    SHR eax, 1
    XOR eax, eax
    XOR eax, ebx
    XOR eax, 0x16

    MOV AL, 0x4F
    XOR AL, 0x10
    ADD AL, 0x51
    XOR AL, 0x10
    NOT AL
    XOR AL, 0x1E

    MOV eax, 0x52
    XOR eax, 0xA
    ADD eax, 0x6
    XOR eax, 0xA
    SUB eax, 0xC

    MOV eax, 0x69
    OR eax, 0x2
    XOR eax, 0x4A
    AND eax, 0xFB
    MOV ecx, eax
    ADD eax, 2
    XOR eax, eax

    XOR eax, 0x6E
    MOV ebx, eax
    XOR eax, 0xF0
    SHL eax, 3
    AND ebx, 0x42
    XOR eax, eax
    XOR eax, ebx

    MOV AL, 0x67
    ROL AL, 1
    XOR AL, 0x6D
    ROR AL, 1
    SUB AL, 0x68
    ADD AL, 0x9

    MOV AL, 0x5F
    ADD AL, 0xB0
    SUB AL, 0xF0
    XOR AL, 0x1F
    MOV DL, 0x3F
    NOT AL
    XOR AL, DL
    SUB AL, 0xF
    XOR DL, DL
    XOR AL, 0x81

    mov eax, 1
    xor ebx, ebx
    int 0x80
