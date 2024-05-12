cmake_minimum_required(VERSION 3.6)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

set(APP_DOMAIN ./lib)
set(SRC_DOMAIN ./lib/src)

include_directories(${APP_DOMAIN})
include_directories(${SRC_DOMAIN})

set(
        SOURCE_FILES
        main.cpp

        ArraySequence.h
        ArraySequence.cpp

        ListSequence.h
        ListSequence.cpp

        ${APP_DOMAIN}/Iterable.h
        ${SRC_DOMAIN}/Iterable.cpp

        ${APP_DOMAIN}/Collection.h
        ${SRC_DOMAIN}/Collection.cpp

        ${APP_DOMAIN}/MutableIterable.h
        ${SRC_DOMAIN}/MutableIterable.cpp

        ${APP_DOMAIN}/MutableCollection.h
        ${SRC_DOMAIN}/MutableCollection.cpp

        ${APP_DOMAIN}/DynamicArray.h
        ${SRC_DOMAIN}/DynamicArray.cpp

        ${APP_DOMAIN}/MutableDynamicArray.h
        ${SRC_DOMAIN}/MutableDynamicArray.cpp

        ${APP_DOMAIN}/LinkedList.h
        ${SRC_DOMAIN}/LinkedList.cpp

        ${APP_DOMAIN}/MutableLinkedList.h
        ${SRC_DOMAIN}/MutableLinkedList.cpp

)
add_executable(untitled ${SOURCE_FILES})
