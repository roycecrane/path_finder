#include "MakeMove.h"

#define MAX_DEPTH 4
#define MAX_VALUE 85
char** explored_map;
void set_params(int * start, int * end){
    start_coords = start;
    end_coords = end;
    explored_map = (char**)malloc(num_cols * sizeof(char*));
    for(int i = 0; i < num_cols; i++ ){
        explored_map[i] = (char*)malloc(num_rows * sizeof(char));
        memcpy(explored_map[i], map[i],  sizeof(char) * num_rows);
    }
}

void add_explored_pos_to_map(int col, int row, int depth){
    char c [3];
    sprintf(c, "%d", depth);
    explored_map[col][row] = c[0];
};

pos_node * make_move(pos_node * pos){
    if( pos->branch_depth > MAX_DEPTH || MAX_VALUE < pos->val){
        return pos;
    }
    
    mov * chosen_move = get_best_move(pos);
    get_best_move(pos);

    if(pos->back_track){
        delete_node(pos->next);
        pos->back_track = 0;
    }
    
    if(chosen_move){
        int new_col = pos->col + chosen_move->col;
        int new_row = pos->row + chosen_move->row;
        int new_val = pos->val + chosen_move->val;
    
        free(chosen_move);
        pos_node * new_pos = add_node(pos, new_col, new_row, new_val, pos->branch_depth);
        pos = new_pos;
        add_explored_pos_to_map(pos->col, pos->row, pos->branch_depth);
        if(new_col == end_coords[0] && new_row == end_coords[1]){
            return pos;
        }
        make_move(pos);
    } else {
        pos_node * new_pos = pos->last;
        new_pos->back_track = 1;
        make_move(new_pos);
    }
    
    return pos;
}

mov * test_options(pos_node* pos, mov* move_a,mov* move_b){
    if(pos->branch_depth > MAX_DEPTH)
        return 0;
    pos_node * test_a = new_list(pos->col + move_a->col,
                                   pos->row + move_a->row,
                                   pos->val + move_a->val,
                                   pos->branch_depth + 1);
    pos_node * test_b = new_list(pos->col + move_b->col,
                                   pos->row + move_b->row,
                                   pos->val + move_b->val,
                                   pos->branch_depth + 1);
    
    pos_node * outcome_a = get_last_node(make_move(test_a));
    pos_node * outcome_b = get_last_node(make_move(test_b));
    
    if(outcome_a && outcome_b){
        if(outcome_a->val && outcome_b->val){
            if(outcome_a->val < outcome_b->val ){
                delete_list(outcome_a);
                delete_list(outcome_b);
                return move_a;
     
            } else{
                delete_list(outcome_a);
                delete_list(outcome_b);
                return move_b;
            }
        }
    }
    if(outcome_a){
        delete_list(outcome_a);
        return move_a;
    }
    if(outcome_b){
        delete_list(outcome_b);
        return move_b;
    }
    return NULL;
}
mov * get_best_move(pos_node * pos){
    mov * moves[4];
    moves[0] =  check_move(pos, (mov) {-1,0,0});
    moves[1] =  check_move(pos, (mov) {1,0,0});
    moves[2] =  check_move(pos, (mov) {0,-1,0});
    moves[3] =  check_move(pos, (mov) {0,1,0});
    
    mov * min_dist_move = NULL;
    float min_dist = 0.f;
    float current_dist = 0.f;
    
    for(int j = 0;  j < 4; j++){
        if(!moves[j])
            continue;
        current_dist = check_dist(pos, *moves[j]);
        if(min_dist == 0.f){
            min_dist_move = moves[j];
            min_dist = current_dist;
        }
        if(current_dist < min_dist ){
            min_dist_move = moves[j];
            min_dist = current_dist;
        }
        if(current_dist == min_dist){
            if(min_dist_move != moves[j]){
                mov * outcome = test_options(pos, moves[j], min_dist_move);
                if(outcome){
                    min_dist_move = outcome;
                }
                
            }
            
        }
        
    }
    for(int i = 0; i < 4; i++){
        if(!moves[i])
            continue;
        if(min_dist_move){
            if(min_dist_move->val >= moves[i]->val && min_dist_move->val > 1){
                mov * outcome = test_options(pos, moves[i], min_dist_move);
                if(outcome){
                    min_dist_move = outcome;
                }
            }
        }
    }

    
    mov * result = NULL;
    if(min_dist_move)
        result = check_move(pos, *min_dist_move);
    
    for(int i = 0; i < 4; i++){
        if(!moves[i])
            continue;
        free(moves[i]);
    }
    return result;
}
