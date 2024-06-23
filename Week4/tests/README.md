# tests
- This folder exists for you to be able to test your implementations
- There are 5 other files in this folder
- I feel like other than `make.sh`, every other file is self-explanatory
## make.sh
- It compiles the given `test*.cpp` files into binaries with seperate binaries for naive and optimized implementations
- Simply run the binary and check that your output (from the `*optim` files) is the same as that from naive implementation
- Feel free to edit the compilation lines to accomodate `SIMD`, `Multithreading` or `OpenCL` 