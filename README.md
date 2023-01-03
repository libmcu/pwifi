## Integration Guide

### Include in your project

```bash
$ cd ${YOUR_PROJECT_DIR}
$ git submodule add https://github.com/libmcu/pwifi.git pwifi
```

### Add in your build system

Supported target platforms are:

- esp32
- zephyr

```cmake
set(PWIFI_TARGET_PLATFORM esp32)
add_subdirectory(pwifi)
```
