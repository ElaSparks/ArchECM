cmake_minimum_required(VERSION 3.12.1)
project(ArchECM)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

add_executable(ArchECM
        src/main.cpp
        src/TermSource/MyTerm.cpp
        include/MyTerm.h
        src/BigCharSouce/MyBigChars.cpp
        include/MyBigChars.h
        src/BigCharSouce/bigCharInit.cpp
        src/TermSource/MyReadKey.cpp
        include/MyReadKey.h
        src/TermSource/TermRegime.cpp
        src/TermSource/TermSaveNRestore.cpp
        src/SimpleComputerSource/MySimpleComputer.cpp
        include/MySimpleComputer.h
        src/SimpleComputerSource/SimpleComputerMemory.cpp
        src/SimpleComputerSource/SimpleComputerHandler.cpp
        src/GUI/GUIBigChar.cpp
        src/GUI/GUIFramesNNames.cpp
        src/MainActivity.cpp
        src/GUI/GUIFlagsNInstruction.cpp
        src/GUI/GUIMemory.cpp
        src/GUI/GUIAll.cpp src/SignalSource/Signals.cpp)