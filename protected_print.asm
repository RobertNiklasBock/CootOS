[bits 32] ; using 32-bit protected mode

; this is how constants are defined
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f ; the color byte for each character

print_string_pm:
    pusha
    call clear_all
    mov edx, VIDEO_MEMORY

print_string_pm_loop:
    mov al, [ebx] ; [ebx] is the address of our character
    mov ah, WHITE_ON_BLACK

    cmp al, 0 ; check if end of string
    je print_string_pm_done

    mov [edx], ax ; store character + attribute in video memory
    add ebx, 1 ; next char
    add edx, 2 ; next video memory position

    jmp print_string_pm_loop

clear_all:
    mov al, 0x20
    mov ah, WHITE_ON_BLACK

    mov ecx, VIDEO_MEMORY
    add ecx, 4000; (25 * 80 - 1) * 2

    clear_loop:
        mov [ecx], ax
        sub ecx, 2

        cmp ecx, VIDEO_MEMORY - 2
        jne clear_loop
    ret



print_string_pm_done:
    popa
    ret