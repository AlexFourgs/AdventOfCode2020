#include <stdio.h>
#include <stdlib.h>
#include "day1.h"

int *read_file(char* file_path)
{
        FILE *fp;
        int *data;
        char chunk[128];
        int idx = 0;
        
        data = malloc(MAX_SIZE*sizeof(int));
        
        fp = fopen(file_path, "r");
        if (fp == NULL)
                exit(EXIT_FAILURE);

        
        while (fgets(chunk, sizeof(chunk), fp) != NULL) {
                data[idx] = atoi(chunk);
                idx++;
        }
    
        fclose(fp);
        
        return data;
}

int *found_entries(int *data, int sum_searched, int nb_entries)
{
        int sum;
        int *entries;
        
        entries = malloc(nb_entries*sizeof(int));
        
        if (nb_entries == 2) {
                for (int i=0; i<MAX_SIZE; i++) {
                        for (int j=i+1; j<MAX_SIZE; j++) {
                                sum = data[i]+data[j];
                                if (sum == sum_searched) {
                                        entries[0] = data[i];
                                        entries[1] = data[j];
                                        return entries;
                                }
                        }
                }
        }
        else if (nb_entries == 3) {
                for (int i=0; i<MAX_SIZE; i++) {
                        for (int j=0; j<MAX_SIZE; j++) {
                                for (int k=0; k<MAX_SIZE; k++) {
                                        sum = data[i]+data[j]+data[k];
                                        if (sum == sum_searched) {
                                                entries[0] = data[i];
                                                entries[1] = data[j];
                                                entries[2] = data[k];
                                                return entries;
                                        }
                                }                                        
                        }
                }
        }
        
        return NULL;
}
