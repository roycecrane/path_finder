#ifndef Lists_h
#define Lists_h

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    int index;
    int row;
    int col;
    int branch_depth;
    int back_track;
    struct ListNode * last;
    struct ListNode * next;
} pos_node;

extern int numebr_of_test_lists;

pos_node * new_list(int col, int row, int val, int branch_depth);
pos_node * init_node(int col, int row, int val,int branch_depth);
pos_node * add_node(pos_node * pos, int col, int row, int val, int branch_depth);

pos_node * get_list_node(pos_node* pos, int col, int row);

pos_node * get_first_node(pos_node * pos);
pos_node * get_last_node(pos_node * pos);


void delete_node(pos_node * pos);
void print_list(pos_node * pos);
void delete_list(pos_node * pos);
#endif /* Lists_h */
