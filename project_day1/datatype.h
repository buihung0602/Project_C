#ifndef DATATYPE_H
#define DATATYPE_H

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    char major[50];
} Student;

extern Student students[MAX_STUDENTS];
extern int studentCount;

#endif
