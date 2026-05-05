cmake_minimum_required(VERSION 4.0)
project(Cozy2DMultiplayerGame)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)

set(AG_ENGINE_DIR "C:\\Users\\Reall\\Desktop\\Vulkan")

find_package(Vulkan REQUIRED)

add_subdirectory(lib/glfw)
SET(GLM_TEST_ENABLE OFF CACHE BOOL "GLM Build unit tests")
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

include_directories(${AG_ENGINE_DIR}/include)
include_directories(${AG_ENGINE_DIR}/lib/glm)
include_directories(${AG_ENGINE_DIR}/lib)


add_executable(Cozy2DMultiplayerGame
        src/main.cpp
        ${AG_ENGINE_DIR}/src/window.cpp
        ${AG_ENGINE_DIR}/src/logger.cpp
        ${AG_ENGINE_DIR}/src/vertexInfo.cpp
        ${AG_ENGINE_DIR}/src/entity.cpp
        ${AG_ENGINE_DIR}/src/texture.cpp
        ${AG_ENGINE_DIR}/src/depthBuffer.cpp
        ${AG_ENGINE_DIR}/src/math.cpp
)

target_compile_definitions(Cozy2DMultiplayerGame PRIVATE DEBUG=1)

target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)