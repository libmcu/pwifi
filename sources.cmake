# SPDX-License-Identifier: MIT

if(TARGET_PLATFORM STREQUAL esp32)
	list(APPEND PWIFI_SRCS ${CMAKE_CURRENT_LIST_DIR}/src/esp32.c)
elseif(TARGET_PLATFORM STREQUAL zephyr)
	list(APPEND PWIFI_SRCS ${CMAKE_CURRENT_LIST_DIR}/src/zephyr.c)
else()
	message(WARN "No target specified. Building with dummy target")
	list(APPEND PWIFI_SRCS ${CMAKE_CURRENT_LIST_DIR}/src/dummy.c)
endif()

list(APPEND PWIFI_INCS ${CMAKE_CURRENT_LIST_DIR}/include)
