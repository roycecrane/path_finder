#ifndef Position_h
#define Position_h

#include <stdio.h>

#include <stdlib.h>


typedef struct Positon {
    int val;
    int index;
    
    struct Positon * last;
    struct Positon * next;
} position;


extern position * first_node;
extern position * last_node;
extern int nodeIndex;

void deleteList(void);
position * get_node(int);
position * newNode(int);
void insertAtEnd(int val);
void printList(void);
position * getNode(int idx, position * currentNode);





#endif /* Position_h */
