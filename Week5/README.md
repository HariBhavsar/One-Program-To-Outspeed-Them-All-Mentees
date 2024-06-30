# Machine Learning
- The big week is here! We are finally going to dvelve into machine learning and we are going to do it in C++.
- We hope all of you attempted last weeks's assignment (optimising various matrix operations using threads,SIMD,openCL).
- If you have not done machine learning previously, then no worries we will define everything that's required for you to get  this week done.
- Hopefully this will spark your interest in ML too :).
## What is Machine Learning?
- Machine learning is a type of artificial intelligence that allows computers to learn from data and make decisions without being explicitly programmed. It helps in recognizing patterns and making predictions, and is used in many areas like recommending products, detecting spam, and more.
- We will mainly deal with supervised learning which is a type of machine learning. Supervised learning is where the model is trained on labeled data. This means the data includes both the input features and the correct output. The goal is for the model to learn the relationship between inputs and outputs so it can make accurate predictions on new, unseen data. It is commonly used for tasks like classification (e.g. spam detection) and regression (e.g. predicting house prices).
## Assignments
- There are three tasks for this week:
    - Implementing linear.cpp in `Week5/linear/`
    - Implementing logisitic.cpp in `Week5/logistic/`
    - Implementing regression.cpp in `Week5/regression/`
- Each of three folders `linear`,`logistic` and `regression` have three different `C/C++` files - the respective `.h` files, the respective `.cpp` files and the file `main.cpp` which contains the main function.
- `main.cpp` and the `.h` files are not be edited. 
- You will only need to implement the methods defined in the `.h` files in the respective `.cpp` files. 
- Apart from this, the three folders will also each contain an input file `input.txt` and a `makefile`.
- For testing the files refer to the makefiles of each folder.
- There is also a folder `matrix/`. This contains the files `matrix.h` and `matrix.cpp`. 
- Note that there are changes made to both `matrix.h` and `matrix.cpp` (`naive.cpp` of week 4) from the previous week. 
- You will not get any compilation error if you replace the files from the previous week in week5's matrix folder. However
the updated files contain a few more functions like `norm`, and `dot` and more overloads for the operators (binary operators and unary minus) and the `log` function. This was done to make sure the implementations look as close to `numpy` of python as possible.
- However you are free to either week4's `matrix.h` and `optim.cpp` or week5's `matrix.h` and your own optimisations to the new functions (the `matrix.cpp` file that is present in `Week5/matrix` is NOT optimised).
- Whatever you use, just be sure to label your files as `matrix.h` and `matrix.cpp` and paste them in the directory `Week5/matrix` because that is how they have been included in all the other files.
- All other definitions and relevant formulae are given as comments in the respective files. Please read them carefully before attempting the assignment.