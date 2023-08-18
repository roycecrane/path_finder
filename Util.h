#ifndef Util_h
#define Util_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void get_file(char * file_name);
void deleteMap(char ** map);
extern int num_rows;
extern int num_cols;
extern char ** map;
#endif /* Util_h */
