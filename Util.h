#ifndef Util_h
#define Util_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void get_file(char * file_name);
void deleteMap(char ** map);
void print_map(void);
extern int num_rows;
extern int num_cols;
extern char ** map;

#endif /* Util_h */
