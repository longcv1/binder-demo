# binder-demo

# Prerequisites:
- Linux kernel version >= 5.0.0
- Cmake version >= 3.0
- Gcc/G++ to compile C++ 11 or above

# My envinonment:
- Ubuntu 22.04.2 LTS
- gcc 11.4.0
- Kernel version: 6.2.0-34-generic

# I. Enable binder driver.
Step 1: Load the kernel modules:
- sudo modprobe binder_linux

Step 2: Mount binderfs
- sudo mkdir /dev/binderfs
- sudo mount -t binder binder /dev/binderfs
=> After those steps, it should present in /dev/binderfs/

# II. Build
- mkdir build/
- cd build/
- cmake ../src
- make

# III. Create binder device
- stay in folder /build
- run command: sudo ./binder-control/binder_control /dev/binderfs/binder-control my-binder

# IV. Start service manager
- stay in folder /build
- run command: ./servicemanager/service_manager &

# V. Run test on VSCode terminal or run on 2 terminals
- ./test_service/test_server
- ./test_service/test_client
=> Should see test_client prints messages to stdout.

# Ref:
Sources may from those links:
- https://github.com/hungys/binder-for-linux
- https://github.com/hiking90/binder-linux
- https://github.com/anthann/binder-for-linux-kernel-5
