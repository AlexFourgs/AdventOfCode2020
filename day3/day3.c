#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day3.h"

// TODO: compare different way to count len (fgets, getc, ...)
void count_sizes(char *file_path, int *len_line, int *nb_lines)
{
	FILE *fp;
	char c;
	
	*len_line = 0;
	*nb_lines = 0;
	
	fp = fopen(file_path, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	
	// counting lenght of a line
	for (c = getc(fp); c != '\n'; c = getc(fp)) {
		*len_line += 1;
	}
	
	// reset fp
	rewind(fp);
	
	// counting number of lines
	for (c = getc(fp); c != EOF; c = getc(fp)) {
		if (c == '\n')
			*nb_lines += 1;
	}
	
	fclose(fp);
	
	// add 1 because no newline at end of file
	*nb_lines += 1;
}

char **read_file(char* file_path, int len_line, int nb_lines)
{
        FILE *fp;
        char **data;
	char chunk[50];
        int idx = 0;
        
        data = malloc(nb_lines*sizeof(char*));
        
        fp = fopen(file_path, "r");
        if (fp == NULL)
                exit(EXIT_FAILURE);
	
	// calculating lenght of a line and allocate memory
	fgets(chunk, sizeof(chunk), fp);
	
	for(int i = 0; i < nb_lines; i++)
                data[i] = malloc(sizeof(chunk)*sizeof(char));
        
	rewind(fp);
	
	// copying file str in data
	while (fgets(chunk, sizeof(chunk), fp) != NULL) {
		strcpy(data[idx], chunk);
                idx++;
        }

        fclose(fp);

        return data;
}

int validate_part1(char** map, int len_line, int nb_lines, int vertical_shift, int horizontal_shift){
	int tree_count = 0;
	int vertical_pos = vertical_shift;
	char current;
	
	for (int i = horizontal_shift; i < nb_lines; i += horizontal_shift) {
		current = map[i][vertical_pos%len_line];
		vertical_pos += vertical_shift;
		
		if (current == '#')
			tree_count++;
	}

	return tree_count;	
}

long validate_part2(char **map, int len_line, int nb_lines, int shifts[5][2]){
	long tree_count = 1;
	int current_count;
	
	// for each shift
	for (int i = 0; i < 5; i++) {
		tree_count *= validate_part1(map, len_line, nb_lines, shifts[i][0], shifts[i][1]);
	}
	
        return tree_count;
}
