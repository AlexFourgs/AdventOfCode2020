#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day2.h"

char **read_file(char* file_path)
{
        FILE *fp;
        char **data;
        char chunk[STR_SIZE];
        int idx = 0;
        
        
        data = malloc(MAX_SIZE*sizeof(char*));
        for(int i = 0; i < MAX_SIZE; i++)
                data[i] = malloc(STR_SIZE*sizeof(char));
        
        fp = fopen(file_path, "r");
        if (fp == NULL)
                exit(EXIT_FAILURE);

        while (fgets(chunk, sizeof(chunk), fp) != NULL) {
                strcpy(data[idx], chunk);
                idx++;
        }

        fclose(fp);
        
        return data;
}


void parse(char *str, int *min_occ, int *max_occ, char *let, char *password)
{
        char *split[3];
        int idx=0;
        char *ptr_occ, *ptr_let;
        char space_delim[] = " ";
        char policy_delim[] = ":";
        char occ_delim[] = "-";
        
        // split str with " ", first occurence is occurencies policies, 
        // second is letter policy, third is password
        ptr_occ = strtok(str, space_delim);
        while(ptr_occ != NULL) {
                split[idx] = ptr_occ;
                idx++;
                ptr_occ = strtok(NULL, space_delim);
        }
        
        // parsing occurence policies
        *min_occ = atoi(strtok(split[0], occ_delim));
        *max_occ = atoi(strtok(NULL, occ_delim));
        
        // parsing letter policy
        ptr_let = strtok(split[1], policy_delim);
        *let = ptr_let[0];

        // copying password
        strcpy(password, split[2]);
}

int validate_part1(char* password, int min_occ, int max_occ, char let){
        int len;
        int occ_count = 0;
        
        len = strlen(password)-1;
        
        for (int i = 0; i < len; i++) {
                if (password[i] == let)
                        occ_count++;
                if (occ_count > max_occ)
                        return 0;
        }
        
        if (occ_count < min_occ)
                return 0;
        
        return 1;
}

int validate_part2(char* password, int pos_1, int pos_2, char let){
        
        return ((password[pos_1-1] == let) ^ (password[pos_2-1] == let));
}
