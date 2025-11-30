#include "../drivers/ports.h" 

void main() {
    /* 1. Ask VGA hardware for cursor position */
    port_byte_out(0x3d4, 14);
    int position = port_byte_in(0x3d5);
    position = position << 8;

    port_byte_out(0x3d4, 15);
    position += port_byte_in(0x3d5);

    /* 2. Write 'X' at the cursor position */
    int offset_from_vga = position * 2;
    
    /* FIXED: Add (char*) cast to prevent warning */
    char *vga = (char*) 0xb8000;
    vga[offset_from_vga] = 'X'; 
    /* FIXED: Use Red (0x4F) instead of White (0x0f) to make it visible */
    vga[offset_from_vga+1] = 0x4F;
}