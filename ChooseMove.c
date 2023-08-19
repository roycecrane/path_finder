#include "ChooseMove.h"
int * start_coords = NULL;
int * end_coords = NULL;

void set_params(int * start, int * end){
    start_coords = start;
    end_coords = end;
}

int * compare_moves(position* pos,int* move_a, int* move_b){
    int * best_move = malloc(2);
    
    if(!move_a && move_b){
        best_move[0] = move_b[0];
        best_move[1] = move_b[1];
        return best_move;
    }
    if(!move_b && move_a){
        best_move[0] = move_a[0];
        best_move[1] = move_a[1];
        return best_move;
    }
    if(!move_b && !move_a) return NULL;
    
    //    move a is preffered when val equal

    best_move[0] = 0; best_move[1] = 0;
    
    int move_a_val = check_move(pos, move_a);
    int move_b_val = check_move(pos, move_b);

    if(move_a_val == 1){
        best_move[0] = move_a[0];
        best_move[1] = move_a[1];
        return  best_move;
    }
    if (move_b_val == 1){
        best_move[0] = move_b[0];
        best_move[1] = move_b[1];
        return  best_move;
    }
//  neither a or b had val 1 so find which is lowest
    if(move_a_val && move_b_val){
        if(move_a_val <= move_b_val){
            best_move[0] = move_a[0];
            best_move[1] = move_a[1];
            return  best_move;
        } else {
            best_move[0] = move_b[0];
            best_move[1] = move_b[1];
            return  best_move;
        }
//    either a or b is 0 so return the one that is not
    }
    if(move_a_val){
        best_move[0] = move_a[0];
        best_move[1] = move_a[1];
        return  best_move;
    }
    if(move_b_val){
        best_move[0] = move_b[0];
        best_move[1] = move_b[1];
        return  best_move;
    }
//  neither move possible return NULL
    return NULL;
}

int * choose_move(position* pos){
    
    int end_col_dist = end_coords[0] - pos->col;
    int end_row_dist = end_coords[1] - pos->row;
    int best_col_dir = (end_col_dist > 0) - (end_col_dist < 0);
    int best_row_dir = (end_row_dist > 0) - (end_row_dist < 0);
    int best_col_move[2] = {best_col_dir, 0};
    int best_row_move[2] = {0, best_row_dir};
    int bad_col_move[2] = {-best_col_dir, 0};
    int bad_row_move[2] = {0, -best_row_dir};
    
    int * best_of_best = compare_moves(pos, best_col_move, best_row_move);
    if(best_of_best)
        printf("best of best:  %d, %d\n",best_of_best[0],best_of_best[1]);
    
    int * best_of_worst = compare_moves(pos, bad_col_move, bad_row_move);
    if(best_of_worst)
        printf("best of worst:  %d, %d\n",best_of_worst[0],best_of_worst[1]);
  
    int * best_move = compare_moves(pos, best_of_best, best_of_worst);
    if(best_move)
        printf("best move:  %d, %d\n",best_move[0],best_move[1]);
   
 
    if(best_move){
        return best_move;
    }
//    no moves possible
    return NULL;
}
int check_move(position* pos, int move[]){
    int possible_move [] = { pos->col + move[0], pos->row + move[1]};
    char move_terrain = map[possible_move[0]][possible_move[1]];
    int move_cost = 0;
        switch(move_terrain) {
            case '_'  :
                move_cost = 1;
        break;
            case 'f' :
                move_cost = 4;
        break;
            case 'M' :
                move_cost = 10;
    }
//    if positon has been visited before return 0
    if (get_pos(possible_move[0], possible_move[1]))
        move_cost = 0;
    
    return move_cost;
}

position * make_move(position * pos){
    int * move = choose_move(pos);
    if(move){
        int new_row = pos->col + move[0];
        int new_col = pos->row + move[1];
        int new_val = check_move(pos, move);
        
        position * new_pos  = append(new_col, new_row, new_val);
        pos = new_pos;
        if(new_col == end_coords[0] && new_row == end_coords[1])
            return pos;
        make_move(pos);
    }

    return pos;
}
