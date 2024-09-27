cmake_minimum_required(VERSION 3.28)
project(CAE2)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

# DAMENG dataset env
include_directories(./cxx_driver/include)
link_directories(./cxx_driver/bin)

add_library(CAE2 STATIC
        include/DamengDB.h
        src/DamengDB.cpp
        src/main.cpp
)

add_executable(CAE2Test
        include/DamengDB.h
        src/DamengDB.cpp
        src/main.cpp)

target_link_libraries(CAE2 PUBLIC dmdpi)
target_link_libraries(CAE2Test PUBLIC dmdpi)

# 安装目标
install(TARGETS CAE2 ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# 安装数据库相关的动态库
install(DIRECTORY ./cxx_driver/bin/ DESTINATION lib
        FILES_MATCHING PATTERN "*.dll"  # 只匹配 .so 文件
)

# 安装数据库相关的头文件
install(DIRECTORY ./cxx_driver/include/ DESTINATION include)

