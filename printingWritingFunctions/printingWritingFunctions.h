#ifndef BP_PRINTINGWRITINGFUNCTIONS_H
#define BP_PRINTINGWRITINGFUNCTIONS_H
#include <stdio.h>
#include "../structDefinition/structDefinition.h"
void writeArraySizeToFile(int size);
void writeTimeToFile(const char *sortMethod, const char *attributeName, double cpuTimeUsed);
void writeArray(Student *students, int count, FILE *f, int sortOrder);
void writeStudentsToFile(Student *quickSorted, Student *heapSorted, int count, int sortOrder);
#endif
