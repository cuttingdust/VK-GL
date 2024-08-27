cmake_minimum_required(VERSION 3.12)

# 使用 vcpkg 工具链文件
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_GENERATOR_PLATFORM x64)

project(VK-GL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug) 

# 查找 vcpkg 安装的库 
find_package(glfw3 CONFIG REQUIRED) 
find_package(glm CONFIG REQUIRED) 
find_package(Vulkan REQUIRED) 
message("Found glad: ${Vulkan_VERSION}")
message("Found glfw: ${glfw3_VERSION}") 

aux_source_directory(./src SRC)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glm::glm)
target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)
