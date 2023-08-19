#include "ChooseMove.h"
int * start_coords = NULL;
int * end_coords = NULL;


void set_params(int * start, int * end){
    start_coords = start;
    end_coords = end;
}

mov * create_move(mov* move_a){
    if(!move_a)
        return NULL;
    mov * new_move = malloc(sizeof(mov));
    new_move->col = move_a->col;
    new_move->row = move_a->row;
    new_move->val = move_a->val;
    return new_move;
}

mov * compare_moves(position* pos, mov* move_a, mov* move_b){
    
    if(move_a){
        check_move(pos, move_a);
        if (move_a->val == 0) move_a = NULL;
    }
       
    if(move_b){
        check_move(pos, move_b);
        if (move_b->val == 0) move_b = NULL;
    }
    
    if(!move_b && !move_a)
        return NULL;
    
    if(move_a && !move_b)
        return create_move(move_a);
    
    if(!move_a && move_b)
        return create_move(move_b);
    
    
    if(move_a->val == 1)
        return create_move(move_a);
    
    
    if (move_b->val == 1)
        return create_move(move_b);
    
    
    if(move_a->val <= move_b->val)
        return create_move(move_a);
    else
        return create_move(move_b);
    
    return NULL;
}

mov * cheapest_possible_move(position* pos){
    mov u = {-1, 0 ,0}; mov d = {1, 0, 0}; mov l = {0,-1, 0}; mov r = {0 ,1, 0};
    mov * best_ud = compare_moves(pos, &u, &d);
    mov * best_lr = compare_moves(pos, &l, &r);
    mov * best = compare_moves(pos, best_ud, best_lr);
    if(best){
        if(best->val)
            return best;
    }
    return NULL;
}


mov * choose_move(position* pos){
    
    int end_col_dist = end_coords[0] - pos->col;
    int end_row_dist = end_coords[1] - pos->row;
    
    int best_col_dir = (end_col_dist > 0) - (end_col_dist < 0);
    int best_row_dir = (end_row_dist > 0) - (end_row_dist < 0);
    
    mov best_col_move = {best_col_dir, 0, 0};
    mov best_row_move = {0, best_row_dir, 0};
    mov bad_col_move = {-best_col_dir, 0, 0};
    mov bad_row_move = {0, -best_row_dir, 0};
    
    mov * best_of_worst = NULL;
    mov * best_of_best = NULL;
    
    if(!best_col_dir || !best_row_dir){
        if(best_col_dir){
            best_of_best = compare_moves(pos, &best_col_move, NULL);
            best_of_worst = compare_moves(pos, &bad_col_move, NULL);
        }
        if(best_row_dir){
            best_of_best = compare_moves(pos, NULL, &best_row_move);
            best_of_worst = compare_moves(pos, NULL, &bad_row_move);
        }
    } else {
        best_of_best = compare_moves(pos, &best_col_move, &best_row_move);
        best_of_worst = compare_moves(pos, &bad_col_move, &bad_row_move);
    }
    
    mov * best_move = compare_moves(pos, best_of_best, best_of_worst);
    if(best_move){
        if (best_move->val)
            return best_move;
    } else {
        return cheapest_possible_move(pos);
    }
    return NULL;
}

void check_move(position* pos, mov * possible_move ){
    int possible_pos [] = { pos->col + possible_move->col, pos->row + possible_move->row };
    
    char move_terrain = map[possible_pos[0]][possible_pos[1]];
    
        switch(move_terrain) {
            case '_' : possible_move->val = 1;
        break;
            case 'f' : possible_move->val = 4;
        break;
            case 'M' : possible_move->val = 10;
        break;
    }
    
    if (get_pos(possible_pos[0], possible_pos[1]))
        possible_move->val = 0;
}

position * make_move(position * pos){
    mov * chosen_move = choose_move(pos);
    if(chosen_move){
        int new_col = pos->col + chosen_move->col;
        int new_row = pos->row + chosen_move->row;
        int new_val = pos->val + chosen_move->val;
        
        position * new_pos  = add_pos(new_col, new_row, new_val);
        pos = new_pos;
        
        if(new_col == end_coords[0] && new_row == end_coords[1])
            return pos;
        make_move(pos);

    } else {
//        no move was possible backtrack
//        TODO fix value problem here
//        this uses old node from list instead of making a copy idk which would be better
        position * new_pos = pos->last;
        make_move(new_pos);
    }
    return pos;
}

