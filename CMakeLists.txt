project(complex)
cmake_minimum_required(VERSION 3.16)

aux_source_directory(./src DIR_SRCS)
add_executable(main ${DIR_SRCS})
