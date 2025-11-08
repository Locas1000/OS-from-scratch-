[org 0x7c00]       ;global offset

    mov bx, HELLO 
    call print
    call print_nl

    mov bx, GOODBYE
    call print
    call print_nl

    jmp $   ;infinite loop 

    %include "./bootsector-functions/boot_sect_print.asm"
    %include "./bootsector-functions/boot_sect_print_hex.asm"

    HELLO:
        db 'Hello, World',0
    
    GOODBYE:
        db 'Goodbye',0

; Fill with 510 zeros minus the size of the previous code
    times 510-($-$$) db 0
    dw 0xaa55 ; Magic number

