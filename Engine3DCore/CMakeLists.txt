cmake_minimum_required(VERSION 3.12)

set(ENGINE_PROJECT_NAME Engine3DCore)

set(ENGINE_PUBLIC_INCLUDES
	includes/Engine3DCore/Application.hpp
	includes/Engine3DCore/Log.hpp
	includes/Engine3DCore/Event.hpp
	includes/Engine3DCore/Camera.hpp
	includes/Engine3DCore/Keys.hpp
	includes/Engine3DCore/Input.hpp
)

set(ENGINE_PRIVATE_INCLUDES
	includes/Engine3DCore/Window.hpp
	src/Engine3DCore/Modules/UImodule.hpp
	src/Engine3DCore/Rendering/OpenGL/Renderer_OpenGL.hpp
	src/Engine3DCore/Rendering/OpenGL/ShaderProgram.hpp
	src/Engine3DCore/Rendering/OpenGL/VertexBuffer.hpp
	src/Engine3DCore/Rendering/OpenGL/VertexArray.hpp
	src/Engine3DCore/Rendering/OpenGL/IndexBuffer.hpp
)

set(ENGINE_PRIVATE_SOURCES
	src/Engine3DCore/Application.cpp
	src/Engine3DCore/Window.cpp
	src/Engine3DCore/Input.cpp
	src/Engine3DCore/Camera.cpp
	src/Engine3DCore/Modules/UImodule.cpp
	src/Engine3DCore/Rendering/OpenGL/Renderer_OpenGL.cpp
	src/Engine3DCore/Rendering/OpenGL/ShaderProgram.cpp
	src/Engine3DCore/Rendering/OpenGL/VertexBuffer.cpp
	src/Engine3DCore/Rendering/OpenGL/VertexArray.cpp
	src/Engine3DCore/Rendering/OpenGL/IndexBuffer.cpp
)

set(ENGINE_ALL_SOURCES
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

add_library(${ENGINE_PROJECT_NAME} STATIC
	${ENGINE_ALL_SOURCES}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES
	${ENGINE_ALL_SOURCES}
)

target_include_directories(${ENGINE_PROJECT_NAME} PUBLIC includes)
target_include_directories(${ENGINE_PROJECT_NAME} PRIVATE src)
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)


add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glfw)

add_subdirectory(../external/spdlog ${CMAKE_CURRENT_BINARY_DIR}/spdlog)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE spdlog)

add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glad)

add_subdirectory(../external/glm ${CMAKE_CURRENT_BINARY_DIR}/glm)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE glm)

set(IMGUI_INCLUDES
	../external/imgui/imgui.h
	../external/imgui/backends/imgui_impl_glfw.h
	../external/imgui/backends/imgui_impl_opengl3.h
)

set(IMGUI_SOURCES
	../external/imgui/imgui.cpp
	../external/imgui/backends/imgui_impl_glfw.cpp
	../external/imgui/backends/imgui_impl_opengl3.cpp
	../external/imgui/imgui_draw.cpp
	../external/imgui/imgui_tables.cpp
	../external/imgui/imgui_widgets.cpp
	../external/imgui/imgui_demo.cpp
)

add_library(ImGui STATIC
	${IMGUI_INCLUDES}
	${IMGUI_SOURCES}
)

target_include_directories(ImGui PUBLIC ../external)
target_include_directories(ImGui PUBLIC ../external/imgui)

target_link_libraries(ImGui PRIVATE glad glfw)
target_link_libraries(${ENGINE_PROJECT_NAME} PRIVATE ImGui)