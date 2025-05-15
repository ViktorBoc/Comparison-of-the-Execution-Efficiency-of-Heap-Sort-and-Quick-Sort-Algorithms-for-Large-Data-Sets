#ifndef BP_SORTINGFUNCTIONS_H
#define BP_SORTINGFUNCTIONS_H
#include "../structDefinition/structDefinition.h"
int compareByLastName(const void *a, const void *b);
int compareByAge(const void *a, const void *b);
int compareByPointsPRP(const void *a, const void *b);
int compareByPointsMS2(const void *a, const void *b);
int compareByPointsST2(const void *a, const void *b);
int compareByAveragePoints(const void *a, const void *b);
void swap(Student *a, Student *b);
int getMedianIndex(Student *array, int low, int high, int (*comp)(const void *, const void *));
int hoarePartition(Student *array, int low, int high, int (*comp)(const void *, const void *));
void quickSort(Student *array, int low, int high, int (*comp)(const void *, const void *));
void heapify(Student array[], int n, int i, int (*comp)(const void*, const void*));
void heapSort(Student array[], int n, int (*comp)(const void*, const void*));

#endif
