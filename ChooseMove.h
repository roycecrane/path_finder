#ifndef ChooseMove_h
#define ChooseMove_h
#include "Position.h"
#include "Util.h"
#include <stdio.h>

extern int * start_coords;
extern int * end_coords;

void set_params(int * start, int * end);
int * choose_move(position* pos);
int check_move(position* pos, int move[]);
int * compare_moves(position* , int *, int *);
position * make_move(position * pos);
#endif /* ChooseMove_h */
