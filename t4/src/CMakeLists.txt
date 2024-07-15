ADD_EXECUTABLE(main main.c)

# 需要引入头文件搜索路径，指令INCLUDE_DIRECTORIES
# 路径与t3中的一致
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../libs/include)

# 导入hello库
add_library(hello SHARED IMPORTED)
set_target_properties(hello PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../libs/lib/libhhhello.dylib)

# 为 target 添加需要链接的共享库
TARGET_LINK_LIBRARIES(main hello)

# export DYLD_LIBRARY_PATH=/Users/baigege/LearnCMake/t4/libs/lib:$DYLD_LIBRARY_PATH 设置运行时环境变量

# 将新添加的头文件路径放到已有路径前面
# 不是必须的，如果有头文件名字和系统的重复，且希望优先使用自己的头文件时，可以用
# set(CMAKE_INCLUDE_DIRECTORIES_BEFORE ON)


# 问题，采用安装方式得到的动态库，不可以用

# 笔记

## `PROJECT_BINARY_DIR`，工程编译发生的目录

## `PROJECT_SOURCE_DIR`，工程顶层目录

## `CMAKE_CURRENT_SOURCE_DIR`，当前`CMakeLists.txt` 所在的路径
