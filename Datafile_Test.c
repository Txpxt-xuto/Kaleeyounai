#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 200

// Define what a single student looks like
struct Student {
    char id[20];
    char fname[50];
    char lname[50];
    int mid;
    int final;
    char grade;
};

// Create an array to hold many students
struct Student students[MAX_STUDENTS];
int studentCount = 0;

void openfile() {
    FILE *fp = fopen("students.dat", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    // Read until end of file or until array is full
    while (studentCount < MAX_STUDENTS && 
           fscanf(fp, "%s %s %s %d %d %c", 
                  students[studentCount].id, 
                  students[studentCount].fname, 
                  students[studentCount].lname, 
                  &students[studentCount].mid,
                  &students[studentCount].final,
                  &students[studentCount].grade) != EOF) {
        
        // Print as we read to verify
        printf("Loaded: %s %s %s\n", students[studentCount].id, 
                                     students[studentCount].fname, 
                                     students[studentCount].lname);
        studentCount++;
    }

    fclose(fp);
}

void Searchbyname() {
    char target[50];
    printf("Enter name to search: ");
    scanf("%s", target);
    
    for(int i = 0; i < studentCount; i++) {
        if(strcmp(students[i].fname, target) == 0) {
            printf("Found: %s %s - Grade: %c\n", students[i].fname, students[i].lname, students[i].grade);
        }
    }
}

void Searchbygrade() {
    char targetGrade;
    printf("Enter grade to search (A/B/C/D/F): ");
    scanf(" %c", &targetGrade); // Note the space before %c to skip newline
    
    for(int i = 0; i < studentCount; i++) {
        if(students[i].grade == targetGrade) {
            printf("%s %s\n", students[i].fname, students[i].lname);
        }
    }
}

void Sortbyscore() {
    // A simple Bubble Sort example based on midterm score
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].mid < students[j+1].mid) {
                struct Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    printf("Sorted by Midterm Score (Highest first).\n");
}

int selectmenu() {
    int choice;
    printf("\n--- Student Management System ---");
    printf("\n1) Search by name");
    printf("\n2) Search by grade");
    printf("\n3) Sort by score");
    printf("\n4) Exit");
    printf("\nSelect number: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    openfile();
    
    int menu;
    do {
        menu = selectmenu();
        if(menu == 1) Searchbyname();
        else if(menu == 2) Searchbygrade();
        else if(menu == 3) Sortbyscore();
    } while(menu != 4);

    return 0;
}