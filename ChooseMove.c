#include "ChooseMove.h"
#include <math.h>
int * start_coords = NULL;
int * end_coords = NULL;

mov * create_move(mov move_a){
    mov * new_move = malloc(sizeof(mov));
    new_move->col = move_a.col;
    new_move->row = move_a.row;
    new_move->val = move_a.val;
    return new_move;
}
float check_dist(pos_node * pos, mov  move){
    int dist_vec[2] ={0,0};
    int new_pos[] = { pos->col + move.col , pos->row + move.row };
    
    dist_vec[0] = end_coords[0] - new_pos[0];
    dist_vec[1] = end_coords[1] - new_pos[1];
    
    float dist = sqrt((float)(dist_vec[0] * dist_vec[0]) + (float)(dist_vec[1] * dist_vec[1]));
    return dist;
}

mov* check_move(pos_node* pos, mov possible_move){
    
    int possible_pos [] = { pos->col + possible_move.col, pos->row + possible_move.row };
    
    char move_terrain = map[possible_pos[0]][possible_pos[1]];
        switch(move_terrain) {
            case '_' : possible_move.val = 1;
        break;
            case 'f' : possible_move.val = 4;
        break;
            case 'M' : possible_move.val = 10;
        break;
    }
    if (get_list_node(pos, possible_pos[0], possible_pos[1]))
        possible_move.val = 0;
    
    if(!possible_move.val){
        return NULL;
    }
    return create_move(possible_move);
}
