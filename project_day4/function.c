#include <stdio.h>
#include <string.h>
#include "function.h"

void mainMenu() {
    printf("*** Student Management System ***\n");
    printf("[1] Quan ly sinh vien\n");
    printf("[0] Thoat chuong trinh\n");
    printf("==============================\n");
    printf("Nhap lua chon cua ban: ");
}

void studentMenu() {
    printf("*** Quan Ly Sinh Vien ***\n");
    printf("[1] Them sinh vien moi\n");
    printf("[2] Hien thi danh sach sinh vien\n");
    printf("[3] Chinh sua thong tin sinh vien\n");
    printf("[4] Xoa sinh vien\n");
    printf("[5] Tim kiem sinh vien\n");
    printf("[6] Sap xep sinh vien theo ten\n");
    printf("[0] Tro lai menu chinh\n");
    printf("==============================\n");
    printf("Nhap lua chon cua ban: ");
}

void inputStudent(student arr[], int *count) {
    printf("Nhap ID sinh vien: ");
    scanf("%s", arr[*count].id);
    printf("Nhap ten sinh vien: ");
    scanf(" %[^\n]", arr[*count].name);
    printf("Nhap so dien thoai: ");
    scanf("%s", arr[*count].phone);
    printf("Nhap nganh hoc: ");
    scanf("%s", arr[*count].industry);
    (*count)++;
    printf("Them sinh vien thanh cong!\n");
}

void displayStudent(student arr[], int count) {
    printf("\n%-10s %-30s %-15s %-20s\n", "ID", "Ten", "So DT", "Nganh");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-30s %-15s %-20s\n", arr[i].id, arr[i].name, arr[i].phone, arr[i].industry);
    }
}

void editStudent(student arr[], int count) {
    char id[10];
    printf("Nhap ID sinh vien can chinh sua: ");
    scanf("%s", id);
    for (int i = 0; i < count; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            printf("Chinh sua thong tin sinh vien %s\n", arr[i].name);
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", arr[i].name);
            printf("Nhap so dien thoai moi: ");
            scanf("%s", arr[i].phone);
            printf("Nhap nganh hoc moi: ");
            scanf("%s", arr[i].industry);
            printf("Chinh sua thong tin thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %s!\n", id);
}

void deleteStudent(student arr[], int *count) {
    char id[10];
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%s", id);
    for (int i = 0; i < *count; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            char confirm;
            printf("Ban co chac chan muon xoa sinh vien voi ID %s? (y/n): ", id);
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < *count - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                (*count)--;
                printf("Xoa sinh vien thanh cong!\n");
            } else {
                printf("Huy thao tac xoa sinh vien.\n");
            }
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %s!\n", id);
}

void searchStudent(student arr[], int count) {
    char name[50];
    int found = 0;
    printf("Nhap ten sinh vien can tim: ");
    scanf(" %[^\n]", name);
    printf("\n%-10s %-30s %-15s %-20s\n", "ID", "Ten", "So DT", "Nganh");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        if (strstr(arr[i].name, name) != NULL) {
            printf("%-10s %-30s %-15s %-20s\n", arr[i].id, arr[i].name, arr[i].phone, arr[i].industry);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co sinh vien can tim!\n");
    }
}

void sortStudents(student arr[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep sinh vien theo ten thanh cong!\n");
}
