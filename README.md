# PD_final_project

hf_class_merge:
Here we put all class into same header file and compile.
clang++ -o final main.cpp Class.cpp
./final

hf_class_sep:
Here we put all class into different header files and compile.
clang++ -o test main.cpp Cell.cpp Entity.cpp Fire.cpp Game.cpp Ice.cpp Money.cpp Position.cpp Utils.cpp Wall.cpp
./test