#define MAX_SIZE 1000
#define STR_SIZE 40

char **read_file(char *file);
void parse(char *str, int *min_occ, int *max_occ, char *let, char *password);
int validate_part1(char* password, int min_occ, int max_occ, char let);
int validate_part2(char* password, int pos_1, int pos_2, char let);
