#include<stdio.h>
struct Employee
{
    char name[100];
    int emp_number;
    float emp_salery;

};
int main(){

    struct  Employee emp ;
    FILE *newfile=fopen("C:\\Users\\SURFUCE\\Pictures\\FDS\\emp.txt","a");
    int number_of_emp ;
    if(newfile == NULL){
        printf("error to acces the file!\n");
        return 1 ;
    }
    printf("enter number of employees :\n");
    scanf("%d",&number_of_emp);
        for (int i = 1; i <= number_of_emp; i++)
        {
            printf("enter information  of employee number %d:",i);
            printf("name:");
            scanf("%s",emp.name);
            printf("\t enter emp nember :");
            scanf("%d",&emp.emp_number);
            printf("\t enter emp salary:");
            scanf("%f",&emp.emp_salery);
            fprintf(newfile, "Name: %s\n", emp.name);
            fprintf(newfile, "Employee Number: %d\n", emp.emp_number);
            fprintf(newfile, "Salary: %.2f\n\n", emp.emp_salery);
            
        }
        fclose(newfile);
        printf("your data has saved !! ");
        char line[1000];
        FILE *file=fopen("C:\\Users\\SURFUCE\\Pictures\\FDS\\emp.txt","r");
       while(fgets(line,sizeof(line),file)){
        printf("%s",line);
       }

       fclose(file);
       return 0 ;
        
}
