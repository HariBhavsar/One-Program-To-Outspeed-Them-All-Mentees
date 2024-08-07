# One-Program-To-Outspeed-Them-All
Welcome to our SOC "One Program To Outspeed Them All". Join us as we program keeping performance first and foremost!
Here is the tentative schedule:

## Week 0 : Setting up
- This week will be spent in setting up your coding environment. We recommend WSL as you can code in C/C++ without any hassle once you set up WSL.
- Install wsl : https://learn.microsoft.com/en-us/windows/wsl/install
- Use ubuntu preferrably although pretty much any distribution should be okay (so if you do not have ubuntu don't panic and change your distribution lol you will probably be fine)
- In case you want to try using the manual install (as the default one may not work for everyone), follow this : https://learn.microsoft.com/en-us/windows/wsl/install-manual
- Integrate WSL with visual studio code : https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-vscode
- Install git : https://learn.microsoft.com/en-us/windows/wsl/tutorials/wsl-git
- Run the following command to install g++, gdb (optional but recommended), make : `sudo apt update && upgrade && sudo apt-get install build-essential && sudo apt install g++ gdb make ninja-build rsync zip`
- Run the following command to install python (we might need this for plotting performance) : `sudo apt install python3 python3-pip ipython3`
- Fork this git repository
- Instructions for forking: 
- Follow the instructions on : https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo
- Here are some practice questions to check your installation.
- Check g++ installation by completing the task described in compile.cpp 
- Complete the tasks in naive.cpp (implement naive Schur/Element-Wise Product of two vectors)
- Run the command `make` on the terminal to check Makefile installation
- Run the command `python3 grapher.py` to check python installation
- You might need to install some python modules like matplotlib or numpy in which case run pip install {nameOfModule}
## Week 1 : May the Threads be with you
- Familiarise yourself with the threading library threads of C++.
- Understand the concepts of mutual exclusions, race conditions and why locking is necessary (yes it is totally not from a core course of a certain department).
- Use locks and conditional variables in programs yourself and understand why they are necessary.
- Also using locks leads to delays so use them smartly and only where necessary.
- Follow the instructions given in the `README.md` file in the `Week1` folder
## Week 2 : Maximizing Resource Usage
- Understand the power of Registers and how one may use specialised registers for parallelization
- Utilize your system memory to achieve huge speedups
- Understand the syntax and usage of `SIMD` instructions as well as the intuition behind `Memoization`
- Get a taste of `Cache Conscious Programming` and how simply reordering loops can result in huge performance gains 
- Follow the instructions given in the `README.md` file in the `Week2` folder
## Week 3 : The Last of The Theory
- Gain knowledge about what `Graphics Processing Units` are and how to use them to their full potential
- Learn to take advantage of numbers and how exactly they're represented in computers
- Create powerfull algorithms by pushing your hardware to its fundamental limits
- Take a look back at all you have learnt so far and use it to gain incredible speedups in fundamental problems
- Get started by following the instructions in the `README.md` file in the `Week3` folder
## Week4 : Numpy in CPP
- The first of our pure application based weeks
- In this week you will be building the foundations of `Machine Learning`
- You will be implementing the `numpy` library in C++
- Apply all that you have learned so far to get huge performance gains over the naive implementations
- Get started by following the instructions in the `README.md` file in the `Week4` folder
## Week5 : Machine Learning
- One of the biggest buzzwords in the world of Computer Science right now
- Everyone and their grandmother is obsessed with machine learning
- However, traditional machine learning is done almost entirely in `python`, due to the language's powerfull abstractions
- Last week, we shattered the wall between the `numpy` library and this week will expose the power of `low level code` to this coveted field
- Put your matrices to work performing `linear` and `logistic regression`, the fundamental cornerstones of any good ML library 
## Week6 : CNF Solver
- One of the most important problems of the last century
- It quite literally has a `million dollar` price tag 
- Modern SAT solvers are incredibly powerful and highly specialised, the goal is to try to replicate this power
- Unlike matrices, we cannot just throw `multithreading` at this problem and hope to solve it
- We have to be a lot more `clever` about optimising this
- Get started by following the instructions in the `README.md` file in the `Week6` folder
## Week7 : SAT Solver
- Make the CNF Solver of Week 6 actually usable via API calls
- Add compatibility of any `arbitary formula` rather than restricting yourself to CNFs
- Use this SAT Solver to solve `NP-Complete` problems
- You will have to use your brain to think about how you can `reduce` the problems to SAT
- No forced optimizations this week, although tseitin can be highly optimized
- Get started by following the instructions in the `README.md` file in the `Week7` folder