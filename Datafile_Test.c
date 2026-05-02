#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Datafile_Test
{
    char id[200];
    char fname[200];
    char lname[200];
    int mid[200];
    int final[200];
    char grade[200];
} student;

void openfile()
{
    FILE *fp = fopen("students.dat","r");
    int i=0;
    while(i)
    {
        if(student.id[i]==NULL) break;
        else fscanf("%s %s %s %d",student.id[i],student.fname[i],student.lname[i],&student.mid[i]);
        i++;
    }
    while(i)
    {
        if(student.id[i]==NULL) break;
        else printf("%s %s %s %d\n",student.id[i],student.fname[i],student.lname[i],student.mid[i]);
        i++;
    }
}

void Searchbyname()
{
    return 0;
}

void Searchbygrade()
{
    return 0;
}
void Sortbyscore()
{
    return 0;
}
int selectmenu()
{
    int i;
    do{
        clrscr();
        printf("\n 1) Search by name ");
        printf("\n 2) Search by grade ");
        printf("\n 3) Sort by score ");
        printf("\n 4) Exit ");
        printf("\nSelect number: ");
        scanf("%d",&i);
    }
    while(i<1 || i>4);
    return i;
}

int main()
{
    openfile();
    int menu = selectmenu();
    if(menu==1) Searchbyname();
    else if(menu==2) Searchbygrade();
    else if(menu==3) Sortbyscore();
    else if(menu==4) return 0;
}