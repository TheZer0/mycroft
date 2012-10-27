project(Mycroft)
cmake_minimum_required(VERSION 2.8)

if(UNIX)
    find_package(LibXml2)
    find_package(CURL)
endif()

add_subdirectory(src)
