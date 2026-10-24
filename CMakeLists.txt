cmake_minimum_required(VERSION 3.20)
project(patronesDisenio LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ejercicio1
    ejercicio1/main.cpp
    ejercicio1/Account.cpp
    ejercicio1/Transaction.cpp
    ejercicio1/TransactionManager.cpp
)
target_include_directories(ejercicio1 PRIVATE ejercicio1)

find_package(Threads REQUIRED)
target_link_libraries(ejercicio1 PRIVATE Threads::Threads)

add_executable(ejercicio2
    ejercicio2/main.cpp
    ejercicio2/OpenGLFactory.cpp
    ejercicio2/VulkanFactory.cpp
)
target_include_directories(ejercicio2 PRIVATE ejercicio2)

add_executable(ejercicio3
        ejercicio3/main_3.cpp
        ejercicio3/Expression.cpp
        ejercicio3/Expression.h
)
target_include_directories(ejercicio3 PRIVATE ejercicio3)

add_executable(ejercicio4
        ejercicio4/main_4.cpp
        ejercicio4/Graph.h
        ejercicio4/Graph.cpp
)
target_include_directories(ejercicio3 PRIVATE ejercicio3)