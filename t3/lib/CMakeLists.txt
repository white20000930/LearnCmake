
SET(LIBHELLO_SRC hello.c)

# 生成动态库
# SHARED 动态库；STATIC 静态库
ADD_LIBRARY(hhhello SHARED ${LIBHELLO_SRC})

# 生成静态库
ADD_LIBRARY(hhhello_static STATIC ${LIBHELLO_SRC})

# 上述方法缺点：动态库和静态库不能重名
# 添加指令解决，设置文件名
SET_TARGET_PROPERTIES(hhhello_static PROPERTIES OUTPUT_NAME "hhhello")

# 获取库的输出名称
GET_TARGET_PROPERTY(OUTPUT_VALUE hhhello_static OUTPUT_NAME)
MESSAGE(STATUS “This is the hhhello_static OUTPUT_NAME:”${OUTPUT_VALUE})

# 这时还不行，动态库不见了，因为cmake构建一个新的target时，会清理掉其他同名库
# 设置属性 CLEAN_DIRECT_OUTPUT
## 该属性设置为1时，构建过程不会将输出文件复制到构建树的根目录。
## 而是将输出文件放在指定的位置，以避免与其他同名目标的库发生冲突。
SET_TARGET_PROPERTIES(hhhello PROPERTIES CLEAN_DIRECT_OUTPUT 1)
SET_TARGET_PROPERTIES(hhhello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# 动态库应包含版本号，如 libhello.dylib.1.2
# 设置 VERSION 动态库版本  和  SOVERSION api版本
SET_TARGET_PROPERTIES(hhhello PROPERTIES VERSION 1.2 SOVERSION 1)

# 动态库生成如下：
## libhello.so.1.2
## libhello.so.1   ->  libhello.so.1.2  libhello.so.1指向实际文件.1.2
## libhello.so     ->  libhello.so.1    libhello.so指向某版本.1 （1是主版本号）

# 安装库
## 安装目标：TARGETS hello hello_static
## 动态库安装目录关键字：LIBRARY DESTINATION；静态库安装目录关键字：ARCHIVE DESTINATION
# INSTALL(TARGETS hhhello hhhello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
# INSTALL(FILES hello.h DESTINATION include)

# 在mac上，应该将库安装入/usr/local/lib，而不是/usr/lib
## cmake -DCMAKE_INSTALL_PREFIX=/usr/local .. , make ,sudo make install

# 总结
## ADD_LIBRARY() 添加库
## SET_TARGET_PROPERTIES() 设置属性(名称、版本)
## INSTALL() 安装库