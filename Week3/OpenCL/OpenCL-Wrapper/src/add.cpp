#include "opencl.hpp"
#include <iostream>
#include <chrono>
int main() {
	Device device(select_device_with_most_flops()); // compile OpenCL C code for the fastest available device

	const uint N = 1024u; // size of vectors
	Memory<float> A(device, N); // allocate memory on both host and device
	Memory<float> B(device, N);
	Memory<float> C(device, N);

	Kernel add_kernel(device, N, "add_kernel", A, B, C); // kernel that runs on the device

	for(uint n=0u; n<N; n++) {
		A[n] = 3.0f; // initialize memory
		B[n] = 2.0f;
		C[n] = 1.0f;
	}

	std::cout<<"Printing value of C before addition : ";
	for (uint i=0u; i<N; i++) {
		std::cout<<C[i]<<" ";
	}
	std::cout<<std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	A.write_to_device(); // copy data from host memory to device memory
	B.write_to_device();
	add_kernel.run(); // run add_kernel on the device
	C.read_from_device(); // copy data from device memory to host memory
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	
	std::cout<<"Vector addition done, printing value of C : ";
	for (uint i=0u; i<N; i++) {
		std::cout<<C[i]<<" ";
	} 
	std::cout<<std::endl;
	std::cout << "(openCL implementation) Time taken : " << elapsed.count() << "\n";
	// wait();
	
	return 0;
}
