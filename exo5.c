#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include for strtok function



int main() {
    FILE *file = fopen("C:\\Users\\SURFUCE\\Desktop\\eng 2\\s1\\FDS\\tp work\\cv.txt", "r");
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }
    int max_line=1000;

    char line[max_line];

    
int i =0;
    // Read and display each line from the CSV
    while (fgets(line, max_line, file)) {
        
       

        char *name = strtok(line, ",");
        char *phone = strtok(NULL, ",");
        char *email = strtok(NULL, ",");

        if (name && phone && email) {
           
            printf(" contect%d :\n name:%-20s\nnumber:\n %-15s email: %-30s\n",i, name, phone, email);
        } else {
            printf("Invalid contact entry in line: %s\n", line);
        }
        i++;
    }

    fclose(file);
    return 0;
}
