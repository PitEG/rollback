cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

set(ROLLBACK_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

# find_package(asio REQUIRED)
# message("found asio")
# include_driectores(${ASIO_INCLUDE_DIRS})

project(rollback)

add_subdirectory(src)
add_subdirectory(sandbox)


