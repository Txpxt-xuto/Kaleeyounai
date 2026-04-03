#include <stdio.h>
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
    setRangeZero("CAR.csv",990, 1, 2);
}