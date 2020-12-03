void count_sizes(char *file_path, int *len_line, int *nb_lines);
char **read_file(char *file_path, int len_line, int nb_lines);
int validate_part1(char **map, int len_line, int nb_lines, int vertical_shift, int horizontal_shift);
long validate_part2(char **map, int len_line, int nb_lines, int shifts[5][2]);
