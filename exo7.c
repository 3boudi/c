#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_LINE 16

void displayHex(const unsigned char *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02X ", buffer[i]);
        if ((i + 1) % BYTES_PER_LINE == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("C:\\eclipse\\eclipse\\eclipsec.exe", "rb");  // Replace "example.exe" with your file name
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    unsigned char buffer[BYTES_PER_LINE];
    int bytesRead;

    printf("Hexadecimal representation of the file:\n");
    printf("----------------------------------------\n");

    while ((bytesRead = fread(buffer, 1, BYTES_PER_LINE, file)) > 0) {
        displayHex(buffer, bytesRead);
    }

    fclose(file);
    return 0;
}
