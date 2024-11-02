#include <stdio.h>

#define MAX_LINE_LENGTH 1000

void Tags(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int intage=0;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        for (int i = 0; line[i] != '\0'; i++) {
           if(line[i]=='<'){
            intage=1;
            printf("<");
           }else if (line[i]=='>')
           {
            intage=0;
            printf(">\n");
           }
           if (intage)
           {
            printf("%c",line[i]);
           }
           
           
        }
    }
}

int main() {
    FILE *file = fopen("C:\\Users\\SURFUCE\\Pictures\\HADJ FOOD\\index.html", "r");  
    if (file == NULL) {
        printf("could not open file.\n");
        return 1;
    }

   Tags(file);

    fclose(file);
    return 0;
}
