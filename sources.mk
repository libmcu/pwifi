# SPDX-License-Identifier: MIT

ifneq ($(PWIFI_ROOT),)
pwifi-basedir := $(PWIFI_ROOT)/
endif

ifeq ($(TARGET_PLATFORM), esp32)
PWIFI_SRCS += $(pwifi-basedir)src/esp32.c
else ifeq ($(TARGET_PLATFORM), zephyr)
PWIFI_SRCS += $(pwifi-basedir)src/zephyr.c
else
$(warning "No target specified. Building with dummy target.")
PWIFI_SRCS += $(pwifi-basedir)src/dummy.c
endif

PWIFI_INCS := $(pwifi-basedir)include
