#ifndef Position_h
#define Position_h
#include <stdio.h>
#include <stdlib.h>

typedef struct Positon {
    int val;
    int index;
    int row;
    int col;
    struct Positon * last;
    struct Positon * next;
} position;

extern position * start_pos;
extern position * end_pos;
extern int nodeIndex;


position * add_pos(int col, int row, int val);
position * init_pos(int col, int row, int val);
position * get_pos(int col, int row);

void print_list(void);
void delete_list(void);





#endif /* Position_h */
