# SPDX-License-Identifier: MIT

ifneq ($(PWIFI_ROOT),)
pwifi-basedir := $(PWIFI_ROOT)/
endif

ifeq ($(PWIFI_TARGET_PLATFORM), dummy)
PWIFI_SRCS += $(pwifi-basedir)src/dummy.c
else ifeq ($(PWIFI_TARGET_PLATFORM), esp32)
PWIFI_SRCS += $(pwifi-basedir)src/esp32.c
else ifeq ($(PWIFI_TARGET_PLATFORM), zephyr)
PWIFI_SRCS += $(pwifi-basedir)src/zephyr.c
else
$(error "No target specified.")
endif

PWIFI_INCS := $(pwifi-basedir)include
