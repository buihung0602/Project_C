#include <stdio.h>
#include <string.h>
#include "datatype.h"
#include "function.h"
#define MAX 100

#define FILE_TEACHER "teacher.txt"
#define FILE_STUDENT "students.txt"
//luu danh sach hoc sinh vao file student.txt 
void saveStudents(Student students[], int count) {
    FILE *file = fopen(FILE_STUDENT, "wb"); 
    if (file == NULL) {
        printf("Loi: Khong the mo file de ghi\n");
        return;
    }
    
    fwrite(&count, sizeof(int), 1, file);
    fwrite(students, sizeof(Student), count, file);
    
    fclose(file);
    printf("Du lieu da duoc luu vao file\n");
}
//doc danh sach hoc sinh trong file student.txt
void loadStudents(Student students[], int *count) {
    FILE *file = fopen(FILE_STUDENT, "rb");
    if (file == NULL) {
        printf("Loi: Khong the mo file hoac file trong\n");
        return;
    }
    
    fread(count, sizeof(int), 1, file);//doc so luong sinh vien
    fread(students, sizeof(Student), *count, file);
    
    fclose(file);
    printf("Du lieu da duoc tai tu file\n");
}
//menu chinh
void mainMenu() {
    printf("*** Student Management System Using C ***\n");
    printf("CHOOSE YOUR ROLE\n");
    printf("========================\n");
    printf("[1] Student\n");
    printf("[2] Teacher\n");
    printf("[0] Exit the Program\n");
    printf("========================\n");
    printf("Enter Your Choice: ");
}

//menu con
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
//nhap thong tin sinh vien
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
        getchar();
        for (int i = 0; i < *count; i++) {
            if (students[i].id == newStudent.id) {
                printf("ID already exists. Please enter a different ID.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    
    printf("Enter Student Name: ");
	fgets(newStudent.name, sizeof(newStudent.name), stdin);
	newStudent.name[strcspn(newStudent.name, "\n")] = '\0';
    
    do {
        isDuplicate = 0;
        printf("Enter Student Email: ");
        scanf("%s", newStudent.email);
        getchar();
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
        getchar();
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
    getchar();
    
    students[(*count)++] = newStudent;
    saveStudents(students, *count);
    printf("Student added successfully!\n");
}

// hien thi bang liet ke danh sach sinh vien
void displayStudents(Student students[], int count) {
	if (count == 0) {
        printf("No students found!\n");
        return;
    }
    printf("==============================================================================================\n");
    printf("| %-5s | %-20s | %-28s | %-15s | %-10s |\n", "ID", "Name", "Email", "Phone", "Industry");
    for (int i = 0; i < count; i++) {
    	printf("----------------------------------------------------------------------------------------------\n");
        printf("| %-5d | %-20s | %-28s | %-15s | %-10s |\n", students[i].id, students[i].name, students[i].email, students[i].phone, students[i].industry);
    }
        printf("==============================================================================================\n");

}
// tim kiem sinh vien theo ten co chuc nang tim kiem gan dung
void searchStudent(Student students[], int count) {
    char keyword[50];
    printf("Enter the first letter(s) of the student's name: ");
    scanf("%s", keyword);
    
    printf("==============================================================================================\n");
    printf("| %-5s | %-20s | %-28s | %-15s | %-10s |\n", "ID", "Name", "Email", "Phone", "Industry");
    printf("----------------------------------------------------------------------------------------------\n");
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strncmp(students[i].name, keyword, strlen(keyword)) == 0) {
            printf("| %-5d | %-20s | %-28s | %-15s | %-10s |\n", students[i].id, students[i].name, students[i].email, students[i].phone, students[i].industry);
            found = 1;
    		printf("==============================================================================================\n");

        }
    }
    
    if (!found) {
        printf("No students found with the given name keyword.\n");
    }
}
//chinh sua thong tin sinh vien theo id
void editStudent(Student students[], int count) {
    int id;
    printf("Enter ID to edit: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
        	printf("Enter Student Name: ");
            fgets(students[i].name, sizeof(students[i].name), stdin);
    		students[i].name[strcspn(students[i].name, "\n")] = '\0';
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
//xoa sinh vien khoi danh sach theo id
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
//sap xep sinh vien theo ten tu a-z bang sap xep bb sort
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
//lam moi danh sach sinh vien
void resetStudents(Student students[], int *count) {
    *count = 0;
    saveStudents(students, *count);
    printf("Student list has been reset!\n");
}

//quan ly giao vien

void teacherMenu() {
    printf("\n--- Teacher Management ---\n");
    printf("1. Add Teacher\n");
    printf("2. Display Teachers\n");
    printf("3. Search Teacher\n");
    printf("4. Edit Teacher\n");
    printf("5. Delete Teacher\n");
    printf("6. Reset Teachers\n");
    printf("0. Back to Main Menu\n");
    printf("Enter your choice: ");
}

//luu danh sach hoc sinh vao file student.txt 
void saveTeachers(Teacher teachers[], int count) {
    FILE *file = fopen(FILE_TEACHER, "wb"); 
    if (file) {
        fwrite(&count, sizeof(int), 1, file);
        fwrite(teachers, sizeof(Teacher), count, file);
        fclose(file);
    }
}
//doc danh sach hoc sinh trong file student.txt
void loadTeachers(Teacher teachers[], int *count) {
    FILE *file = fopen(FILE_TEACHER, "rb");
    if (file) {
        fread(count, sizeof(int), 1, file);
        fread(teachers, sizeof(Teacher), *count, file);
        fclose(file);
    }
}

//nhap thong tin giao vien
void inputTeacher(Teacher teachers[], int *count) {
    if (*count >= MAX) {
        printf("Teacher list is full!\n");
        return;
    }
    Teacher newTeacher;
    int isDuplicate;
    
    do {
        isDuplicate = 0;
        printf("Enter Teacher ID: ");
        scanf("%d", &newTeacher.id);
        getchar();
        for (int i = 0; i < *count; i++) {
            if (teachers[i].id == newTeacher.id) {
                printf("ID already exists. Please enter a different ID.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    
    printf("Enter Teacher Name: ");
    fgets(newTeacher.name, sizeof(newTeacher.name), stdin);
    newTeacher.name[strcspn(newTeacher.name, "\n")] = '\0';
    
    do {
        isDuplicate = 0;
        printf("Enter Teacher Email: ");
        scanf("%s", newTeacher.email);
        getchar();
        for (int i = 0; i < *count; i++) {
            if (strcmp(teachers[i].email, newTeacher.email) == 0) {
                printf("Email already exists. Please enter a different email.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    
    do {
        isDuplicate = 0;
        printf("Enter Phone: ");
        scanf("%s", newTeacher.phone);
        getchar();
        for (int i = 0; i < *count; i++) {
            if (strcmp(teachers[i].phone, newTeacher.phone) == 0) {
                printf("Phone number already exists. Please enter a different phone number.\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);
    
    teachers[(*count)++] = newTeacher;
    saveTeachers(teachers, *count);
    printf("Teacher added successfully!\n");
}

// hien thi bang liet ke danh sach giao vien
void displayTeachers(Teacher teachers[], int count) {
    if (count == 0) {
        printf("No teachers found!\n");
        return;
    }
    printf("=================================================================================\n");
    printf("| %-5s | %-20s | %-28s | %-15s |\n", "ID", "Name", "Email", "Phone");
    for (int i = 0; i < count; i++) {
        printf("---------------------------------------------------------------------------------\n");
        printf("| %-5d | %-20s | %-28s | %-15s |\n", teachers[i].id, teachers[i].name, teachers[i].email, teachers[i].phone);
    }
    printf("=================================================================================\n");
}

//tim kiem giao vien theo ten gan dung
void searchTeacher(Teacher teachers[], int count) {
    char keyword[50];
    printf("Enter the first letter(s) of the teacher's name: ");
    scanf("%s", keyword);
    
    printf("=================================================================================\n");
    printf("| %-5s | %-20s | %-28s | %-15s |\n", "ID", "Name", "Email", "Phone");
    printf("---------------------------------------------------------------------------------\n");
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strncmp(teachers[i].name, keyword, strlen(keyword)) == 0) {
            printf("| %-5d | %-20s | %-28s | %-15s |\n", teachers[i].id, teachers[i].name, teachers[i].email, teachers[i].phone);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No teachers found with the given name keyword.\n");
    }
}
//chinh sua thong tin giao vien theo id
void editTeacher(Teacher teachers[], int count) {
    int id;
    printf("Enter ID to edit: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < count; i++) {
        if (teachers[i].id == id) {
            printf("Enter New Name: ");
            fgets(teachers[i].name, sizeof(teachers[i].name), stdin);
            teachers[i].name[strcspn(teachers[i].name, "\n")] = '\0';
            printf("Enter New Email: ");
            scanf("%s", teachers[i].email);
            printf("Enter New Phone: ");
            scanf("%s", teachers[i].phone);
            saveTeachers(teachers, count);
            printf("Teacher information updated!\n");
            return;
        }
    }
    printf("Teacher not found!\n");
}
//xoa giao vien khoi danh sach theo id
void deleteTeacher(Teacher teachers[], int *count) {
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (teachers[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                teachers[j] = teachers[j + 1];
            }
            (*count)--;
            saveTeachers(teachers, *count);
            printf("Teacher deleted successfully!\n");
            return;
        }
    }
    printf("Teacher not found!\n");
}
//lam moi danh sach giao vien 
void resetTeachers(Teacher teachers[], int *count) {
    *count = 0;
    saveTeachers(teachers, *count);
    printf("Teacher list has been reset!\n");
}

 
