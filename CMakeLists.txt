cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Engine3D)

add_subdirectory(Engine3DCore)
add_subdirectory(Engine3DEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Engine3DEditor)