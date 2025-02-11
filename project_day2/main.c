#include <stdio.h>
#include "function.h"

int main() {
    student arr[MAX];
    int count = 0;
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputStudent(arr, &count);
                break;
            case 2:
                displayStudent(arr, count);
                break;
            case 3:
                editStudent(arr, count);
                break;
            case 4:
                deleteStudent(arr, &count);
                break;
            case 5:
                searchStudent(arr, count);
                break;
            case 6:
                sortStudents(arr, count);
                break;
            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
} 

