/*

This CPP file is going through a midlife crisis and is under the impression that it is a .ipynb file
Please accept its beliefs and read the comments in the file :)

*/
#include <iostream>
using namespace std;
/*

One of the most important parts of the CPU is the registers
They are tiny chunks of memory the CPU can use for things like computation, function return values, storing addresses etc.
This CPP file will guide you through understanding : 
1]What registers are
2]How we can exploit registers to their maximum potential
Thereby squeezing every drop of computational power that we can 

*/
int main () {
/*

THE SETUP:

Lets assume you had a simple code, you have two pairs of 32 bit integers, a = {12,16} and b = {14,20}
You are to add them and store the result in another 32 bit integer, c = a + b = {26,36}
The traditional way to do this would be as written below

*/

int32_t a[2] = {12,16}; // a[0] = 12, a[1] = 16
int32_t b[2] = {14,20}; // b[0] = 14, b[1] = 20
int32_t c[2]; // declare c
c[0] = a[0] + b[0]; // c[0] = a[0] + b[0] = 26
c[1] = a[1] + b[1]; // c[1] = a[1] + b[1] = 36
cout<<c[0]<<" "<<c[1]<<endl;
/*

Well lets try and understand how a computer goes through and does this, for this we need to go one level lower into the generated assembly
The generated assembly looks as follows, it can be a bit hard to understand so I have set up comments using semicolons:
	mov	DWORD PTR -32[rbp], 12 ; sets a[0] = 12 
	mov	DWORD PTR -28[rbp], 16 ; sets a[1] = 16
	mov	DWORD PTR -24[rbp], 14 ; sets b[0] = 14
	mov	DWORD PTR -20[rbp], 20 ; sets b[1] = 20
	mov	edx, DWORD PTR -32[rbp] ; sets edx = a[0] (bringing a[0] into a register so that the cpu can work on it)
	mov	eax, DWORD PTR -24[rbp] ; sets eax = b[0] (bringing b[0] into a register so that the cpu can work on it)
	add	eax, edx ; sets eax = eax + edx = a[0] + b[0]
	mov	DWORD PTR -16[rbp], eax ; sets c[0] = eax = a[0] + b[0]
	mov	edx, DWORD PTR -28[rbp] ; sets edx = a[1] (bringing a[1] into a register so that the cpu can work on it)
	mov	eax, DWORD PTR -20[rbp] ; sets eax = b[1] (bringing b[1] into a register so that the cpu can work on it)
	add	eax, edx ; sets eax = eax + edx = a[1] + b[1]
	mov	DWORD PTR -12[rbp], eax ; sets c[1] = eax = a[1] + b[1]
Well thats a lot of instructions for adding just 2 pairs of numbers! Is it possible to do better than this?
The answer is yes*



THE CHEAT:

We are going to take advantage of two facts:
1] We are adding two pairs of 32 bit numbers
2] We have access to registers can handle 64 bit numbers
The setup for the cheat is simple, instead of loading a (similiarly b) into two seperate 32 bit registers, we will load it
into one single 64 bit register!
For this we need to see what the values of a were
a[0] = 12, which in hexadecimal is 0x0000000C
a[1] = 16, which in hexadecimal is 0x00000010
We will consider A = 0x000000100000000C, a 64 bit "number" which is really just a as a vector
Similiarly, for b:
b[0] = 14 = 0x0000000E
b[1] = 20 = 0x00000014 
Thus, B = 0x000000140000000E, a 64 bit "number" which is really just b as a vector

*/

int64_t A = 0x000000100000000C; // vector representation of a
int64_t B = 0x000000140000000E; // vector representation of b
int64_t C = A + B; // C vector = A vector + B vector
int32_t cOne = C>>32; //c[1] = the upper 32 bits of C vector
int32_t cZero = C^(0xFFFFFFFF00000000); // c[0] = the lower 32 bits of C vector
cout<<cZero<<" "<<cOne<<endl;
/*

Thats very weird looking isn't it?
Understanding what A and B are was weird already, what is '>>' and '^' doing?
Well the '>>' is a bitwise shift right operation, essentially we take whatever C was and 'shift' its bits, in this case by 32 bits = 8 hexadecimal places
for example, if C was 0x000000240000001A, shifting it right by 32 bits would make it 0x0000000000000024
The '^' is a bitwise xor operation, by feeding it  the weird looking value, it will preserve the lower 32 bits and make upper 32 bits 0
Thus we extract c[0] = a[0] + b[0] by looking at the lower 32 bits and c[1] = a[1] + b[1] by looking at upper 32 bits
This is what the generated assembly looks like:
	movabs	rax, 68719476748 ; move some absurd looking number (decimal representation of A vector) into a register
	mov	QWORD PTR -24[rbp], rax ; move the value in this register to A
	movabs	rax, 85899345934 ; move another weird number (decimal representation of B vector) into register
	mov	QWORD PTR -16[rbp], rax ; move the value in this register to B
	mov	rdx, QWORD PTR -24[rbp] ; move A to rdx, some register
	mov	rax, QWORD PTR -16[rbp] ; move B to rax, another register
	add	rax, rdx ; perform rax = rax + rdx = A + B
	mov	QWORD PTR -8[rbp], rax ; set C = rax = A + B
	mov	rax, QWORD PTR -8[rbp] ; set rax = C = A + B
	shr	rax, 32 ; perform rax = C>>32
	mov	DWORD PTR -32[rbp], eax ; set c[1] = eax = C>>32 (note eax and rax are the same thing :P)
	mov	rax, QWORD PTR -8[rbp] ; set rax = C
	mov	DWORD PTR -28[rbp], eax ; set c[0] = lower 32 bits of C
Well the clever among you will notice that we have moved backwards.
Instead of decreasing the number of instructions, the number of instructions has actually increased by one.
Why is that?
Its because we can directly set 32 bit values but we cannot directly set 64 bit values!
Hence why we must use the movabs instruction to go through a register intermediary
The shortcut however does actually take fewer instructions
Is it possible to enjoy the best of both worlds?

The answer in this case is YES!
We will take advantage of the fact that the present values can be represented as 16 bit numbers!
Thus, we can define A vector and B vector as 32 bit integers
We will define A = 0x0010000C and B = 0x0014000E
writing this in C++ looks like:

*/

int32_t aThirtyTwo = 0x0010000C;
int32_t bThirtyTwo = 0x0014000E;
int32_t cThirtyTwo = aThirtyTwo + bThirtyTwo;
int16_t cSixteenZero = cThirtyTwo ^ (0xFFFF0000);
int16_t cSixteenOne = cThirtyTwo>>16;
cout<<cSixteenZero<<" "<<cSixteenOne<<endl;
/*

The generated asm is one instruction shorter than our original asm, and looks like : 
	mov	DWORD PTR -12[rbp], 1048588 ; move some weird looking value (decimal representation of 0x0010000C) into A
	mov	DWORD PTR -8[rbp], 1310734 ; move another weird looking value (decimal representation of 0x0014000E) into B
	mov	edx, DWORD PTR -12[rbp] ; set edx = A
	mov	eax, DWORD PTR -8[rbp] ; set eax = B
	add	eax, edx ; set eax = eax + edx = A + B
	mov	DWORD PTR -4[rbp], eax ; set C = eax = A + B
	mov	eax, DWORD PTR -4[rbp] ; set eax = C
	mov	WORD PTR -16[rbp], ax ; set cSixteenZero = lower 16 bits of C
	mov	eax, DWORD PTR -4[rbp] ; set eax = C
	sar	eax, 16 ; set eax = upper 16 bits of eax
	mov	WORD PTR -14[rbp], ax ; set cSixteenOne = upper 16 bits of C
Insert Thanos Quote "All of this just for one less instruction"
Well the point isn't one less instruction, its pushing your CPU to its limits
Now you can clearly see that there are advantages and disadvantages to this entire process.

Advantages:

1] The actual computation occurs much faster : You can theoretically add upto 2 pairs of *positive* signed 32 bit 
integers using a single 64 bit register, 4 pairs of 16 bit, 8 pairs of 8 bit and so on

Disadvantages:

1]The loading of data is impractical: In this particular example, we know the data we are working with, however,
that is not always the case. In general, suppose we had 32 bit a[0],a[1], we would construct A (64 bit) = a[1]<<32 + a[0]
which would increase the number of instructions by quite a bit
2]Overflow values are scary: Its pretty clear that you need to ensure the values do not overflow as that would ruin the answer
3]Obtaining data after computation is bulky: Unvectorizing the data is very computationally expensive and requires several
shift right operations

Its clear that if there was hardware support for easy loading and unloading then this method could potentially be much faster
Well, there is hardware support! There are special instructions called SIMD instructions that use this method to further parallelize computation
But before we go into that, try making a vectorized implementation of the below computation 

*/

int32_t x[2] = {127,203};
int32_t y[2] = {155,201};
int32_t z[2];
z[0] = x[0] + y[0];
z[1] = x[1] + y[1];
cout<<z[0]<<" "<<z[1]<<endl;
/*

TASK:
MAKE A VECTORIZED IMPLEMENTATION OF ABOVE CODE

*/

//student code begin
cout<<"Task not completed!\n";
//student code end
}