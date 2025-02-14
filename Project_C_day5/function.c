#include <stdio.h>
#include <string.h>
#include "datatype.h"
#include "function.h"
#define MAX 100


#define FILE_NAME "students.txt"

void saveStudents(Student students[], int count) {
    FILE *file = fopen(FILE_NAME, "wb"); 
    if (file) {
        fwrite(&count, sizeof(int), 1, file);
        fwrite(students, sizeof(Student), count, file);
        fclose(file);
    }
}

void loadStudents(Student students[], int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file) {
        fread(count, sizeof(int), 1, file);
        fread(students, sizeof(Student), *count, file);
        fclose(file);
    }
}

void mainMenu() {
    printf("***Student Management System Using C***\n");
    printf("CHOOSE YOUR ROLE\n");
    printf("========================\n");
    printf("[1] Admin\n");
    printf("[2] Student\n");
    printf("[3] Teacher\n");
    printf("[0] Exit the Program\n");
    printf("========================\n");
    printf("Enter Your Choice: ");
}

void studentMenu() {
    printf("***Student Management Menu***\n");
    printf("[1] Add A New Student\n");
    printf("[2] Show All Students\n");
    printf("[3] Search A Student\n");
    printf("[4] Edit A Student\n");
    printf("[5] Delete A Student\n");
    printf("[6] Sort Students\n");
    printf("[7] Reset Student List\n");
    printf("[0] Back to Main Menu\n");
    printf("Enter Your Choice: ");
}

void inputStudent(Student students[], int *count) {
    if (*count >= MAX) {
        printf("Student list is full!\n");
        return;
    }
    Student newStudent;
    int isDuplicate;
    
    do {
        isDuplicate = 0;
        printf("Enter Student ID: ");
        scanf("%d", &newStudent.id);
        for (int i = 0; i < *count; i++) {
            if (students[i].id == newStudent.id) {
                printf("ID already exists. Please enter a different ID.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    
    printf("Enter Student Name: ");
    scanf("%s", newStudent.name);
    
    do {
        isDuplicate = 0;
        printf("Enter Student Email: ");
        scanf("%s", newStudent.email);
        for (int i = 0; i < *count; i++) {
            if (strcmp(students[i].email, newStudent.email) == 0) {
                printf("Email already exists. Please enter a different email.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    
    do {
        isDuplicate = 0;
        printf("Enter Phone: ");
        scanf("%s", newStudent.phone);
        for (int i = 0; i < *count; i++) {
            if (strcmp(students[i].phone, newStudent.phone) == 0) {
                printf("Phone number already exists. Please enter a different phone number.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);

    printf("Enter Industry: ");
    scanf("%s", newStudent.industry);
    
    students[(*count)++] = newStudent;
    saveStudents(students, *count);
    printf("Student added successfully!\n");
}


void displayStudents(Student students[], int count) {
	if (count == 0) {
        printf("No students found!\n");
        return;
    }
    printf("======================================================================================\n");
    printf("| %-5s | %-20s | %-20s | %-15s | %-10s |\n", "ID", "Name", "Email", "Phone", "Industry");
    for (int i = 0; i < count; i++) {
    	printf("--------------------------------------------------------------------------------------\n");
        printf("| %-5d | %-20s | %-20s | %-15s | %-10s |\n", students[i].id, students[i].name, students[i].email, students[i].phone, students[i].industry);
    }
        printf("======================================================================================\n");

}

void searchStudent(Student students[], int count) {
    char keyword[50];
    printf("Enter the first letter(s) of the student's name: ");
    scanf("%s", keyword);
    
    printf("======================================================================================\n");
    printf("| %-5s | %-20s | %-20s | %-15s | %-10s |\n", "ID", "Name", "Email", "Phone", "Industry");
    printf("--------------------------------------------------------------------------------------\n");
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strncmp(students[i].name, keyword, strlen(keyword)) == 0) {
            printf("| %-5d | %-20s | %-20s | %-15s | %-10s |\n", students[i].id, students[i].name, students[i].email, students[i].phone, students[i].industry);
            found = 1;
    		printf("======================================================================================\n");

        }
    }
    
    if (!found) {
        printf("No students found with the given name keyword.\n");
    }
}

void editStudent(Student students[], int count) {
    int id;
    printf("Enter ID to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Enter New Name: ");
            scanf("%s", students[i].name);
            printf("Enter New Email: ");
            scanf("%s", students[i].email);
            printf("Enter New Phone: ");
            scanf("%s", students[i].phone);
            printf("Enter New Industry: ");
            scanf("%s", students[i].industry);
            saveStudents(students, count);
            printf("Student information updated!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void deleteStudent(Student students[], int *count) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            saveStudents(students, *count);
            printf("Student deleted successfully!\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void sortStudents(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (students[i].id > students[j].id) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    saveStudents(students, count);
    printf("Students sorted successfully!\n");
}

void resetStudents(Student students[], int *count) {
    *count = 0;
    saveStudents(students, *count);
    printf("Student list has been reset!\n");
}
