sudo apt update
sudo apt upgrade -y
sudo apt install -y ocl-icd-libopencl1 ocl-icd-opencl-dev
mkdir -p ~/cpuruntime && cd $_
wget https://github.com/intel/llvm/releases/download/2024-WW14/oclcpuexp-2024.17.3.0.09_rel.tar.gz
wget https://github.com/oneapi-src/oneTBB/releases/download/v2021.12.0/oneapi-tbb-2021.12.0-lin.tgz
sudo mkdir -p /opt/intel/oclcpuexp_2024.17.3.0.09_rel && cd $_
sudo tar -zxvf ~/cpuruntime/oclcpuexp-*.tar.gz
sudo mkdir -p /etc/OpenCL/vendors
echo "/opt/intel/oclcpuexp_2024.17.3.0.09_rel/x64/libintelocl.so" | sudo tee /etc/OpenCL/vendors/intel_expcpu.icd
cd /opt/intel
sudo tar -zxvf ~/cpuruntime/oneapi-tbb-*-lin.tgz
sudo ln -s /opt/intel/oneapi-tbb-2021.12.0/lib/intel64/gcc4.8/libtbb.so /opt/intel/oclcpuexp_2024.17.3.0.09_rel/x64
sudo ln -s /opt/intel/oneapi-tbb-2021.12.0/lib/intel64/gcc4.8/libtbbmalloc.so /opt/intel/oclcpuexp_2024.17.3.0.09_rel/x64
sudo ln -s /opt/intel/oneapi-tbb-2021.12.0/lib/intel64/gcc4.8/libtbb.so.12 /opt/intel/oclcpuexp_2024.17.3.0.09_rel/x64
sudo ln -s /opt/intel/oneapi-tbb-2021.12.0/lib/intel64/gcc4.8/libtbbmalloc.so.2 /opt/intel/oclcpuexp_2024.17.3.0.09_rel/x64
sudo mkdir -p /etc/ld.so.conf.d
echo "/opt/intel/oclcpuexp_2024.17.3.0.09_rel/x64" | sudo tee /etc/ld.so.conf.d/libintelopenclexp.conf
sudo ldconfig -f /etc/ld.so.conf.d/libintelopenclexp.conf
rm -r ~/cpuruntime
sudo shutdown -r now
