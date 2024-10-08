cmake_minimum_required(VERSION 3.28)
project(CAE2)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)

# DAMENG dataset env
include_directories(pkg/dm_driver/include)
link_directories(pkg/dm_driver/bin)

# yaml cxx env
include_directories(pkg/yaml-cxx/include)
link_directories(pkg/yaml-cxx/bin)

add_library(CAE2 STATIC
        include/DamengDB.h
        src/DamengDB.cpp
        src/main.cpp
)

add_executable(CAE2Test
        include/DamengDB.h
        src/DamengDB.cpp
        src/main.cpp)

target_link_libraries(CAE2 PUBLIC dmdpi yaml-cpp)
target_link_libraries(CAE2Test PUBLIC dmdpi yaml-cpp)


# 安装目标
install(TARGETS CAE2 ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# 安装数据库相关的动态库
install(DIRECTORY pkg/dm_driver/bin/ DESTINATION lib
        FILES_MATCHING PATTERN "*.dll"  # 只匹配 .so 文件
)

install(DIRECTORY pkg/yaml-cxx/bin/ DESTINATION lib
        FILES_MATCHING PATTERN "*.dll"  # 只匹配 .so 文件
)

# 安装数据库相关的头文件
install(DIRECTORY pkg/dm_driver/include/ DESTINATION include)
install(DIRECTORY pkg/yaml-cxx/include/ DESTINATION include)

install(FILES ./config.yaml DESTINATION .)