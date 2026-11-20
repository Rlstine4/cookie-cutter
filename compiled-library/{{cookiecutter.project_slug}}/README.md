# {{ cookiecutter.project_name }}

**{{ cookiecutter.description }}**

## Requirements

- CMake 3.26 or newer
- C++{{ cookiecutter.cxx_standard }} compiler
- Network access if using CPM to bring in packages

## Build

The project provides CMake presets. Build files are written to
`build/<preset>/`.

| Preset | Build type | Tests |
| --- | --- | --- |
| `debug` | Debug | Off |
| `release` | Release | Off |
| `test` | Debug | On |

```sh
cmake --preset debug
cmake --build --preset debug
```

Libraries are built shared by default; pass `-DBUILD_SHARED_LIBS=OFF` for a static build.

Dependencies are managed with [CPM](https://github.com/cpm-cmake/CPM.cmake).

## Tests

Tests use [Catch2](https://github.com/catchorg/Catch2) and are registered with CTest:

```sh
cmake --preset test
cmake --build --preset test
ctest --preset test
```

## Usage

```cmake
find_package({{ cookiecutter.project_slug }} CONFIG REQUIRED)
target_link_libraries(my_target PRIVATE {{ cookiecutter.project_slug }}::{{ cookiecutter.project_slug }})
```

```cpp
#include <{{ cookiecutter.project_slug }}/{{ cookiecutter.project_slug }}.hpp>
```
