#include <stdio.h>
#include <ctype.h>
#include <conio.h>

int main()
{

    FILE *amin;
    char A[999];
    char ch;
    int x = 1;
    int n = 1;
    int in_word = 0;
    int word;

    while (x == 1)
    {
        printf("Enter text to the file:\n");
        fgets(A, sizeof(A), stdin);

        amin = fopen("C:<\\Users\\SURFUCE\\Desktop\\eng 2\\s1\\FDS\\tp work\\TEST.exe.txt", "w");
        if (amin == NULL)
        {
            printf("Error opening file!\n");
            return 1;
        }

        for (int i = 1; i <= 10000; i++)
        {
            fprintf(amin, "Text %d: %s", n, A);
            n++;
        }

        fclose(amin);
        printf("Your text is now in the file!\n");

        amin = fopen("C:\\Users\\SURFUCE\\Pictures\\FDS\\TEST.txt", "r");
        if (amin == NULL)
        {
            printf("Error opening file for reading!\n");
            return 1;
        }

        word = 0;
        in_word = 0;

        while ((ch = fgetc(amin)) != EOF)
        {
            if (isspace(ch) || ispunct(ch))
            {
                in_word = 0;
            }
            else if (in_word == 0)
            {
                in_word = 1;
                word++;
            }
        }

        fclose(amin);

        printf("The number of words in the file is: %d\n", word);

        printf("If you want to add to the file, enter 1 for yes and 0 for no:\n");
        scanf("%d", &x);

        fflush(stdin);
    }

    printf("The file is closed.\n");
    return 0;
}
