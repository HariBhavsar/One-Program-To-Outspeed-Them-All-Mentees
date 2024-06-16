#include "opencl.hpp"
#include <iostream>

int main () {
    Device device (select_device_with_most_flops());
    const uint N = 1024;
    Memory<float> A3(device,N*N); // A3 is a N*N matrix
	Memory<float> B3(device,N*N); // B3 is a N*N matrix
	Memory<float> C3(device,N*N); // C3 is a N*N matrix, C3 = A3*B3
	
	Kernel matMul(device,N*N,"matMul",A3,B3,C3,N,N,N);
	
	for (uint i = 0; i < N; i++) {
		for (uint j=0; j<N; j++) {
			A3[i*N + j] = i;
			B3[i*N + j] = j;
			C3[i*N + j] = 0;
		}
	}
    auto start = std::chrono::high_resolution_clock::now();

	// TASK 2 CODE BEGINS HERE
	std::cout<<"Task 2 code not implemented!\n";
	wait();
	exit(1);
	// TASK 2 CODE ENDS HERE

    auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

	std::cout<<"C3 is : "<<"\n";
	for (uint i = 0; i < N; i++) {
		for (uint j=0; j<N; j++) {
			std::cout<<C3[i*N + j]<<" ";	
		}
		std::cout<<"\n";
	}	

    std::cout << "(openCL implementation) Time taken : " << elapsed.count() << "\n";

    // wait();
    return 0;
}