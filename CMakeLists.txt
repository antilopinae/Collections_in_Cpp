cmake_minimum_required(VERSION 3.6)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

set(APP_DOMAIN ./lib)

include_directories(${APP_DOMAIN})

set(
        SOURCE_FILES

        main.cpp
        Testing.h
        Debugging.h
        MutableStack.h

        ${APP_DOMAIN}/Sequence.h

        ${APP_DOMAIN}/DynamicArray.h

        ${APP_DOMAIN}/LinkedList.h

        ${APP_DOMAIN}/MutableListSequence.h

        ${APP_DOMAIN}/ArraySequence.h

        ${APP_DOMAIN}/TypeObject.h

        ${APP_DOMAIN}/VectorList.h
        lib/DynamicArray.h
)

add_executable(untitled ${SOURCE_FILES})
