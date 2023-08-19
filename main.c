#include <stdio.h>
#include "Util.h"
#include "Position.h"
#include "ChooseMove.h"
int main(int argc, const char * argv[]) {
    get_file("map.txt");
    
    int start_coords[] = {18,16};
    int end_coords[] = {20,47};
    
    position * start = append(start_coords[0], start_coords[1], 0);
    set_params(start_coords, end_coords);
    make_move(start);
    
    print_map();
    print_list();
    delete_list();
    deleteMap(map);
    return 0;
}
