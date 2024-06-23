# Matrix
- This is the only folder in which you actually have to make any code changes however this week will have more code changes than weeks 1 and 2 combined
- There are three files in this folder
## matrix.h
- It is a header file that contains a list of functions and operations that you are expected to implement.
- Don't be too intimidated by the boilerplate OOP code that we had to add (such as `friend`) just to make sure you can implement the functions in a seperate file.
- There are 8 different parts of this file, you are expected to implement 7 of these 8 parts, here is a small explanation of each part.
- Note that you can find the explanation of what individual functions do in the comments provided next to the functions:
1. Actual Matrix : This contains the actual data of the matrix as well as its shape.
2. Constructors : This contains functions that handle the creation of matrices.
3. Utility Functions : These are `implemented for you` and should make it easier to write python-like code.
4. Operators : These contain functions that define how matrices `interact` with other matrices and non-matrix objects.
5. Matrix Operations : These contain are functions that are for common operations on matrices.
6. Basic Functions : These make it easier to get some standard matrices that are very commonly used.
7. MinMax Functions : These allow you to get row-wise or column-wise maximum/minimum elements or their positions.
8. Element Functions : These contain functions for performing element-wise operations on matrices
- You may edit this file but make sure your edits are compatible with `naive.cpp`.
## naive.cpp
- This file contains naive implementations of all 7 parts that you are expected to implement.
- The implementations in this file are purposely slow and there is a `huge` room for performance improvement.
- You are expected to understand some of the more complicated functions such as `matrix inverse` and `determinant` and make the implementation faster.
- For some of the more complicated functions we have provided comments.
- Ideally you should `not` edit this file, however, you might need to in case you have made some changes in the header, in which case feel free to edit.
- Note that `naive.cpp` is merely the base code and can be used to check correctness of your optimised code. However do not expect certain functions to run fast and keep input sizes small for testing accuracy.
## optim.cpp
- This is the file in which you are expected to make changes.
- The file currently has the same code as `naive.cpp` you are to make changes to boost performance
- Feel free to use `OpenCL`, `SIMD` or `multithreading`, however, you will need to change the make files of your tests and timing in that case so do keep that in mind. Also bear in mind the iterative implementations of most functions are far faster 
than their recursive versions.
- Unless you use the aforementioned optimizations, you will not be able to get any significant speedup.