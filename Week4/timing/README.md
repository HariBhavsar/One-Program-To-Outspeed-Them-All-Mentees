# tests
- This folder exists for you to be able to check the performance of your implementations
- There are 5 other files in this folder
## make.sh
- It compiles the given `time*.cpp` files into binaries with seperate binaries for naive and optimized implementations
- Simply run the binary, give it some appropriate input and check that your output (from the `*optim` files) is faster (smaller) than the output from naive implementation
- Feel free to edit the compilation lines to accomodate `SIMD`, `Multithreading` or `OpenCL`
- Here is a list of sample inputs (essentially matrix dimensions) that should help you test your performance
1. timeBasicOperators.cpp - 1024
2. timeExp.cpp - 1024
3. timeMatrOps.cpp - 512 (don't give 1024 here lol 90+ seconds tak jaata hai naive implementation)
4. timeMinMax.cpp - 1024