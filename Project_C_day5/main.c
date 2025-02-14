#include <stdio.h>
#include "datatype.h"
#include "function.h"

#define MAX 100

int main() {
    Student students[MAX];
    int count = 0, choice;
    loadStudents(students, &count);
    do {
        mainMenu();
        scanf("%d", &choice);
        if (choice == 1) {
            int subChoice;
            do {
                studentMenu();
                scanf("%d", &subChoice);
                switch (subChoice) {
                    case 1: inputStudent(students, &count); break;
                    case 2: displayStudents(students, count); break;
                    case 3: searchStudent(students, count); break;
                    case 4: editStudent(students, count); break;
                    case 5: deleteStudent(students, &count); break;
                    case 6: sortStudents(students, count); break;
                    case 7: resetStudents(students, &count); break;
                    case 0: break;
                    default: printf("Invalid choice! Please try again.\n");
                }
            } while (subChoice != 0);
        } else if (choice == 0) {
            printf("Exiting Program...\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}

