#include <stdio.h>
#include <string.h>
#include <math.h>
struct student
{
    char Id[10];
    char fname[20];
    char lname[20];
    int Mid;
    int Final;
    char grade[5];
};
struct student students[300];
int count=0;

void openfile()
{

    FILE *fp = fopen("students.dat","r");
    while(fscanf(fp,"%s %s %s %d",students[count].Id,students[count].fname,students[count].lname,&students[count].Mid) != EOF)
    {
        count++;
    }
    fclose(fp);
}

void calculatefinalandgrade()
{
    for(int i=0;i<=count;i++)
    {
        students[i].Final=(students[i].Mid/3)+30;
        int total = students[i].Final + students[i].Mid;
        if(total>90) strcpy( students[i].grade,"A");
        else if(total>80) strcpy( students[i].grade,"+B");
        else if(total>70) strcpy( students[i].grade,"B");
        else if(total>60) strcpy( students[i].grade,"+C");
        else if(total>50) strcpy( students[i].grade,"C");
        else if(total>40) strcpy( students[i].grade,"+D");
        else if(total>30) strcpy( students[i].grade,"D");
        else strcpy( students[i].grade,"F");
    }
}

void Searchbyname()
{
    char target[20];
    printf("\nEnter name: ");
    scanf("%s",target);
    for(int i=0;i<=count;i++)
    {
        if(strcmp(students[i].fname,target)==0)
        {
            printf("%10s %20s %20s %3d %3d %3s\n",students[i].Id,students[i].fname,students[i].lname,students[i].Mid, students[i].Final, students[i].grade);
        }
    }
}


void Searchbygrade()
{
    char target[20];
    printf("\nEnter grade: ");
    scanf("%s",target);
    for(int i=0;i<=count;i++)
    {
        if(strcmp(students[i].grade,target)==0)
        {
            printf("%10s %20s %20s %3d %3d %3s\n",students[i].Id,students[i].fname,students[i].lname,students[i].Mid, students[i].Final, students[i].grade);
        }
    }
}

void sort()
{
    for(int i=0;i<=count-1;i++)
    {
        for(int j=0;j<=count-i-1;j++)
        {
            if(students[j].Mid+students[j].Final<students[j+1].Mid+students[j+1].Final)
            {
                struct student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    for(int i=0;i<count;i++)
    {
        printf("%10s %20s %20s %3d %3d %3s\n",students[i].Id,students[i].fname,students[i].lname,students[i].Mid, students[i].Final, students[i].grade);
    }
}



int Menu()
{
    int i;
    printf("====MENU====\n");
    printf("1) Search by name\n");
    printf("2) Search by grade\n");
    printf("3) Sort\n");
    printf("4) Exit\n");
    printf("Enter your ans: ");
    scanf("%d",&i);
    if(i==4) return 0;
    return i;

}
int main()
{
    openfile();
    calculatefinalandgrade();
    int menu;
    do
    {
        menu = Menu();
        if(menu==1) Searchbyname();
        if(menu==2) Searchbygrade();
        if(menu==3) sort();
    } while (menu!=0);
}
