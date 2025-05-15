#include "printingWritingFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stddef.h>

void writeArraySizeToFile(int size) {
    FILE *file = fopen("output/output.txt", "a");
    if (!file) {
        perror("Failed to open output file.\n");
        return;
    }
    fprintf(file, "The number of elements being sorted is %d.\n\n", size);
    fclose(file);
}
void writeTimeToFile(const char *sortMethod, const char *attributeName, double cpuTimeUsed) {
    FILE *f = fopen("output/output.txt", "a");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    fprintf(f, "[%s] Sorted by %s - %s execution time: %lf milliseconds.\n", buffer, attributeName, sortMethod, cpuTimeUsed * 1000);
    fclose(f);
}

void writeArray(Student *students, int count, FILE *f, int sortOrder) {
    fprintf(f, "\nPRP is shortcut for the points achieved in a university class called Decision support systems.\n");
    fprintf(f, "MS2 is shortcut for the points achieved in a university class called Management science 2.\n");
    fprintf(f, "ST2 is shortcut for the points achieved in a university class called Network technologies 2.\n");
    fprintf(f, "Average is shortcut for the average points achieved in the three mentioned classes.\n\n");
    fprintf(f, "%-6s %-30s %-30s %-3s %-4s %-4s %-4s %-4s\n", "Id", "First Name", "Last Name", "Age", "PRP", "MS2", "ST2", "Average");

    if (sortOrder == 2) {
        for (int i = count - 1; i >= 0; i--) {
            fprintf(f, "%-6d %-30s %-30s %-3d %-4d %-4d %-4d %-4d\n",
                    students[i].id,
                    students[i].firstName,
                    students[i].lastName,
                    students[i].age,
                    students[i].pointsPRP,
                    students[i].pointsMS2,
                    students[i].pointsST2,
                    students[i].averagePoints);
        }
    } else {
        for (int i = 0; i < count; i++) {
            fprintf(f, "%-6d %-30s %-30s %-3d %-4d %-4d %-4d %-4d\n",
                    students[i].id,
                    students[i].firstName,
                    students[i].lastName,
                    students[i].age,
                    students[i].pointsPRP,
                    students[i].pointsMS2,
                    students[i].pointsST2,
                    students[i].averagePoints);
        }
    }
    fprintf(f,"\n\n");
}

void writeStudentsToFile(Student *quickSorted, Student *heapSorted, int count, int sortOrder) {
    int identical = 1;
    for (int i = 0; i < count; i++) {
        if (quickSorted[i].id != heapSorted[i].id ||
            strcmp(quickSorted[i].firstName, heapSorted[i].firstName) != 0 ||
            strcmp(quickSorted[i].lastName, heapSorted[i].lastName) != 0 ||
            quickSorted[i].age != heapSorted[i].age ||
            quickSorted[i].pointsPRP != heapSorted[i].pointsPRP ||
            quickSorted[i].pointsMS2 != heapSorted[i].pointsMS2 ||
            quickSorted[i].pointsST2 != heapSorted[i].pointsST2 ||
            quickSorted[i].averagePoints != heapSorted[i].averagePoints) {
            identical = 0;
            break;
        }
    }

    FILE *f = fopen("output/output.txt", "a");
    if (f == NULL) {
        perror("Error opening file");
        exit(1);
    }
    if (identical) {
        fprintf(f, "\nThe arrays sorted by quickSort and heapSort functions with implemented Quick Sort and Heap Sort algorithms\nwere compared by the writeStudentsToFile function.\nThe arrays are identical, only one of them is written into the output file.\n");
        writeArray(quickSorted, count, f, sortOrder);
    } else {
        fprintf(f, "\nThe arrays sorted by quickSort and heapSort functions with implemented Quick Sort and Heap Sort algorithms\nwere compared by the writeStudentsToFile function.\nThe arrays are not identical, both of them are written into the output file.\n");
        fprintf(f, "\nArray sorted by quickSort:\n");
        writeArray(quickSorted, count, f, sortOrder);
        fprintf(f, "\nArray sorted by heapSort:\n");
        writeArray(heapSorted, count, f, sortOrder);
    }
    fprintf(f, "----------------------------------------------------------------------------------------------------\n\n");
    fclose(f);
}
