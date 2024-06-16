#include <iostream>
#include <chrono>

int main(){
    __uint128_t N = 1024;
    float* A = new float[N];
    float* B = new float[N];
    float* C = new float[N];
    for (int i = 0 ; i < N ; i++){
        A[i] = 3.0;
        B[i] = 2.0;
        C[i] = 1.0;
    }
	std::cout<<"Printing value of C before addition : ";
	for (uint i=0u; i<N; i++) {
		std::cout<<C[i]<<" ";
	}
	std::cout<<std::endl;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0 ; i < N ; i++) C[i] = A[i] * B[i];
    auto end = std::chrono::high_resolution_clock::now();
	std::cout<<"Vector multiplication done, printing value of C : ";
	for (uint i=0u; i<N; i++) {
		std::cout<<C[i]<<" ";
	} 
	std::cout<<std::endl;
	auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	std::cout << "(naive implementation) Time taken : " << elapsed.count() << "\n";
    delete [] C;
    delete [] B;
    delete [] A;
}