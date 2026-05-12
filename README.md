# biocomputing_core

High-performance DNA sequence generator C library with sequential and parallel (OpenMP) implementations.

This is the C backend for the [biocomputing](https://github.com/sigdelsanjog/biocomputing) Python package.

## Building

```bash
make
```

This creates:

- `libdna_sequential.so` - Sequential DNA generator
- `libdna_parallel.so` - Parallel DNA generator (OpenMP)

## Installation

### Prerequisites

```bash
# Ubuntu/Debian
sudo apt-get install build-essential libomp-dev

# macOS
brew install gcc libomp

# Fedora/RHEL
sudo dnf install gcc gcc-c++ libomp-devel
```

### Build

```bash
make
```

## Testing

```bash
make seq_test par_test
./seq_test
./par_test
```

## Cleaning

```bash
make clean
```

## Library Usage

See the header file `dna_generator.h` for the C API.

### C Function Signatures

```c
typedef struct {
    char *sequence;
    double time_taken;
} DNAResult;

DNAResult generate_dna_sequential(unsigned long length);
DNAResult generate_dna_parallel(unsigned long length);
void free_dna_result(DNAResult *result);
```

## License

MIT License - See LICENSE file
