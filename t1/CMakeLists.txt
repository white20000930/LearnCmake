# 定义工程名称
PROJECT (HELLO) 

# 设置源文件列表
# SET指令用于显式的定义变量
SET(SRC_LIST main.c) 

# 打印信息
MESSAGE(STATUS "This is BINARY dir " ${HELLO_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir "${HELLO_SOURCE_DIR})

# 生成可执行文件
# "hello"是生成的可执行文件的名字
ADD_EXECUTABLE(hello ${SRC_LIST})

# 笔记1

# 基本语法规则
## ${} 取值，但在IF语句中，不需要${}
## 指令(参数1 参数2 ...), 指令和参数之间用空格分隔，参数之间用分号或空格分隔
## 指令大小写无关，参数大小写相关，推荐指令大写
## SET(SRC_LIST main.c) 和 SET(SRC_LIST "main.c") ，都可；但如果文件名中间有空格，必须双引号

# 清理 make clean

# 注意：以上是内部构建，但cmake更推荐外部

# 外部构建  out-of-source
## 1. 清除 除了自己写的文件外的其他所有文件
## 2. mkdir build, cd build, cmake .., make
## 最大好处：对于原有工程无影响，所有动作全部发生在编译目录。
## HELLO_SOURCE_DIR工程路径，HELLO_BINARY_DIR编译路径

## 输出结果：
## -- This is BINARY dir /Users/baigege/LearnCMake/t1/build
## -- This is SOURCE dir /Users/baigege/LearnCMake/t1




