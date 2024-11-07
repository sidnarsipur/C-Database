cmake_minimum_required(VERSION 3.26)
project(Database C)

set(CMAKE_C_STANDARD 99)

add_executable(Database
        SNAP.c
        SNAP.h
        string-extras.c
        CSG.c
        CSG.h
        CP.c
        CP.h
        CDH.c
        CDH.h
        CR.c
        CR.h
        main.c
        Database.c
        Database.h
        SNAPCG.c
        SNAPCG.h)
