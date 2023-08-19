#include "Position.h"

position * start_pos = NULL;
position * end_pos = NULL;
int nodeIndex = 0 ;

position * init_pos(int col, int row, int val){
    
    position * n = (position *) malloc(sizeof(position));
    n->val = val;
    n->col = col;
    n->row = row;
    n->last = NULL;
    n->next = NULL;
    n->index = nodeIndex;
    
    nodeIndex++;
    
    return n;
};

position * add_pos(int col, int row, int val){
    
    position * new_pos = init_pos(col, row, val);
    if(end_pos){
        new_pos->last = end_pos;
        end_pos->next = new_pos;
    }
    end_pos = new_pos;
    if(!start_pos){
        start_pos = new_pos;
    }
    return new_pos;
}

position * get_pos(int col, int row){
    position * n = start_pos;
     while(n){
         if(n->row == row && n->col == col){
             return n;
         }
         n = n->next;
     }
     return NULL;
}

void delete_list(void){
    position * current = start_pos;
    position * next = NULL;
    int i = 0;
    
    while(current){
        
        next = current->next;
        free(current);
        current = next;
        i++;
    }
}

void print_list(void){
    position * n = start_pos;
    while(n){
        printf("val: %d\ncol: %d\nrow: %d\n",n->val,n->col,n->row);
        n = n->next;
    }
}
