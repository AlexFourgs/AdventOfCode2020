#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "day3.h"


int main()
{
	int len_line, nb_lines;
        char **map;
	int tree_count_1;
	long tree_count_2;
	int slice_part_1[1][2] = {{3, 1}};
	int slices_part_2[5][2] = 
	{
		{1, 1},
		{3, 1},
		{5, 1},
		{7, 1},
		{1, 2}
	};
	
	// reading file, calculating lenghts and store data
	count_sizes("input.txt", &len_line, &nb_lines);
	map = read_file("input.txt", len_line, nb_lines);
	
	tree_count_1 = validate_part1(map, len_line, nb_lines, slice_part_1[0][0], slice_part_1[0][1]);
	tree_count_2 = validate_part2(map, len_line, nb_lines, slices_part_2);
	
	printf("Answer for part 1 is = %d\n", tree_count_1);
	printf("Answer for part 2 is = %ld\n", tree_count_2);
	
	return 0;
}
