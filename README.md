# Comparison of Execution Efficiency of Heap Sort and Quick Sort Algorithms

This repository contains the implementation from my bachelor's thesis "Comparison of the Execution Efficiency of Heap Sort and Quick Sort Algorithms for Sorting Large Data Files in C". The program compares the performance of Quick Sort and Heap Sort algorithms on structured student data.

## Project Structure

### Main Components

1. **main.c** - The core program that:
    - Loads student data from CSV files
    - Provides user interface for selecting sorting options
    - Measures and compares execution times
    - Manages memory and program flow


2. **loadFunctions** - Handles data input:
    - `selectFile()` - Lets user choose from available data files
    - `selectSortOrder()` - Gets user preference for ascending/descending order
    - `loadCSVData()` - Reads and parses CSV files into Student structures


3. **sortingFunctions** - Implements the algorithms:
    - Comparison functions for different student attributes
    - `quickSort()` with Hoare partition scheme
    - `heapSort()` with max-heap implementation
    - Helper functions like `swap()` and `heapify()`


4. **printingWritingFunctions** - Handles output:
    - Records execution times to output.txt
    - Writes sorted results with formatting
    - Compares and verifies sort results


5. **structDefinition** - Contains the Student structure definition:
   ```c
   typedef struct {
       int id;
       char firstName[50];
       char lastName[50];
       int age;
       int pointsPRP;      // Decision support systems
       int pointsMS2;      // Management science 2
       int pointsST2;      // Network technologies 2
       int averagePoints;  // Average of the three courses
   } Student;

6. **data** - Contains test datasets:
   - data_10.csv (sample data)
   - data_100,000.csv
   - data_150,000.csv
   - data_200,000.csv
   - data_250,000.csv
   - data_300,000.csv
   - data_350,000.csv
   - data_400,000.csv


7. **output** - Stores generated output files:

   - output.txt (contains sorting results and timings)