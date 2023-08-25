#include "Util.h"
#include <sys/stat.h>

int num_rows = 0;
int num_cols = 0;
char ** map;

void print_map(void){
    for(int i = 0; i < num_cols; i++){
        printf("%s\n",map[i]);
    }
}

void get_file(char * file_name){

    FILE * file_ptr;
    char * line = NULL;
    size_t len = 0;
    struct stat st;
    
    stat(file_name, &st);
//    get file size
    int file_size = (int) st.st_size;
//    get the len of first row
    file_ptr = fopen(file_name, "r");
    num_rows = (int) getline(&line, &len, file_ptr);
//    send file ptr back to first row
    rewind(file_ptr);
//    use file size and row len to get col len
    num_cols = file_size / num_rows;
    int i = 0;
//    allocate memory for map matrix and fill it with fill with file vals
    map = (char**)malloc(num_cols * sizeof(char*));
    for (i = 0; i < num_cols; i++)
        map[i] = (char*)malloc(num_rows * sizeof(char));
    ssize_t read;
    if (file_ptr == NULL)
        exit(EXIT_FAILURE);
    i = 0;
    while ((read = getline(&line, &len, file_ptr)) != -1) {
        for( int j = 0; j < num_rows - 1; j++){
            map[i][j] = line[j];
        }
        i++;
    }
    
    fclose(file_ptr);
    if (line)
        free(line);
}

void deleteMap(char ** map){
    for(int i = 0; i < num_cols ; i++)
        free(map[i]);
    free(map);
}
