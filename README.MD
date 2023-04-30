# undercov

<p align="center">
    <img src="https://img.shields.io/badge/gcc-8.2.0-brightgreen.svg">
    <img src="https://img.shields.io/badge/gcc-9.4.0-brightgreen.svg">
</p>

## Intro

undercov is a light-weighted instrumentation tool designed for the deep learning library.

It contains 3 main librarys:

- `libundercov_ins.so`: a gcc plugin that inserts basic block hooks into target.

- `libundercov_trace.so`: a dynamic library contains implements for the hooks inserted by libundercov_ins.so.

- `libundercov_info.so`: a dynamic library used to get the hit cnts of basic blocks, which can be used in python for faster call.

## Install

### Prerequst

#### Python 3.9 or later

#### compile gcc 9.4.0 from source

You should first install gcc 9.4.0 from source to obtain the plugin support.
Version `9.4.0` is important because gcc changes its apis frequetly.

1. download gcc 9.4.0 source code. 
```bash
# this is an example method
wget -c https://github.com/gcc-mirror/gcc/archive/refs/tags/releases/gcc-9.4.0.tar.gz

# or you can try https://mirrors.tuna.tsinghua.edu.cn/gnu/gcc/gcc-9.4.0/gcc-9.4.0.tar.gz

tar -zxf gcc-9.4.0.tar.gz
```

2. let gcc download prerequets itself
```bash
cd gcc-9.4.0
./contrib/download_prerequisites
```

3. compile
```bash
# outside gcc source dir
mkdir gcc_build
cd gcc_build
../gcc-9.4.0/configure --prefix=<path you like>/gcc_install --enable-languages=c,c++ --disable-multilib
make
make install
```

4. go find your gcc at `path you like/gcc_install`

#### install some libs

Then you should install gmp.
```bash
#CentOs
yum install libgmp3-dev
 
#Ubuntu
apt-get install libgmp3-dev
 
#Mac OS
brew install gmp
```

### Ready to go
This project is managed by CMake so you can do what most CMake does.

At first edit the undercov/CMakeLists.txt, and change the `GCC_DIR` to `path you like/gcc_install`, and then

```bash
mkdir build 
cd build 
cmake ..
make
make install
```

## Demo

This project contains a demo in `build/test`.

```bash
cd build/test

# in one terminal
python coverage.py

# in another terminal
./undercov_test
```

For the python terminal, you will get something like:

```bash
root@a154aa72e200:~/undercov/build/test# python coverage.py 
Current bb cnt is 0
Current bb cnt is 0
...
Current bb cnt is 0
Current bb cnt is 16
Current bb cnt is 16
```

For the `undercov_test` terminal, you will get something like:

```bash
Basic block 2364 was executed.
Basic block 2593 was executed.
Basic block 2959 was executed.
...
Basic block 407 was executed.
```

In a practical situation, the instrumentation should not print any information, so you need to turn off the debug mode in the top `CMakeLists.txt`

```
# comment this line
add_definitions(-DUNDERCOV_DEBUG)
```

## Usage

1. Add `-fplugin=libundercov_ins.so` to your c compile options.

2. Add `-lundercov_trace -lrt` to your link options.

3. Start the `undercov_ins_server` before you instrumenting anything.

```bash
cd instrument
./undercov_ins_server
root@7c16b7f0aa67:~/undercov/build/instrument# ./undercov_ins_server 
undercov currently has inserted 0 blocks
undercov currently has inserted 0 blocks
...
^C
undercov totally inserts XX blocks
```

> Those above make sense only when you finished `make install`
