#include <stdio.h>
#include "Util.h"
#include "MakeMove.h"
#include "Lists.h"


int main(int argc, const char * argv[]) {
//    load map
    get_file("map.txt");
//
    int start_coords[] = {18,16};
    int end_coords[] = {20,47};
    pos_node * start = new_list(start_coords[0], start_coords[1], 0, 0);
//    set the start and end coords
    set_params(start_coords, end_coords);
//    start exploring map
    make_move(start);
    
    int final_val = get_last_node(start)->val;
    
    printf("final outcome: %d\n", final_val);
    
    for(int i = 0;i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            pos_node * p  = get_list_node(start, j, i);
            if(p){
                int in = p->index % 10;
                char c [3];
                sprintf(c, "%d", in);
                map[j][i] = c[0];
            }
        }
    }
    for(int i = 0;i < num_cols; i++){
        printf("%s\n",explored_map[i]);
    }
    start = get_last_node(start);
    printf("num steps: %d\n",start->index);
    printf("num states explored: %d\n",num_states_explored);
    print_list(start);
    
    delete_list(start);
    print_map();
    return 0;
}
