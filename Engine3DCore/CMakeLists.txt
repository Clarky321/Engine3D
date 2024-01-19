cmake_minimum_required(VERSION 3.12)

set(ENGINE_PROJECT_NAME Engine3DCore)

add_library(${ENGINE_PROJECT_NAME} STATIC
	src/Engine3DCore/Utils/test.cpp
	includes/Engine3DCore/Utils/test.hpp
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)