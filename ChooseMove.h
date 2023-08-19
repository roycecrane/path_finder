#ifndef ChooseMove_h
#define ChooseMove_h
#include "Position.h"
#include "Util.h"
#include <stdio.h>

extern int * start_coords;
extern int * end_coords;

typedef struct Move{
    int col;
    int row;
    int val;
} mov;

void set_params(int * start, int * end);
mov * choose_move(position* pos);
void check_move(position* pos, mov * possible_move);
mov * compare_moves(position* pos, mov* move_a, mov* move_b);
position * make_move(position * pos);

#endif /* ChooseMove_h */
