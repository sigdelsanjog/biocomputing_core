#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dna_generator.h"

// Sequential DNA sequence generator function
DNAResult generate_dna_sequential(unsigned long length) {
    DNAResult result;
    result.sequence = (char*) malloc((length + 1) * sizeof(char));
    
    if (result.sequence == NULL) {
        result.time_taken = -1.0;
        return result;
    }
    
    char bases[] = {'A', 'T', 'G', 'C'};
    srand(time(NULL));
    clock_t start = clock();
    
    for (unsigned long i = 0; i < length; i++) {
        result.sequence[i] = bases[rand() % 4];
    }
    result.sequence[length] = '\0';
    
    clock_t end = clock();
    result.time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    
    return result;
}

// Free function
void free_dna_result(DNAResult *result) {
    if (result && result->sequence) {
        free(result->sequence);
        result->sequence = NULL;
    }
}

// Main function for standalone testing
int main() {
    unsigned long length = 1000000000UL;
    DNAResult result = generate_dna_sequential(length);
    
    if (result.time_taken < 0) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Sequential generation completed\n");
    printf("Time taken: %f seconds\n", result.time_taken);
    printf("First 100 bases:\n");
    for (int i = 0; i < 100; i++) {
        printf("%c", result.sequence[i]);
    }
    printf("\n");
    
    free_dna_result(&result);
    return 0;
}