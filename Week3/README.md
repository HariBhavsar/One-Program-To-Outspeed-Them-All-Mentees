# Theory
## Binary Manipulation
- It is a type of software optimization
- It involves taking advantage of the fact that, at a hardware level, numbers are just strings of 0s or 1s
- This fact that each bit can take one of two values, gives us powerfull `O(poly(n)*logn)` algorithms for many use cases
- Get started by reading the `README.md` file in the `binaryManipulation` folder
## OpenCL
- OpenCL is a programming language used to program on the `Graphics Processing Unit (GPU)`
- The GPU is a highly specialised piece of hardware built to take advantage of mass parallelism
- The GPU is best used on workloads that involve a huge amount of number crunching and very little conditional logic
- Its architecture consists of hundreds or even thousands of `cores`, however each core is smaller and does not have a `branch predictor`
- Each GPU core also shares memory with every other core
# Assignments
- Thats it, the theory part of this SoC is over, hope you enjoyed it, hope you learnt something
- Going forth, this SoC will be focussed almost entirely on applications and making use of all the optimizations that we have learnt
- Use the knowledge you have gained so far to solve the problem statements given in the files in the `assignments` folder