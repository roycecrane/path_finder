#ifndef MakeMove_h
#define MakeMove_h
#include <stdio.h>
#include "ChooseMove.h"
#include "Lists.h"

void set_params(int * start, int * end);
pos_node * make_move(pos_node * pos);
mov * test_options(pos_node* pos, mov* move_a,mov* move_b);
mov * find_best_direction(pos_node* pos,  mov * move_a, mov * move_b);

#endif /* MakeMove_h */
