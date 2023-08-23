#ifndef ChooseMove_h
#define ChooseMove_h
#include "Util.h"
#include <stdio.h>
#include "Lists.h"
typedef struct Move{
    int col;
    int row;
    int val;
} mov;

extern int * start_coords;
extern int * end_coords;

mov * check_move(pos_node* pos, mov possible_move);
mov * create_move(mov move_a);
mov *  get_best_move(pos_node * pos);
float check_dist(pos_node * pos, mov move);


#endif /* ChooseMove_h */
