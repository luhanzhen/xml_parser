cmake_minimum_required(VERSION 3.22)
project(XmlParser)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(XmlParser src/main.cpp src/Timer.h src/Files.h src/xmlElement.h src/xmlDoc.h)
