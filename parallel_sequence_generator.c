#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include "dna_generator.h"

// Parallel DNA sequence generator function
DNAResult generate_dna_parallel(unsigned long length) {
    DNAResult result;
    result.sequence = (char*) malloc((length + 1) * sizeof(char));
    if (result.sequence == NULL) {
        result.time_taken = -1.0;
        return result;
    }
    char bases[] = {'A', 'T', 'G', 'C'};
    double start = omp_get_wtime();
    #pragma omp parallel
    {
        unsigned int seed = time(NULL) ^ omp_get_thread_num();
        #pragma omp for
        for (unsigned long i = 0; i < length; i++) {
            result.sequence[i] = bases[rand_r(&seed) % 4];
        }
    }
    result.sequence[length] = '\0';
    double end = omp_get_wtime();
    result.time_taken = end - start;
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
int main(int argc, char *argv[]) {
    unsigned long length = 1000000000UL; // Default length
    
    // Accept sequence length as command-line argument
    if (argc > 1) {
        length = strtoul(argv[1], NULL, 10);
    }
    
    DNAResult result = generate_dna_parallel(length);   
    if (result.time_taken < 0) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Parallel generation completed\n");
    printf("Threads used: %d\n", omp_get_max_threads());
    printf("Time taken: %f seconds\n", result.time_taken);
    printf("First 100 bases:\n");
    for (int i = 0; i < 100; i++) {
        printf("%c", result.sequence[i]);
    }
    printf("\n");
    free_dna_result(&result);
    return 0;
}
