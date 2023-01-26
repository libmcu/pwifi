# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.16)

project(pwifi LANGUAGES C CXX)

include(${CMAKE_CURRENT_LIST_DIR}/sources.cmake)

if(NOT DEFINED TARGET_PLATFORM)
	set(TARGET_PLATFORM dummy)
endif()

add_library(${PROJECT_NAME} STATIC ${PWIFI_SRCS})
target_compile_features(${PROJECT_NAME} PRIVATE c_std_99)
target_include_directories(${PROJECT_NAME} PUBLIC ${PWIFI_INCS})
target_compile_definitions(${PROJECT_NAME} PUBLIC
	TARGET_PLATFORM=${TARGET_PLATFORM}
)
