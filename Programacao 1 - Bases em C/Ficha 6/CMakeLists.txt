cmake_minimum_required(VERSION 3.24)
project(ficha6)
 
# Our Project
set(SOURCE_FILES
    Main.c
    funcoes_reservas.c)
 
add_executable(${PROJECT_NAME} ${SOURCE_FILES})