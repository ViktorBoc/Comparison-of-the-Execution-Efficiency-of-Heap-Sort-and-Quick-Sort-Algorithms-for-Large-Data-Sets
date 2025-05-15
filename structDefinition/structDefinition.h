#ifndef BP_STRUCTDEFINITION_H
#define BP_STRUCTDEFINITION_H
#define MAX_LINE_LENGTH 90
#define MAX_NAME_LENGTH 30


typedef struct {
    int id;
    char firstName[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int age;
    int pointsPRP;
    int pointsMS2;
    int pointsST2;
    int averagePoints;
} Student;

#endif
