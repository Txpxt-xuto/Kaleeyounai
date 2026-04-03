#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void Menu()
{
    int i;
    do
    {
        printf("\n           Car Rental System           \n");
        printf("*****************************************\n");
        printf("*   [1]  Booking                        *\n");
        printf("*   [2]  Unbooking                      *\n");
        printf("*****************************************\n");
        printf("Please choose menu : ");
        scanf("%d",&i);
        if(i==1) Booking();
        else if(i==2) Unbooking();
        else if(i==3) Search();
        else if(i==4) Readrule();
    }while (i!=5);
}


void Unbooking()
{
    FILE *fp = fopen("CUSTOMER.csv", "r");

    if(fp == NULL)
    {
        printf("File error\n");
        return;
    }
    char searchF[50], searchL[50];

    printf("First name: ");
    scanf("%s", searchF);

    printf("Last name: ");
    scanf("%s", searchL);

    char line[1000];
    int found = 0;

    while(fgets(line, sizeof(line), fp))
    {
        // ข้าม header
        if(strncmp(line, "FirstName", 9) == 0) continue;

        char temp[1000];
        strcpy(temp, line);

        char *fname = strtok(line, ",");
        char *lname = strtok(NULL, ",");
        char *phone = strtok(NULL, ",");
        char *email = strtok(NULL, ",");
        char *price = strtok(NULL, ",");
        char *start = strtok(NULL, ",");
        char *end = strtok(NULL, ",");

        if(fname && lname)
        {
            // ตัด \n
            lname[strcspn(lname, "\n")] = 0;
            if(strcmp(fname, searchF) == 0 && strcmp(lname, searchL) == 0)
            {
                int startCol = atoi(start), targetRow = atoi(price), endCol = atoi(end);
                Deletecustomer("CUSTOMER.csv",searchF,searchL);
                setRangeZero("CAR.csv",targetRow,startCol,endCol);
                found = 1;
                break;
            }
        }
    }

    if(!found) printf("Customer not found\n");
    fclose(fp);
}

void Deletecustomer(char *filename, char *fname, char *lname)
{
    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("Temp.csv", "w");

    if(fp == NULL || temp == NULL)
    {
        printf("File error\n");
        return;
    }

    char line[1000];
    int deleted = 0;

    while(fgets(line, sizeof(line), fp))
    {

        // header → copy ตรง ๆ
        if(strncmp(line, "FirstName", 9) == 0)
        {
            fprintf(temp, "%s", line);
            continue;
        }

        char tempLine[1000];
        strcpy(tempLine, line);
        char *f = strtok(line, ",");
        char *l = strtok(NULL, ",");

        if(f && l)
        {
            l[strcspn(l, "\n")] = 0;
            //  ถ้าตรง -> ไม่เขียน (ลบ)
            if(strcmp(f, fname) == 0 && strcmp(l, lname) == 0)
            {
                deleted = 1;
                continue;
            }
        }
        // แถวอื่นเขียนตามปกติ
        fprintf(temp, "%s", tempLine);
    }

    fclose(fp);
    fclose(temp);
    remove(filename);
    rename("Temp.csv", filename);

    if (deleted) printf("Customer deleted successfully!\n");
    else printf("Delete ERROR!!\n");
}

void setRangeZero(char *filename, int targetRow, int startCol, int endCol)
{
    FILE *fp = fopen(filename, "r");
    FILE *temp = fopen("temp.csv", "w");

    if(fp == NULL || temp == NULL)
    {
        printf("File error\n");
        return;
    }
    char line[10000];
    int currentRow = 0;
    while(fgets(line, sizeof(line), fp))
    {
        currentRow++;
        if(currentRow == 1)
        {
            fprintf(temp, "%s", line);
            continue;
        }
        if(currentRow == targetRow + 1)
        {
            int col = 1;
            char *token = strtok(line, ",");

            while(token != NULL)
            {
                if(col >= startCol && col <= endCol) fprintf(temp, "0");
                else
                {
                    token[strcspn(token, "\n")] = 0;
                    fprintf(temp, "%s", token);
                }
                token = strtok(NULL, ",");
                if(token != NULL) fprintf(temp, ",");
                col++;
            }
            fprintf(temp, "\n");
        }
        else fprintf(temp, "%s", line); // แถวอื่น copy โง่ๆ
    }
    fclose(fp);
    fclose(temp); // แทนไฟล์เดิม
    remove(filename);
    rename("temp.csv", filename);
    printf("Unbooking Successfully!\n");
}






int main()
{
    Menu();
}
