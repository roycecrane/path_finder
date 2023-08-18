#include "Position.h"

position * first_node = NULL;
position * last_node = NULL;

int nodeIndex = 0 ;

position * newNode(int val){
    
    position * n = (position *) malloc(sizeof(position));
    
    n->val = val;
    n->last = NULL;
    n->next = NULL;
    n->index = nodeIndex;
    
    nodeIndex++;
    
    return n;
};

void insertAtEnd(int val){
    
    position * link = newNode(val);
    
    if(last_node){
        link->last = last_node;
        last_node->next = link;
    }
    
    last_node = link;
    if(!first_node){
        first_node = link;
    }
  
}
position * get_node(int idx){
    position * n = first_node;
     while(n){
         if(n->index == idx){
             return n;
         }
         n = n->next;
     }
     return NULL;
}

void deleteList(void){
    position * current = first_node;
    position * next = NULL;
    int i = 0;
    
    while(current){
        
        next = current->next;
        free(current);
        current = next;
        i++;
    }
}

void printList(void){
    position * n = first_node;
    while(n){
        printf("%d\n",n->val);
        n = n->next;
    }
}
