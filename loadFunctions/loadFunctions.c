#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "loadFunctions.h"
const char *selectFile(void) {
    const char *fileOptions[] = {
            "data/data_10.csv",
            "data/data_100,000.csv",
            "data/data_150,000.csv",
            "data/data_200,000.csv",
            "data/data_250,000.csv",
            "data/data_300,000.csv",
            "data/data_350,000.csv",
            "data/data_400,000.csv"
    };
    int fileChoice = 0;
    char input[3];

    do {
        printf("Select the data file to load:\n");
        for (int i = 0; i < 8; i++) {
            printf("%d - Load from %s\n", i + 1, fileOptions[i]);
        }
        printf("Enter a number (1-8):\n");

        if (!fgets(input, sizeof(input), stdin)) {
            fprintf(stderr, "Error reading input. Please try again.\n\n");
            continue;
        }

        if (input[1] != '\n' && input[1] != '\0') {
            while ((getchar()) != '\n' && !feof(stdin) && !ferror(stdin));
            printf("Invalid input. Please enter a number between 1 and 8.\n\n");
            continue;
        }

        fileChoice = input[0] - '0';
        if (fileChoice < 1 || fileChoice > 8) {
            printf("Invalid input. Please enter a number between 1 and 8.\n\n");
            continue;
        }
    } while (fileChoice < 1 || fileChoice > 8);

    return fileOptions[fileChoice - 1];
}

int selectSortOrder(void) {
    char input[3];
    int sortOrder = 0;
    do {
        printf("Select sort order:\n1 - Ascending\n2 - Descending\nEnter choice (1 or 2):\n");
        if (!fgets(input, sizeof(input), stdin)) {
            fprintf(stderr, "Error reading input. Please try again.\n\n");
            continue;
        }
        if (input[1] != '\n' && input[1] != '\0') {
            while (getchar() != '\n'); // Discard characters until the end of the line
            printf("Invalid input. Please enter a number between 1 and 2.\n\n");
            continue;
        }
        sortOrder = input[0] - '0';
        if (sortOrder < 1 || sortOrder > 2) {
            printf("Invalid input. Please enter a number between 1 and 2.\n\n");
        }
    } while (sortOrder < 1 || sortOrder > 2);
    return sortOrder;
}

Student *loadCSVData(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int capacity = 10;
    int size = 0;
    Student *students = (Student *) malloc(capacity * sizeof(Student));
    if (!students) {
        perror("Failed to allocate memory.\n");
        fclose(file);
        return NULL;
    }

    while (fgets(line, sizeof(line), file)) {
        if (size == capacity) {
            capacity *= 2;
            Student *temp = (Student *) realloc(students, capacity * sizeof(Student));
            if (!temp) {
                free(students);
                perror("Failed to reallocate memory.\n");
                fclose(file);
                return NULL;
            }
            students = temp;
        }

        sscanf_s(line, "%d,%29[^,],%29[^,],%d,%d,%d,%d,%d",
                 &students[size].id,
                 students[size].firstName, (unsigned)_countof(students[size].firstName),
                 students[size].lastName, (unsigned)_countof(students[size].lastName),
                 &students[size].age,
                 &students[size].pointsPRP,
                 &students[size].pointsMS2,
                 &students[size].pointsST2,
                 &students[size].averagePoints);

        if (strlen(students[size].firstName) > MAX_NAME_LENGTH ||
            strlen(students[size].lastName) > MAX_NAME_LENGTH) {
            fprintf(stderr, "Error: Name too long in file %s.\n", filename);
            free(students);
            exit(1);
        }
        size++;
    }

    fclose(file);

    if (size == 0) {
        fprintf(stderr, "Error: File %s is empty.\n", filename);
        free(students);
        exit(1);
    }

    Student *temp = (Student *) realloc(students, size * sizeof(Student));
    if (!temp) {
        free(students);
        perror("Failed to reallocate memory.\n");
        return NULL;
    }
    students = temp;
    *count = size;
    return students;
}
