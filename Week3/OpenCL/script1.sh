sudo apt update
sudo apt upgrade -y
sudo apt install -y ocl-icd-libopencl1 ocl-icd-opencl-dev intel-opencl-icd
sudo usermod -a -G render $(whoami)
sudo shutdown -r now
