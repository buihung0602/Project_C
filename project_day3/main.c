#include <stdio.h>
#include "function.h"

int main() {
    student arr[MAX];
    int count = 0;
    int choice;
    while (1) {
        mainMenu();
        scanf("%d", &choice);
        if (choice == 0) {
            printf("Thoat chuong trinh. Tam biet!\n");
            break;
        } else if (choice == 1) {
            int subChoice;
            do {
                studentMenu();
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1: inputStudent(arr, &count); break;
                    case 2: displayStudent(arr, count); break;
                    case 3: editStudent(arr, count); break;
                    case 4: deleteStudent(arr, &count); break;
                    case 5: searchStudent(arr, count); break;
                    case 6: sortStudents(arr, count); break;
                    case 0: break;
                    default: printf("Lua chon khong hop le!\n");
                }
            } while (subChoice != 0);
        } else {
            printf("Lua chon khong hop le!\n");
        }
    }
    return 0;
}
