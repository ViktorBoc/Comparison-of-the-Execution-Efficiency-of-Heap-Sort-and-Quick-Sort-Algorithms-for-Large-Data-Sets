#include "sortingFunctions.h"
#include <string.h>

int compareByLastName(const void *a, const void *b) {
    const Student *studentA = (const Student *)a;
    const Student *studentB = (const Student *)b;
    return strcmp(studentA->lastName, studentB->lastName);
}
int compareByAge(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;
    return (studentA->age > studentB->age) - (studentA->age < studentB->age);

}
int compareByPointsPRP(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;
    return (studentA->pointsPRP > studentB->pointsPRP) - (studentA->pointsPRP < studentB->pointsPRP);
}
int compareByPointsMS2(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;
    return (studentA->pointsMS2 > studentB->pointsMS2) - (studentA->pointsMS2 < studentB->pointsMS2);
}
int compareByPointsST2(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;
    return (studentA->pointsST2 > studentB->pointsST2) - (studentA->pointsST2 < studentB->pointsST2);
}
int compareByAveragePoints(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;
    return (studentA->averagePoints > studentB->averagePoints) - (studentA->averagePoints < studentB->averagePoints);
}

void swap(Student *a, Student *b) {
    Student temp = *a;
    *a = *b;
    *b = temp;
}

int getMedianIndex(Student *array, int low, int high, int (*comp)(const void *, const void *)) {
    int mid = low + (high - low) / 2;
    if (comp(&array[low], &array[high]) > 0) {
        if (comp(&array[mid], &array[high]) > 0)
            return high;
        return comp(&array[mid], &array[low]) > 0 ? mid : low;
    } else {
        if (comp(&array[mid], &array[low]) > 0)
            return low;
        return comp(&array[mid], &array[high]) > 0 ? mid : high;
    }
}

//https://www.geeksforgeeks.org/hoares-vs-lomuto-partition-scheme-quicksort/
int hoarePartition(Student *array, int low, int high, int (*comp)(const void *, const void *)) {
    int medianIndex = getMedianIndex(array, low, high, comp);
    swap(&array[medianIndex], &array[low]);

    Student pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
        } while (comp(&array[i], &pivot) < 0);

        do {
            j--;
        } while (comp(&array[j], &pivot) > 0);

        if (i >= j)
            return j;

        swap(&array[i], &array[j]);
    }
}

void quickSort(Student *array, int low, int high, int (*comp)(const void *, const void *)) {
    if (low < high) {
        int p = hoarePartition(array, low, high, comp);
        quickSort(array, low, p, comp);
        quickSort(array, p + 1, high, comp);
    }
}
//https://www.geeksforgeeks.org/heap-sort/
void heapify(Student array[], int n, int i, int (*comp)(const void*, const void*)) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && comp(&array[l], &array[largest]) > 0)
        largest = l;

    if (r < n && comp(&array[r], &array[largest]) > 0)
        largest = r;

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest, comp);
    }
}

void heapSort(Student array[], int n, int (*comp)(const void*, const void*)) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i, comp);

    for (int i=n-1; i>0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0, comp);
    }
}
