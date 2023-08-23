#include "Lists.h"
pos_node ** test_lists;
int numebr_of_test_lists = 0;

pos_node * new_list(int col, int row, int val,int branch_depth){
    
    pos_node * new_pos = init_node(col, row, val, branch_depth);
    return new_pos;
}

pos_node * add_node(pos_node * pos, int col, int row, int val, int branch_depth){
    
    pos_node * new_pos = init_node(col, row, val,branch_depth);
    pos_node * last_node = get_last_node(pos);
    if(last_node){
        new_pos->index = last_node->index + 1;
        last_node->next = new_pos;
        new_pos->last = last_node;
        return new_pos;
    } else {
        new_pos->index = 0;
    }
    printf("could not add new node to list");
    return NULL;
}

pos_node * init_node(int col, int row, int val, int branch_depth){
    pos_node * n = (pos_node *) malloc(sizeof(pos_node));
    n->branch_depth = branch_depth;
    n->val = val;
    n->col = col;
    n->row = row;
    n->back_track = 0;
    n->last = NULL;
    n->next = NULL;
    n->index = 0;
    return n;
};

pos_node * get_last_node(pos_node * pos){
    pos_node * current_node  = pos;
    while(current_node){
        if(!current_node->next){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

pos_node * get_first_node(pos_node * pos){
    if(pos){
        pos_node * current_node = pos;
        while(current_node){
            if(current_node->last == NULL){
                return current_node;
            }
            current_node = current_node->last;
        }
    }

    return NULL;
}


pos_node * get_list_node(pos_node *pos, int col, int row){
    pos_node * current_node =  get_first_node(pos);
    while(current_node){
        if (current_node->col == col && current_node ->row == row){
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

void print_list(pos_node * pos){
    pos_node * current_node = get_first_node(pos);
    while(current_node){
        printf("col: %d, row: %d\n",current_node->col, current_node->row);
        current_node = current_node -> next;
    }
}

void delete_node(pos_node * pos){
    if(pos->last){
        pos->last->next = NULL;
        if(pos->next){
            pos->last->next = pos->next;
            pos->next->last = pos->last;
        }
    }
    
    free(pos);
}
void delete_list(pos_node * pos){
    pos_node * current_node = get_first_node(pos);
    while(current_node){
        pos_node * last_node = current_node;
        current_node = current_node->next;
        free(last_node);
    }
}

//void delete_lists(void){
//    for(int i = 0; i < numebr_of_test_lists; i++){
//        pos_node * current_node = test_lists[i];
//        while(current_node){
//            pos_node * last_node = current_node;
//            current_node = current_node->next;
//            free(last_node);
//        }
//    }
//}
