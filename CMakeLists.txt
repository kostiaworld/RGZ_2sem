cmake_minimum_required(VERSION 3.26)
project(RGZ_2ssem)

set(CMAKE_CXX_STANDARD 20)

add_executable(RGZ_2ssem main.cpp
        cipher_Hill.cpp
        cipher_Polybius_Square.cpp
        cipher_Vigener.cpp
        fool_test.cpp
        Menu_system_code.cpp
        Preparation_for_cipher.cpp
        Read_write_control.cpp
        System_security_check.cpp)
