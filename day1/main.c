#include <stdio.h>
#include <stdlib.h>

#include "day1.h"


int main()
{
        int *data, *entries;
        int sum_searched = 2020;
        int answer, nb_entries;
        
        data = read_file("input.txt");
        
        // step 1, 2 entries
        nb_entries = 2;
        entries = found_entries(data, sum_searched, nb_entries);
        answer = entries[0]*entries[1];
        
        printf("Entries = {%d, %d} (%d)\n", entries[0], entries[1], (entries[0]+entries[1]));
        printf("Answer 1 = %d\n\n", answer);
        
        // step 2, 3 entries
        nb_entries = 3;
        entries = found_entries(data, sum_searched, nb_entries);
        answer = entries[0]*entries[1]*entries[2];
        
        printf("Entries = {%d, %d, %d} (%d)\n", entries[0], entries[1], entries[2], (entries[0]+entries[1]+entries[2]));
        printf("Answer 2 = %d\n", answer);
        
        
        return 0;
}
