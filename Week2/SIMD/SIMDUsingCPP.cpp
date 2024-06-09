#include <iostream>
#include <immintrin.h>
#include <iomanip>
using namespace std;
int main () {

/*

The first bit of this code will go through the syntax of SIMD, I will showcase how to use SIMD by adding two 128*1 Vectors each having 32 bit elements
The code below computes vec3 = vec1 + vec2

*/

float vec1[128];
float vec2[128];
float vec3[128];
__m256 v1,v2,v3; // using 256 bit registers, each float is of 32 bits so each register holds up to 8 floats
for (int i=0; i<128; i++) {
    vec1[i] = i;
    vec2[i] = 2*i;
} 

for (int i=0; i<128; i+=8) {
    v1 = _mm256_loadu_ps(vec1+i); // load vec1[i],vec1[i+1]..vec1[i+7] into 256 bit register
    v2 = _mm256_loadu_ps(vec2+i); // load vec2[i],vec2[i+1]..vec2[i+7] into 256 bit register
    v3 = _mm256_add_ps(v1,v2); // add the two 256 bit registers and store result in a third 256 bit register (v3)
    _mm256_storeu_ps(vec3+i,v3); // store v3 in vec3+i
}

for (int i=0; i<128; i++) {
    cout<<vec3[i]<<" ";
}

/*

Repeat the above experiment but for vectors whose size is not divisible by 8. You will see that stack smashing occurs or segmentation fault occurs
Why is that?
How can we fix it?

TASK : UNCOMMENT THE BELOW CODE AND OBSERVE A RUNTIME ERROR OF SOME KIND (also post the error that you got on whatsapp)
TASK : FIX THE CODE SO THAT THE RUNTIME ERROR DOES NOT OCCUR

*/

// float vec1[130];
// float vec2[130];
// float vec3[130];
// __m256 v1,v2,v3; // using 256 bit registers, each float is of 32 bits so each register holds up to 8 floats
// for (int i=0; i<130; i++) {
//     vec1[i] = i;
//     vec2[i] = 2*i;
// } 
//
// for (int i=0; i<130; i+=8) {
//     v1 = _mm256_loadu_ps(vec1+i); // load vec1[i],vec1[i+1]..vec1[i+7] into 256 bit register
//     v2 = _mm256_loadu_ps(vec2+i); // load vec2[i],vec2[i+1]..vec2[i+7] into 256 bit register
//     v3 = _mm256_add_ps(v1,v2); // add the two 256 bit registers and store result in a third 256 bit register (v3)
//     _mm256_storeu_ps(vec3+i,v3); // store v3 in vec3+i
// }
//
// for (int i=0; i<130; i++) {
//     cout<<vec3[i]<<" ";
// }

}