# Makefile for DNA Generator Libraries
CC = gcc
CFLAGS_SEQ = -Wall -fPIC -shared
CFLAGS_PAR = -Wall -fPIC -shared -fopenmp

# Targets
all: libdna_sequential.so libdna_parallel.so

# Shared library for sequential generator
libdna_sequential.so: sequential_sequence_generator.c dna_generator.h
	$(CC) $(CFLAGS_SEQ) sequential_sequence_generator.c -o libdna_sequential.so

# Shared library for parallel generator
libdna_parallel.so: parallel_sequence_generator.c dna_generator.h
	$(CC) $(CFLAGS_PAR) parallel_sequence_generator.c -o libdna_parallel.so

# Standalone binaries (optional, for testing)
seq_test: sequential_sequence_generator.c dna_generator.h
	$(CC) -Wall sequential_sequence_generator.c -o seq_test

par_test: parallel_sequence_generator.c dna_generator.h
	$(CC) -Wall -fopenmp parallel_sequence_generator.c -o par_test

# Clean
clean:
	rm -f *.so seq_test par_test

.PHONY: all clean
