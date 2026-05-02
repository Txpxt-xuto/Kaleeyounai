#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 300

struct Student {
    char id[20];
    char fname[50];
    char lname[50];
    int mid;
    int Final;
    char grade[5];
};
struct Student students[MAX_STUDENTS];
int studentCount = 0;








void calculateGrades()
{
    for (int i = 0; i < studentCount; i++)
    {

        students[i].Final = (students[i].mid / 3) + 30;
        int total = students[i].Final + students[i].mid;

        if (total >= 90) strcpy(students[i].grade, "A");
        else if (total >= 80) strcpy(students[i].grade, "+B");
        else if (total >= 70) strcpy(students[i].grade, "B");
        else if (total >= 60) strcpy(students[i].grade, "+C");
        else if (total >= 50) strcpy(students[i].grade, "C");
        else if (total >= 40) strcpy(students[i].grade, "+D");
        else if (total >= 30) strcpy(students[i].grade, "D");
        else strcpy(students[i].grade, "F");
    }
}








void openfile()
{
    FILE *fp = fopen("students.dat", "r");

    while (studentCount < MAX_STUDENTS && fscanf(fp, "%s %s %s %d",students[studentCount].id,students[studentCount].fname,students[studentCount].lname,&students[studentCount].mid) != EOF)
    {
        studentCount++;
    }
    fclose(fp);
}







void Searchbyname()
{
    char target[50];
    printf("Enter name to search: ");
    scanf("%s", target);

    for(int i = 0; i < studentCount; i++)
    {
        if(strcmp(students[i].fname, target) == 0)
        {
            printf("ID: %9s | NAME: %15s %-20s | MID: %3d | FINAL: %3d | Grade: %2s\n",students[i].id, students[i].fname, students[i].lname,students[i].mid, students[i].Final, students[i].grade);
        }
    }
}






void Searchbygrade()
{
    char targetGrade[5];
    printf("Enter grade to search (e.g., A or +B): ");
    scanf("%s", targetGrade);

    for(int i = 0; i < studentCount; i++)
    {
        if(strcmp(students[i].grade, targetGrade) == 0)
        {
            printf("ID: %9s | NAME: %15s %-20s | MID: %3d | FINAL: %3d | Grade: %2s\n",students[i].id, students[i].fname, students[i].lname,students[i].mid, students[i].Final, students[i].grade);
        }
    }
}





void Sortbyscore()
{
    for (int i = 0; i < studentCount - 1; i++)
    {
        for (int j = 0; j < studentCount - i - 1; j++)
        {
            if ((students[j].mid + students[j].Final) < (students[j+1].mid + students[j+1].Final))
            {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < studentCount; i++)
    {
      printf("ID: %9s | NAME: %15s %-20s | MID: %3d | FINAL: %3d | Grade: %2s\n",students[i].id, students[i].fname, students[i].lname,students[i].mid, students[i].Final, students[i].grade);
    }
}





int selectmenu()
{
    int choice;
    printf("--- Student Management System ---");
    printf("\n1) Search by name");
    printf("\n2) Search by grade");
    printf("\n3) Sort by score");
    printf("\n4) Exit");
    printf("\nSelect number: ");
    if(scanf("%d", &choice) != 1) return 4;
    return choice;
}







int main()
{
    openfile();
    calculateGrades();
    int menu;
    do {
        menu = selectmenu();
        if(menu == 1) Searchbyname();
        else if(menu == 2) Searchbygrade();
        else if(menu == 3) Sortbyscore();
    } while(menu != 4);

    return 0;
}
