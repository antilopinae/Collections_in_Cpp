cmake_minimum_required(VERSION 3.6)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

set(APP_DOMAIN ./lib)

include_directories(${APP_DOMAIN})

set(
        SOURCE_FILES
        main.cpp

        ArraySequence.h
        ArraySequence.cpp

        ListSequence.h
        ListSequence.cpp

        ${APP_DOMAIN}/Iterable.h

        ${APP_DOMAIN}/Collection.h

        ${APP_DOMAIN}/MutableIterable.h

        ${APP_DOMAIN}/MutableCollection.h

        ${APP_DOMAIN}/DynamicArray.h

        ${APP_DOMAIN}/MutableDynamicArray.h

        ${APP_DOMAIN}/LinkedList.h

        ${APP_DOMAIN}/MutableLinkedList.h

        ${APP_DOMAIN}/TypeObject.h

        ${APP_DOMAIN}/vector.h
        Testing.h
        Debugging.h
)

add_executable(untitled ${SOURCE_FILES})
