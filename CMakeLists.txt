set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
cmake_minimum_required(VERSION 3.18)

set(UI_PROJECT "UI")

project(${UI_PROJECT} CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Vulkan REQUIRED)

if(MSVC)
    set(CMAKE_GENERATOR_PLATFORM ${CMAKE_VS_PLATFORM_NAME})
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_DEBUG_POSTFIX "" CACHE BOOL "" FORCE)
set(LIBRARY_SUFFIX "" CACHE BOOL "" FORCE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_GENERATOR_PLATFORM})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_GENERATOR_PLATFORM})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_GENERATOR_PLATFORM})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_GENERATOR_PLATFORM})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_GENERATOR_PLATFORM})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_GENERATOR_PLATFORM})

file(
    GLOB_RECURSE UI_BINS_LIST
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/bins/*.*"
)

file(
    GLOB_RECURSE UI_LIBS_LIST
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libs/*.*"
)

foreach (BIN_FILE ${UI_BINS_LIST})
    get_filename_component(BIN_NAME "${BIN_FILE}" NAME)
    file(COPY_FILE ${BIN_FILE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}${BIN_NAME} ONLY_IF_DIFFERENT)
endforeach()

foreach (LIB_FILE ${UI_LIBS_LIST})
    get_filename_component(LIB_NAME "${LIB_FILE}" NAME)
    file(COPY_FILE ${LIB_FILE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}${LIB_NAME} ONLY_IF_DIFFERENT)
endforeach()

file(
    GLOB_RECURSE UI_CODE_LIST
    LIST_DIRECTORIES false
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c*"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/ui/*.h*"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/ui/*.inl"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui_draw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui_internal.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui_widgets.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/imgui_tables.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/backends/imgui_impl_glfw.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/backends/imgui_impl_glfw.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/backends/imgui_impl_vulkan.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui/backends/imgui_impl_vulkan.h"
)

add_library(${UI_PROJECT} SHARED ${UI_CODE_LIST})

target_link_libraries(${UI_PROJECT} ${UI_BINS_LIST} ${Vulkan_LIBRARIES})
target_include_directories(${UI_PROJECT} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include/imgui
    ${Vulkan_INCLUDE_DIRS})

foreach(CODE_FILE IN ITEMS ${UI_CODE_LIST})
    get_filename_component(CODE_FILE_PATH "${CODE_FILE}" PATH)
    file(RELATIVE_PATH CODE_FILE_RELATIVE_PATH "${CMAKE_SOURCE_DIR}" "${CODE_FILE_PATH}")
    string(REPLACE "\\" "/" GROUP_PATH "${CODE_FILE_RELATIVE_PATH}")
    file(RELATIVE_PATH EXTERNAL_INCLUDE_RELATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/include")
    string(REPLACE ${EXTERNAL_INCLUDE_RELATIVE_PATH} "" GROUP_PATH "${GROUP_PATH}")
    string(REPLACE "src" "" GROUP_PATH "${GROUP_PATH}")
    string(REPLACE "include/ui" "" GROUP_PATH "${GROUP_PATH}")
    source_group("${GROUP_PATH}" FILES "${CODE_FILE}")
endforeach()

if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Engine)
endif()
