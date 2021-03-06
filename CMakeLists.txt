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

project(Singleton)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE SINGLETON_HEADERS "singleton/*.h")
file(GLOB_RECURSE SINGLETON_SOURCES "singleton/*.cpp")

add_executable(Singleton ${SINGLETON_HEADERS} ${SINGLETON_SOURCES})

project(Factory)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE FACTORY_HEADERS "factory/*.h")
file(GLOB_RECURSE FACTORY_SOURCES "factory/*.cpp")

add_executable(Factory ${FACTORY_HEADERS} ${FACTORY_SOURCES})

project(Adapter)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE ADAPTER_HEADERS "adapter/*.h")
file(GLOB_RECURSE ADAPTER_SOURCES "adapter/*.cpp")

add_executable(Adapter ${ADAPTER_HEADERS} ${ADAPTER_SOURCES})

project(Memento)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE MEMENTO_HEADERS "memento/*.h")
file(GLOB_RECURSE MEMENTO_SOURCES "memento/*.cpp")

add_executable(Memento ${MEMENTO_HEADERS} ${MEMENTO_SOURCES})

target_link_libraries(Observer pthread)