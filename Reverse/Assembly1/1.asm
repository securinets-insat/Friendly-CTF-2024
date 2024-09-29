section .data
    win_msg db "Congratulations, you can validate with that value!", 10, 0
    value dd 0                  

section .text
    global main
    extern scanf, printf

main:
    push value
    call scanf
    add esp, 4

    mov eax, [value]
    bswap eax

    mov edx, eax
    and eax, 0x0F0F0F0F
    shl eax, 4
    and edx, 0xF0F0F0F0
    shr edx, 4
    or eax, edx

    mov edx, eax
    and eax, 0x33333333
    shl eax, 2
    and edx, 0xCCCCCCCC
    shr edx, 2
    or eax, edx

    mov edx, eax
    and eax, 0x55555555
    shl eax, 1
    and edx, 0xAAAAAAAA
    shr edx, 1
    or eax, edx

    add eax, 0x5A5A5A5A

    cmp eax, 0x08F41CD5
    je Win

    jmp Exit

Win:
    push win_msg
    call printf
    add esp, 4

Exit
    xor eax, eax
    ret
