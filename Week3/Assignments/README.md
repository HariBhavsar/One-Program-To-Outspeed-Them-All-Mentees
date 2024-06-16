# Assignments
- There are two `.cpp` files in this folder, you are to complete the tasks mentioned in both files
### treeSearch.cpp
- The naive implementation uses breadth-first search to try and locate the key
- You cannot do better than O(n) here! BFS/DFS are indeed the fastest available algorithms as the given tree does not have any kind of order
- However, there is very little `overlap`, that is, `the results of one search does not help or hinder another`
- Thus, one can exploit multithreading for this algorithm
- Compile using `g++ treeSearch.cpp -mavx -o treeSearch`, add the mavx flag if and only if your implementation uses SIMD instructions
### quake3.cpp
- Once upon a time, in the dark ages before good CISC architecture, when developers needed to quickly calculate inverse square roots they found no good method (Newton-Raphson/Gradient-Descent is cumbersome)
- They stumbled upon some magical floating point values that could help them with their computation
- This algorithm is a bit outdated as now we have instructions that directly compute inverse square roots, nonetheless it is fascinating
- Here is the original algorithm used by developers of the game `Quake 3 : Arena`
```c
float Q_rsqrt(float number)
{
  long i;
  float x2, y;
  const float threehalfs = 1.5F;

  x2 = number * 0.5F;
  y  = number;
  i  = * ( long * ) &y;                       // evil floating point bit level hacking
  i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
  y  = * ( float * ) &i;
  y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
  // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

  return y;
}
```
- You are forbidden from using the `sqrt()` method of the cmath library
- However as you are working with large arrays, you might find that `SIMD` instructions are hiding something from you :)
- Compile using `g++ quake3.cpp -mavx -o quake3`, add the mavx flag if and only if your implementation uses SIMD instructions