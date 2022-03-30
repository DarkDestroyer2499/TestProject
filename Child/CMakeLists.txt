cmake_minimum_required(VERSION 3.12)

project(child VERSION 1.0.0)

add_executable(child main.cpp IFileSaver.h FileSaver.h FileSaver.cpp)
