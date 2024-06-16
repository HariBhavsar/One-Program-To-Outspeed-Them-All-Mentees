#include <iostream>
#include <chrono>

int main(){
    __uint128_t N = 1024;
    float* A = new float[N*N];
    float* B = new float[N*N];
    float* C = new float[N*N];
    for (int i = 0 ; i < N ; i++){
        for (int j=0; j<N; j++) {
            A[i*N + j] = i;
            B[i*N + j] = j;
            C[i*N + j] = 0;
        }
    }

	auto start = std::chrono::high_resolution_clock::now();

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                C[i*N + j] += A[i*N + k]*B[k*N+j];
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
	std::cout<<"Matrix multiplication done, printing value of C : ";
	for (uint i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
            std::cout<<C[i*N+j]<<" ";
        }
        std::cout<<std::endl;
	} 
	std::cout<<std::endl;
	auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
	std::cout << "(naive implementation) Time taken : " << elapsed.count() << "\n";
    delete [] C;
    delete [] B;
    delete [] A;
}