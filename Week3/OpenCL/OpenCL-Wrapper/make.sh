mkdir -p bin # create directory for executable
rm -f ./bin/OpenCL-Wrapper # prevent execution of old version if compiling fails
g++ ./src/add.cpp ./src/kernel.cpp -o ./bin/add -std=c++17 -pthread -I./src/OpenCL/include -L./src/OpenCL/lib -lOpenCL # compile on Linux
g++ ./src/mul.cpp ./src/kernel.cpp -o ./bin/mul -std=c++17 -pthread -I./src/OpenCL/include -L./src/OpenCL/lib -lOpenCL
g++ ./src/matMul.cpp ./src/kernel.cpp -o ./bin/matMul -std=c++17 -pthread -I./src/OpenCL/include -L./src/OpenCL/lib -lOpenCL
g++ ./naive/add.cpp -o ./naive/add
g++ ./naive/mul.cpp -o ./naive/mul
g++ ./naive/matMul.cpp -o ./naive/matMul
#g++ ./src/*.cpp -o ./bin/OpenCL-Wrapper -std=c++17 -pthread -I./src/OpenCL/include -framework OpenCL # compile on macOS
#g++ ./src/*.cpp -o ./bin/OpenCL-Wrapper -std=c++17 -pthread -I./src/OpenCL/include -L/system/vendor/lib64 -lOpenCL # compile on Android
./bin/add
./naive/add
./bin/mul
./naive/mul
./bin/matMul
./naive/matMul
