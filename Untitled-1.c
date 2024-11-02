#include <stdio.h>
#include <time.h>

void readchar(const char *filepath) {
    printf("Reading the file by character...\n");
    FILE *filetext = fopen(filepath, "r");

    if (filetext == NULL) {
        printf("ERROR 104: Could not open the file.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(filetext)) != EOF) {
        putchar(ch);
    }
    fclose(filetext);
}

void readline(const char *filepath) {
    printf("Reading the file by line...\n");
    FILE *filetex = fopen(filepath, "r");

    if (filetex == NULL) {
        printf("ERROR 104: Could not open the file.\n");
        return;
    }

    char line[1000];
    while (fgets(line, sizeof(line), filetex) != NULL) {
        printf("The text in file: %s", line);
    }
    fclose(filetex);
}

int main() {
    clock_t start1, end1;
    clock_t start2, end2;

    const char *filepath = "C:\\Users\\SURFUCE\\Pictures\\FDS\\TEST.txt";

    // Measure time for reading by character
    start1 = clock();
    readchar(filepath);
    end1 = clock();
    double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("\nTime taken to read by character: %.6f seconds\n", time1);

    // Measure time for reading by line
    start2 = clock();
    readline(filepath);
    end2 = clock();
    double time2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    printf("\nTime taken to read by line: %.6f seconds\n", time2);

    return 0;
}
    char line[255];  // To store each line of the file

    // Open the file for reading
    file = fopen("employees.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read and display the employee data
    printf("Employee Data from File:\n");
    while (fgets(line, sizeof(line), file)) {
        // Print each line from the file
        printf("%s", line);
    }

    // Close the file
    fclose(file);