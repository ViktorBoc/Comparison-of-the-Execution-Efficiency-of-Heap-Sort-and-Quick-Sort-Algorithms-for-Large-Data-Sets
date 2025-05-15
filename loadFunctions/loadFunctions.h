#ifndef BP_LOADFUNCTIONS_H
#define BP_LOADFUNCTIONS_H
#include "../structDefinition/structDefinition.h"
Student *loadCSVData(const char *filename, int *count);
const char *selectFile(void);
int selectSortOrder(void);
#endif
