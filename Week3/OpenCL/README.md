# openCL
- Note : This will not work on apple silicon! If you have a macbook with an M1/M2/M3/M4 then you should not even attempt to do this section
### Setup
- Setting up openCL is highly non-trivial and to be honest, its quite hard
- Note : OpenCL DOES NOT WORK on WSL, you must be using either linux on a VM (preferrably Ubuntu 22.04 but any linux distro should be fine) OR dual boot (to be honest this is ideal, but way too much mehnat)
- If you do use openCL on WSL you will end up with very pretty looking error messages and it will never work
- Instructions for installing Ubuntu on a VM are here `https://ubuntu.com/tutorials/how-to-run-ubuntu-desktop-on-a-virtual-machine-using-virtualbox#1-overview`
- Now I'm gonna assume that you are on a VM or have dual booted linux, congratulations! 
- If you have an intel GPU (that is, an integrated graphics card, for example UHD or iris XE or ig arc too?) then you simply have to run `bash script1.sh` in the terminal followed by `bash script2.sh` and that should set up openCL
- If you have a dedicated GPU, congratulations, you should be able to take full advantage of openCL, follow the instructions on `https://github.com/ProjectPhysX/FluidX3D/blob/master/DOCUMENTATION.md#0-intstall-gpu-drivers-and-opencl-runtime`, (go to the top of the page and expand Section 0 : `Intstall GPU Drivers and OpenCL Runtime`) first run the instructions for your GPU and after that run the instructions for installation on CPU, it should work
- Confirm your installation by running `sudo apt install clinfo && clinfo`, the output should be something along the lines of `found x devices` and not `no openCL runtime found!`
### Getting started
- Ok, you successfully setup openCL, good job, I'm proud of you, now we're going to be working with an altered version of the `OpenCL-Wrapper`, created by `ProjectPhysX`, without him, even setting up openCL would have been impossible, so full credit for this part of the SoC goes to him
- The reason is that openCL by default is very verbose and has a very cumbersome syntax, this section is simply going to highlight a very simple work case of openCL and we will only touch upon the very top of the iceberg
- Its a very powerfull tool and we highly recommend exploring it further in your own time
- We will be working with just two `.cpp` files, `OpenCL-Wrapper/OpenCL-Wrapper/src/main.cpp` and `OpenCL-Wrapper/OpenCL-Wrapper/src/kernel.cpp` 
- `main.cpp` contains the so-called driver code, it is the brains of the operation, allocating resources to the most powerful device available
- Go through `main.cpp` which currently contains a very simple 1024-dimensional vector addition and understand how resources for this addition are allocated, I have also added explanation for what things do
- Go through `kernel.cpp` where a simple code for addition is written
### Task 1
- Understand the vector addition mechanics and write code to do element-wise vector multiplication
- Make the appropriate changes in `main.cpp` and in `kernel.cpp`
- Post the time difference you get on whatsapp (naive will be faster here, don't worry)
### Task 2
- Write an implementation of matrix multiplication by making appropriate changes in `main.cpp` and `kernel.cpp`
- I swear this is the last unique matrix multiplication implementation you will be doing lol
- Post the speedup you get on whatsapp (Depending on your environment, openCL implementation could be around 20 times faster)
### Theory
- Speculate on why naive is (or at least should be), about 50-100 times faster in vector addition and element-wise multiplication 
- Hint : It has to do with device interconnects/bus
- Post your speculation on whatsapp