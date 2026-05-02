#include <stdio.h>

void convertCsvToSpace() {
    FILE *fin = fopen("CUSTOMERS.csv", "r");
    FILE *fout = fopen("CUSTOMERS_SPACE.txt", "w");

    if (fin == NULL || fout == NULL) {
        printf("เกิดข้อผิดพลาดในการเปิดไฟล์\n");
        return;
    }

    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        if (ch == ',') {
            fputc(' ', fout); // ถ้าเจอคอมมา ให้เขียนเว้นวรรคแทน
        } else {
            fputc(ch, fout);  // ถ้าไม่ใช่ ให้เขียนตัวอักษรเดิม
        }
    }

    fclose(fin);
    fclose(fout);
    printf("แปลงไฟล์สำเร็จ! บันทึกที่ CUSTOMERS_SPACE.txt\n");
}
int main()
{
    convertCsvToSpace();
}
