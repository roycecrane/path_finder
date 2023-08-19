#include <stdio.h>
#include "Util.h"
#include "Position.h"
#include "ChooseMove.h"

int main(int argc, const char * argv[]) {
    get_file("map.txt");
    
    int start_coords[] = {18,16};
    int end_coords[] = {20,47};
    
    position * start = add_pos(start_coords[0], start_coords[1], 0);
    set_params(start_coords, end_coords);
    
    make_move(start);
    
    for(int i = 0;i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            position * p  = get_pos(j, i);
            if(p){
                int in = p->index % 10;
                char c [3];
                sprintf(c, "%d", in);
                printf("%s\n", c);
                map[j][i] = c[0];
            }
        }
    }
    print_map();
    delete_list();
    deleteMap(map);
    return 0;
}
