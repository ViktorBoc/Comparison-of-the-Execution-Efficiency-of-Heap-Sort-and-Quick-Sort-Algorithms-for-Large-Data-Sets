#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stddef.h>
#include "../loadFunctions/loadFunctions.h"
#include "../sortingFunctions/sortingFunctions.h"
#include "../printingWritingFunctions/printingWritingFunctions.h"
//#include "../structDefinition/structDefinition.h"

int main(void) {
    printf("\nThe program sorts arrays of structured variables using Quick Sort and Heap Sort.\nEach structured variable contains the data about one student.\nThe execution time of each sort is written in the console.\nA more detailed report regarding the individual sorts is recorded in the output.txt file.\n\n");
    int count = 0;
    const char *filename = selectFile();
    Student *students = loadCSVData(filename, &count);
    if (!students) {
        fprintf(stderr, "Failed to load the student data.\n");
        return 1;
    }
    writeArraySizeToFile(count);
    printf("\nThe number of elements being sorted is %d.\n\n", count);
    int sortOrder = selectSortOrder();
    int choice;
    char input[3];
    do {
        printf("\n1 - sort by Last name\n2 - sort by Age\n3 - sort by points achieved in Decision support systems\n4 - sort by points achieved in Management science 2\n5 - sort by points achieved in Network technologies 2\n6 - sort by the average points achieved from the three mentioned classes\n\n");
        printf("Enter a number (0 to exit, 1-6 for sorting options):\n");

        if (!fgets(input, sizeof(input), stdin)) {
            fprintf(stderr, "Error reading input. Please try again.\n\n");
            continue;
        }

        if (input[1] != '\n' && input[1] != '\0') {
            while ((getchar()) != '\n' && !feof(stdin) && !ferror(stdin));
            printf("Invalid input. Please enter a number between 0 and 6.\n\n");
            continue;
        }

        if (input[0] < '0' || input[0] > '6') {
            printf("Invalid input. Please enter a number between 0 and 6.\n\n");
            continue;
        }

        choice = input[0] - '0';
        clock_t start, end;
        double cpuTimeUsed;
        const char *attributeName = NULL;
        Student *quickSortedStudents = malloc(count * sizeof(Student));
        Student *heapSortedStudents = malloc(count * sizeof(Student));
        if (!quickSortedStudents || !heapSortedStudents) {
            fprintf(stderr, "Memory allocation failed.\n");
            free(students);
            free(quickSortedStudents);
            free(heapSortedStudents);
            return 1;
        }
        memcpy(quickSortedStudents, students, sizeof(Student) * count);
        memcpy(heapSortedStudents, students, sizeof(Student) * count);

        switch (choice) {
            case 0:
                printf("Exiting program.\n");
                break;
            case 1:
                attributeName = "Last name";
                //quick sort
                start = clock();
                quickSort(quickSortedStudents, 0, count - 1, compareByLastName);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Quick Sort execution time: %lf milliseconds.\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Quick Sort", attributeName, cpuTimeUsed);

                //heap sort
                start = clock();
                heapSort(heapSortedStudents, count, compareByLastName);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Heap sort execution time: %lf milliseconds.\n\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Heap Sort", attributeName, cpuTimeUsed);
                writeStudentsToFile(quickSortedStudents, heapSortedStudents, count, sortOrder);
                break;
            case 2:
                //quick sort
                attributeName = "Age";
                start = clock();
                quickSort(quickSortedStudents, 0, count - 1, compareByAge);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Quick Sort execution time: %lf milliseconds.\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Quick Sort", attributeName, cpuTimeUsed);

                //heap sort
                start = clock();
                heapSort(heapSortedStudents, count, compareByAge);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s -Heap Sort execution time: %lf milliseconds.\n\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Heap Sort", attributeName, cpuTimeUsed);
                writeStudentsToFile(quickSortedStudents, heapSortedStudents, count, sortOrder);
                break;
            case 3:
                //quick sort
                attributeName = "Points in Decision support systems";
                start = clock();
                quickSort(quickSortedStudents, 0, count - 1, compareByPointsPRP);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Quick Sort execution time: %lf milliseconds.\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Quick Sort", attributeName, cpuTimeUsed);

                //heap sort
                start = clock();
                heapSort(heapSortedStudents, count, compareByPointsPRP);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Heap Sort execution time: %lf milliseconds.\n\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Heap Sort", attributeName, cpuTimeUsed);
                writeStudentsToFile(quickSortedStudents, heapSortedStudents, count, sortOrder);
                break;
            case 4:
                //quick sort
                attributeName = "Points in Management science 2";
                start = clock();
                quickSort(quickSortedStudents, 0, count - 1, compareByPointsMS2);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Quick Sort execution time: %lf milliseconds.\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Quick Sort", attributeName, cpuTimeUsed);

                //heap sort
                start = clock();
                heapSort(heapSortedStudents, count, compareByPointsMS2);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Heap Sort execution time: %lf milliseconds.\n\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Heap Sort", attributeName, cpuTimeUsed);
                writeStudentsToFile(quickSortedStudents, heapSortedStudents, count, sortOrder);
                break;
            case 5:
                //quick sort
                attributeName = "Points in Network technologies 2";
                start = clock();
                quickSort(quickSortedStudents, 0, count - 1, compareByPointsST2);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Quick Sort execution time: %lf milliseconds.\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Quick Sort", attributeName, cpuTimeUsed);

                //heap sort
                start = clock();
                heapSort(heapSortedStudents, count, compareByPointsST2);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Heap Sort execution time: %lf milliseconds.\n\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Heap Sort", attributeName, cpuTimeUsed);
                writeStudentsToFile(quickSortedStudents, heapSortedStudents, count, sortOrder);
                break;
            case 6:
                //quick sort
                attributeName = "Average points";
                start = clock();
                quickSort(quickSortedStudents, 0, count - 1, compareByAveragePoints);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Quick Sort execution time: %lf milliseconds.\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Quick Sort", attributeName, cpuTimeUsed);

                //heap sort
                start = clock();
                heapSort(heapSortedStudents, count, compareByAveragePoints);
                end = clock();
                cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Sorted by %s - Heap Sort execution time: %lf milliseconds.\n\n", attributeName, cpuTimeUsed * 1000);
                writeTimeToFile("Heap Sort", attributeName, cpuTimeUsed);
                writeStudentsToFile(quickSortedStudents, heapSortedStudents, count, sortOrder);
                break;
        }
        free(quickSortedStudents);
        free(heapSortedStudents);
    } while (choice != 0);
    free(students);
    return 0;
}


