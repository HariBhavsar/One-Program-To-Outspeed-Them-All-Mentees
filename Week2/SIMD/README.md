# SIMD
- There are 3 cpp files that you have to complete
### introToSIMD.cpp
- This is more of a reading material
- Go through the code and the comments to understand what register based parallelization is
- Complete the task at the end of the code
- Compile using `g++ introToSIMD.cpp -o introToSIMD`
- Run using `./introToSIMD`
### SIMDUsingCPP.cpp
- Get yourself familiar with the syntax of the immintrin.h library
- Make the code work for vectors with size not divisible by 8
- Compile using `g++ SIMDUsingCPP.cpp -mavx -o SIMDUsingCPP`
- Run using `./SIMDUsingCPP`
- OPTIONAL : Try to implement the same functionality with integers instead of floating point numbers
### finalTask.cpp
- Implement dot product of two vectors using SIMD instructions
- See syntax and hints in `syntax.txt`
- Compile using `g++ finalTask.cpp -mavx -o finalTask`
- Run using `./finalTask`
- Share your speedup over naive implementation for large (size >= 1000) vectors