# 定义工程名称
PROJECT (HELLO) 

ADD_SUBDIRECTORY(src bin) # src是源码目录，bin是输出目录

# 安装COPYRIGHT和README文件到指定目录
INSTALL(FILES COPYRIGHT README DESTINATION share/doc/cmake/t2)
# 安装runhello.sh到bin目录
INSTALL(PROGRAMS runhello.sh DESTINATION bin)

# 安装doc目录下的所有文件到share/doc/cmake/t2目录
# DESTINATION关键字，指定安装路径
INSTALL(DIRECTORY doc/ DESTINATION share/doc/cmake/t2)


# 笔记2

# 项目结构
# .
# ├── CMakeLists.txt
# ├── COPYRIGHT 关于版权信息的文件
# ├── README 项目简介等信息文件
# ├── build 文件夹，用于存放编译生成的文件
# ├── doc 暂时不知道
# │   └── hello.txt 
# ├── runhello.sh 脚本文件
# └── src 源码目录
#     ├── CMakeLists.txt
#     └── main.c





