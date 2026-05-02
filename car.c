#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 100

struct detail
{
    char car[20];
    char fname[20];
    char lname[20];
    char tel[12];
    char email[20];
    char id[20];
    char start[12];
    char end[12];
    char location[20];
    char day[12];
    char howpay[20];
    char namecard[20];
    char numbercard[20];
    char cvv[20];
    char Exp[20];
    int total;
    char rate[5];

};

struct detail information[Max];
int count = 0;

void Openfile()
{
    FILE *fp = fopen("CUSTOMERS_SPACE.txt","r");
    while(fscanf(fp,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d",information[count].car,information[count].fname,information[count].lname,information[count].tel,
                 information[count].email,information[count].id,information[count].start,information[count].end,information[count].location,information[count].day,
                 information[count].howpay,information[count].namecard,information[count].numbercard,information[count].cvv,information[count].Exp,&information[count].total) != EOF)
    {
        count++;
    }
    fclose(fp);
}

void CreateRate()
{
    for(int i=0;i<count;i++)
    {
        int Total=information[i].total+100*i;
        if(Total>10000) strcpy(information[i].rate,"one");
        else if(Total>5000) strcpy(information[i].rate,"two");
        else if(Total>1000) strcpy(information[i].rate,"three");
        else strcpy(information[i].rate,"four");
    }
}

void searchname()
{
    char target[20];
    printf("--->");
    scanf("%s",target);
    for(int i=0;i<count;i++)
    {
        if(strcmp(information[i].fname,target)==0)
        {
           printf("%-20s %-12s %-12s %-12s %-25s %-10d %-5s\n",information[i].car,information[i].fname,information[i].lname,information[i].tel,information[i].email,information[i].total,information[i].rate); // แสดงเฉพาะค่าสำคัญเพื่อให้บรรทัดไม่ยาวเกินไป

        }

    }
}

void searchcar()
{
    char target[20];
    printf("--->");
    scanf("%s",target);
    for(int i=0;i<count;i++)
    {
        if(strcmp(information[i].car,target)==0)
        {
           printf("%-20s %-12s %-12s %-12s %-25s %-10d %-5s\n",information[i].car,information[i].fname,information[i].lname,information[i].tel,information[i].email,information[i].total,information[i].rate); // แสดงเฉพาะค่าสำคัญเพื่อให้บรรทัดไม่ยาวเกินไป

        }

    }
}

void searchdate()
{
    char target[20];
    printf("--->");
    scanf("%s",target);
    for(int i=0;i<count;i++)
    {
        if(strcmp(information[i].start,target)==0)
        {
           printf("%-20s %-12s %-12s %-12s %-25s %-10d %-5s\n",information[i].car,information[i].fname,information[i].lname,information[i].start,information[i].email,information[i].total,information[i].rate); // แสดงเฉพาะค่าสำคัญเพื่อให้บรรทัดไม่ยาวเกินไป

        }

    }
}

void sort()
{
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-1-i;j++)
        {
            if(information[j].total<information[j+1].total)
            {
                struct detail temp=information[j];
                information[j]=information[j+1];
                information[j+1]=temp;

            }
        }
    }
    for(int i=0;i<count;i++)
    {
        printf("%-20s %-12s %-12s %-12s %-25s %-10d %-5s\n",information[i].car,information[i].fname,information[i].lname,information[i].start,information[i].email,information[i].total,information[i].rate); // แสดงเฉพาะค่าสำคัญเพื่อให้บรรทัดไม่ยาวเกินไป
    }
}




int Menu()
{
    int i;
    printf("*******MENU*******\n");
    printf("1) searchname\n");
    printf("2) searchcar\n");
    printf("3) searchdate\n");
    printf("4) Exit\n");
    printf("5) sort\n");
    scanf("%d",&i);
    if(i==4) return 0;
    else return i;


}

int main()
{
    Openfile();
    CreateRate();
    int menu;
    do
    {
        menu=Menu();
        if(menu==1) searchname();
        else if(menu==2) searchcar();
        else if(menu==3) searchdate();
        else if(menu==5) sort();
    } while(menu!=0);
    return 0;
}
