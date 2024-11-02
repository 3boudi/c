#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1) // Ensure no padding is added to structs

// Define the BMP file header structure
typedef struct {
    unsigned short bfType;          // File type ("BM" for Bitmap)
    unsigned int bfSize;            // Size of the file in bytes
    unsigned short bfReserved1;     // Reserved; must be zero
    unsigned short bfReserved2;     // Reserved; must be zero
    unsigned int bfOffBits;         // Offset to start of pixel data
} BITMAPFILEHEADER;

// Define the BMP info header structure
typedef struct {
    unsigned int biSize;            // Size of the BITMAPINFOHEADER
    int biWidth;                    // Width of the image
    int biHeight;                   // Height of the image
    unsigned short biPlanes;        // Number of color planes (must be 1)
    unsigned short biBitCount;      // Bits per pixel (e.g., 24 for RGB)
    unsigned int biCompression;     // Compression type (0 for no compression)
    unsigned int biSizeImage;       // Size of the pixel data
    int biXPelsPerMeter;            // Horizontal resolution
    int biYPelsPerMeter;            // Vertical resolution
    unsigned int biClrUsed;         // Number of colors in the color palette
    unsigned int biClrImportant;    // Number of important colors
} BITMAPINFOHEADER;

#pragma pack(pop) // End of no-padding

int main() {
    FILE *file = fopen("C:\\Users\\SURFUCE\\Desktop\eng 2\\s1\\FDS\\tp work\\Untitled.bmp", "rb");
    if (file == NULL) {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    // Read the BITMAPFILEHEADER
    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, file);

    // Check if it's a BMP file by verifying the signature
    if (fileHeader.bfType != 0x4D42) { // "BM" in hexadecimal
        printf("Error: Not a valid BMP file.\n");
        fclose(file);
        return 1;
    }

    // Read the BITMAPINFOHEADER
    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    // Display metadata
    printf("BMP Metadata:\n");
    printf("File Size: %u bytes\n", fileHeader.bfSize);
    printf("Image Width: %d pixels\n", infoHeader.biWidth);
    printf("Image Height: %d pixels\n", infoHeader.biHeight);
    printf("Color Depth: %d bits per pixel\n", infoHeader.biBitCount);
    printf("Compression: %u\n", infoHeader.biCompression);

    // Move to the pixel data location
    fseek(file, fileHeader.bfOffBits, SEEK_SET);

    // Determine bytes per pixel (BPP) based on color depth
    int bytesPerPixel = infoHeader.biBitCount / 8;

    // Read and display the first 10 pixels
    printf("\nFirst 10 Pixels:\n");
    for (int i = 0; i < 10; i++) {
        unsigned char pixel[3]; // RGB pixel (assuming 24-bit BMP)
        fread(pixel, bytesPerPixel, 1, file);

        if (bytesPerPixel == 3) { // 24-bit RGB format
            printf("Pixel %d: R=%d, G=%d, B=%d\n", i + 1, pixel[2], pixel[1], pixel[0]);
        } else if (bytesPerPixel == 4) { // 32-bit RGBA format
            printf("Pixel %d: R=%d, G=%d, B=%d, A=%d\n", i + 1, pixel[2], pixel[1], pixel[0], pixel[3]);
        }
    }

    fclose(file);
    return 0;
}
