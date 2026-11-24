cmake_minimum_required(VERSION 3.16)

project(simplefetch
    VERSION 0.1.0
    DESCRIPTION "Small system information fetcher"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Write build/compile_commands.json so clangd (Zed) resolves the include paths.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Every .c file under src/include is part of the build. CONFIGURE_DEPENDS makes
# CMake re-scan on each build, so new files are picked up without editing this
# file.
file(GLOB_RECURSE SIMPLEFETCH_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/include/*.c"
)

add_executable(simplefetch
    src/main.c
    ${SIMPLEFETCH_SOURCES}
)

target_include_directories(simplefetch PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/include"
)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(simplefetch PRIVATE -Wall -Wextra)
endif()
