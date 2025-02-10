#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_STUDENTS 100
#include "datatype.h"
#include "funtion.h"

Student students[MAX_STUDENTS];  
int studentCount = 0;           


void displayMenu() {
    printf("===============================\n");
    printf("%7sQUAN LY SINH VIEN\n","");
    printf("===============================\n");
    printf("1. Hien thi danh sach sinh vien\n");
    printf("2. Them sinh vien\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Sap xep danh sach sinh vien\n");
    printf("6. Thoat\n");
    printf("Nhap lua chon: ");
}
void displayStudents() {
    if (studentCount == 0) {
        printf("Chua co sinh vien nao trong danh sach.\n");
        return;
    }
    printf("\nDanh sach sinh vien:\n");
    printf("+-------------------------------------------+\n");
    printf("|%-5s|%-20s|%-5s|%-10s|\n", "ID", "Ten", "Tuoi", "Nganh hoc");
    for(int i = 0; i < studentCount; i++) {
    	printf("---------------------------------------------\n");
        printf("|%-5d|%-20s|%-5d|%-10s|\n", students[i].id, students[i].name, students[i].age, students[i].major);
    }
    printf("+-------------------------------------------+\n");
}
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Khong the them sinh vien, danh sach da day.\n");
        return;
    }

    Student newStudent;
    printf("Nhap ID: ");
    scanf("%d", &newStudent.id);
    printf("Nhap ten: ");
    getchar(); 
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // X?a k? t? xu?ng d?ng
    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);
    printf("Nhap nganh hoc: ");
    getchar();
    fgets(newStudent.major, sizeof(newStudent.major), stdin);
    newStudent.major[strcspn(newStudent.major, "\n")] = 0;

    students[studentCount++] = newStudent;
    printf("Them sinh vien thanh cong!\n");
}
