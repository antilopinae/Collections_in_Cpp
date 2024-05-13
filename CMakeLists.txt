cmake_minimum_required(VERSION 3.6)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

set(APP_DOMAIN ./lib)

include_directories(${APP_DOMAIN})

set(
        SOURCE_FILES
        main.cpp

        ArraySequence.h

        MutableListSequence.h

        ${APP_DOMAIN}/Iterable.h

        ${APP_DOMAIN}/Collection.h

        ${APP_DOMAIN}/DynamicArray.h

        ${APP_DOMAIN}/MutableLinkedList.h

        ${APP_DOMAIN}/TypeObject.h

        ${APP_DOMAIN}/vector.h
        Testing.h
        Debugging.h
        lib/MutableLinkedList.h
)

add_executable(untitled ${SOURCE_FILES})
