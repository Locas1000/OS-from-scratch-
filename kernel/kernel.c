void main() {
    // Pointer to video memory
    char* video_memory = (char*) 0xb8000;
    // Write 'X' to the top-left corner
    *video_memory = 'X';
}

// This function must be FIRST so the bootloader hits it
void dummy_test_entrypoint() {
    main();
}