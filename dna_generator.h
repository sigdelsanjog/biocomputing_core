#ifndef DNA_GENERATOR_H
#define DNA_GENERATOR_H

#include <time.h>

typedef struct {
    char *sequence;
    double time_taken;
} DNAResult;

// Sequential DNA sequence generator
DNAResult generate_dna_sequential(unsigned long length);

// Parallel DNA sequence generator
DNAResult generate_dna_parallel(unsigned long length);

// Free memory allocated for DNA sequence
void free_dna_result(DNAResult *result);

#endif // DNA_GENERATOR_H
