cmake_minimum_required(VERSION 3.10)

project(Mediator)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE MEDIATOR_HEADERS "mediator/*.h")
file(GLOB_RECURSE MEDIATOR_SOURCES "mediator/*.cpp")

add_executable(Mediator ${MEDIATOR_HEADERS} ${MEDIATOR_SOURCES})

project(Observer)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE OBSERVER_HEADERS "observer/*.h")
file(GLOB_RECURSE OBSERVER_SOURCES "observer/*.cpp")

add_executable(Observer ${OBSERVER_HEADERS} ${OBSERVER_SOURCES})
target_link_libraries(Observer pthread)