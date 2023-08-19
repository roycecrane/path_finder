#include "Position.h"

position * start_pos = NULL;
position * end_pos = NULL;

int nodeIndex = 0 ;

position * new_node(int col, int row, int val){
    
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

position * append(int col, int row, int val){
    position * link = new_node(row, col, val);
    if(end_pos){
        link->last = end_pos;
        end_pos->next = link;
    }
    end_pos = link;
    if(!start_pos){
        start_pos = link;
    }
    return link;
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
