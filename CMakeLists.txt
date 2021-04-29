cmake_minimum_required(VERSION 3.12.1)
project(ArchECM)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

add_executable(ArchECM
        src/main.cpp
        src/TermSource/TermDesign.cpp
        include/TermDesign.h
        src/BigCharSouce/BigChars.cpp
        include/BigChars.h
        src/BigCharSouce/BigCharInit.cpp
        src/TermSource/MyReadKey.cpp
        include/MyReadKey.h
        src/TermSource/TermRegime.cpp
        src/TermSource/TermSaveNRestore.cpp
        src/SimpleComputerSource/MySimpleComputer.cpp
        include/MySimpleComputer.h
        src/SimpleComputerSource/SimpleComputerMemory.cpp
        src/ALU/ALURegNAccumHandler.cpp
        src/GUI/GUIBigChar.cpp
        src/GUI/GUIFrames.cpp
        src/MainActivity.cpp
        src/GUI/GUIFlags.cpp
        src/GUI/GUIMemory.cpp
        src/GUI/GUIAll.cpp
        src/SignalSource/Signals.cpp
        src/GUI/GUIAccumulator.cpp
        src/ALU/ArithmeticLogicUnit.cpp
        include/ArithmeticLogicUnit.h
        src/TermSource/TermEcho.cpp
        src/ALU/ALUEncDecCommands.cpp
        src/ALU/ALUMemoryHandler.cpp
        src/ALU/Commands/ALUIO.cpp
        src/ALU/Commands/ALULoadNStore.cpp
        src/ALU/Commands/ALUArithmetic.cpp
        src/ALU/Commands/ALUControlTransfer.cpp
        src/ALU/ControlUnit.cpp
        src/Encode/TranslateASM.cpp
        src/Encode/TranslateBAS.cpp
        src/Encode/BasicHandler/LetterEncode.cpp
        src/Encode/BasicHandler/JuxtaposeCode.cpp
        src/TermSource/TermScreenSize.cpp
        src/TermSource/TermColors.cpp
        src/GUI/GUINames.cpp
        src/GUI/GUIOperation.cpp
        src/GUI/GUIInstruction.cpp src/ALU/Commands/ALUMovEax.cpp)