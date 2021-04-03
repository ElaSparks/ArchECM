cmake_minimum_required(VERSION 3.12.1)
project(ArchECM)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

add_executable(ArchECM src/main.cpp src/MyTerm.cpp include/MyTerm.h src/MyBigChars.cpp include/MyBigChars.h src/bigCharInit.cpp src/MyReadKey.cpp include/MyReadKey.h src/TermRegime.cpp src/TermSaveNRestore.cpp)