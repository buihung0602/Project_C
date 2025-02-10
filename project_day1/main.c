#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "funtion.h"
 
void displayMenu();
void displayStudents();
void addStudent();

int main(int argc, char *argv[]) {
	
	int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayStudents();
                break;
            case 2:
                addStudent();
                break;
                case 3:
                printf("Thoat chuong trinh.\n");
                exit(0);
            default:
                printf("Lua chon khong hop le, vui long nhap lai.\n");
        }
        printf("\n");
    }while(choice != 3);
	return 0;
}
