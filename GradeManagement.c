#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu() {
    printf("\n     Please select an option from the menu below:  \n");
    printf("         1. Add Student \n");
    printf("         2. View Student Grades \n");
    printf("         3. Update Students Grades \n");
    printf("         4. Delete Student Details \n");
    printf("         5. Exit \n");

}
struct Student {
    char name[50];
    int rollNumber;
    float marks[5];
};
void addStudent(struct Student *students, int *count) {
    if (*count >= 60) {
        printf("   Cannot add more students. Maximum limit reached.\n");
        return;
    }
    while (getchar() != '\n'); // Clear the input buffer
    printf("   Enter student name: ");
    fgets(students[*count].name, sizeof(students[*count].name), stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = 0; // Remove newline character
    printf("   Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);
    for (int i = 0; i < 5; i++) {
        printf("   Enter marks for subject %d: ", i + 1);
        scanf("%f", &students[*count].marks[i]);
    }
    (*count)++;
    printf("   Student added successfully!\n");
}
void viewStudents(struct Student *students, int count) {

    if (count == 0) {
        printf("*****  No students available to display. *****\n");
        return;
    }

    printf("*****  Student Details  *****\n");

    for (int i = 0; i < count; i++) {

        float totalMarks = 0;

        printf("\n Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks:\n");

        for (int j = 0; j < 5; j++) {
            printf("     Subject %d: %.2f\n",
                   j + 1, students[i].marks[j]);

            totalMarks += students[i].marks[j];
        }

        printf("Total Marks: %.2f / 500\n", totalMarks);

        float percentage = (totalMarks / 500) * 100;
        printf("Percentage:  %.2f%%\n", percentage);
        
        char grade[3];
        if (percentage >= 90) {
            strcpy(grade, "A+");
        } else if (percentage <= 89 && percentage >= 80) {
            strcpy(grade, "A");
        } else if (percentage <= 79 && percentage >= 70) {
            strcpy(grade, "B");
        } else if (percentage <= 69 && percentage >= 60) {
            strcpy(grade, "C");
        } else {
            strcpy(grade, "F");
        }
        printf("Grade: %s\n", grade);
    }
}
void updateStudent(struct Student *students, int count) {
    if (count == 0) {
        printf("*****  No students available to update. *****\n");
        return;
    }
    int rollNumber;
    printf("   Enter the roll number of the student to update: ");
    scanf("%d", &rollNumber);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("   Updating details for student: %s\n", students[i].name);
            printf("   Enter new name: ");
            while (getchar() != '\n'); // Clear the input buffer
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0; // Remove newline character
            printf("   Enter new roll number: ");
            scanf("%d", &students[i].rollNumber);
            for (int j = 0; j < 5; j++) {
                printf("   Enter new marks for subject %d: ", j + 1);
                scanf("%f", &students[i].marks[j]);
            }
            printf("   Student details updated successfully!\n");
            return;
        }
    }
    printf("   Student with roll number %d not found.\n", rollNumber);

}
void deleteStudent(struct Student *students, int *count){
    if (*count == 0) {
        printf("*****  No students available to delete. *****\n");
        return;
    }
    int rollNumber;
    printf("   Enter the roll number of the student to delete: ");
    scanf("%d", &rollNumber);
    for (int i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
            // Shift all students after the deleted one
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            printf("   Student with roll number %d deleted successfully!\n", rollNumber);
            return;
        }
    }
    printf("   Student with roll number %d not found.\n", rollNumber);
}

int main() {
    printf("***=====================================================================***\n");
    printf("                         Grade Management System\n");
    printf("***=====================================================================***\n");
    
    int choice;
    struct Student students[60];
    int studentCount = 0;
    while(1) {
        displayMenu();
        printf("   Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("   Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }
        
        switch(choice) {
            case 1:
                // Add Student functionality
                addStudent(students, &studentCount);
                break;
            case 2:
                // View Student Grades functionality
                viewStudents(students, studentCount);
                break;
            case 3:
                // Update Students Grades functionality
                updateStudent(students, studentCount);
                break;
            case 4:
                // Delete Student Details functionality
                deleteStudent(students, &studentCount);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("   Invalid choice. Please select a valid option from the menu.\n");
        }
    }
   
}