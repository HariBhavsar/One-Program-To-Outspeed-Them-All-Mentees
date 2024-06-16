#include "opencl.hpp"
#include <iostream>

int main () {
	Device device(select_device_with_most_flops()); // compile OpenCL C code for the fastest available device

	const uint N = 1024u; // size of vectors

	Memory<float> A2(device, N); // allocate memory on both host and device
	Memory<float> B2(device, N);
	Memory<float> C2(device, N);

	Kernel mul_kernel(device, N, "mul_kernel", A2, B2, C2); // kernel that runs on the device

	for(uint n=0u; n<N; n++) {
		A2[n] = 3.0f; // initialize memory
		B2[n] = 2.0f;
		C2[n] = 1.0f;
	}

	std::cout<<"Printing value of C2 before multiplication : ";
	for (uint i=0u; i<N; i++) {
		std::cout<<C2[i]<<" ";
	}
	std::cout<<std::endl;

    auto start = std::chrono::high_resolution_clock::now();

	// TASK 1 CODE BEGINS HERE
	std::cout<<"STUDENT CODE FOR TASK 1 NOT IMPLEMENTED\n";
	wait();
	exit(1);
	// TASK 1 CODE ENDS HERE
    
    auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

	std::cout<<"Vector element wise multiplication done, printing value of C2 : ";
	for (uint i=0u; i<N; i++) {
		std::cout<<C2[i]<<" ";
	} 
	std::cout<<std::endl;
    
	std::cout << "(openCL implementation) Time taken : " << elapsed.count() << "\n";
	
    // wait();
    return 0;

}