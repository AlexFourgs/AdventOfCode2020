#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "day2.h"


int main()
{
        char **data;
        int pol_nb_1, pol_nb_2;
        char let;
        char *password;
        int total_valid_1 = 0, total_valid_2 = 0;
        
        data = read_file("input.txt");
        
        for (int i=0; i<MAX_SIZE; i++) {
                parse(data[i], &pol_nb_1, &pol_nb_2, &let, password);
                
                // part 1
                total_valid_1 += validate_part1(password, pol_nb_1, pol_nb_2, let);
                
                // part 2
                total_valid_2 += validate_part2(password, pol_nb_1, pol_nb_2, let);
        }
        
        printf("Anwser for part 1 is : %d\n", total_valid_1);
        printf("Anwser for part 2 is : %d\n", total_valid_2);
        
        return 0;
}
