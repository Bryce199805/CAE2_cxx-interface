cmake_minimum_required(VERSION 3.28)
project(CAE2)

set(CMAKE_CXX_STANDARD 17)

option(USE_FILESYSTEM "Enable file system support" OFF)

set(SRC_LIST
        src/DamengDB.cpp
        src/DBVariant.cpp
)

set(HEAD_LIST
        include/DamengDB.h
        include/DBVariant.h
)

include_directories(./include)

# DAMENG dataset env
include_directories(pkg/dm_driver/include)
link_directories(pkg/dm_driver/bin)

# yaml cxx env
include_directories(pkg/yaml-cxx/include)
link_directories(pkg/yaml-cxx/bin)


if (USE_FILESYSTEM)
     message(STATUS "File system support enabled")

     target_compile_definitions(CAE2 PRIVATE USE_FILESYSTEM)
     target_compile_definitions(CAE2Test PRIVATE USE_FILESYSTEM)

     # file system env

     add_library(CAE2 STATIC ${SRC_LIST} ${HEAD_LIST})
     add_executable(CAE2Test ${SRC_LIST} ${HEAD_LIST} src/main.cpp)

     target_link_libraries(CAE2 PUBLIC dmdpi yaml-cpp)
     target_link_libraries(CAE2Test PUBLIC dmdpi yaml-cpp)
else()
     message(STATUS "File system support disabled")

     add_library(CAE2 STATIC ${SRC_LIST} ${HEAD_LIST})
     add_executable(CAE2Test ${SRC_LIST} ${HEAD_LIST} src/main.cpp)

     target_link_libraries(CAE2 PUBLIC dmdpi yaml-cpp)
     target_link_libraries(CAE2Test PUBLIC dmdpi yaml-cpp)
endif ()

# 安装目标
install(TARGETS CAE2 ARCHIVE DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)

# 安装数据库相关依赖
install(DIRECTORY pkg/dm_driver/bin/ DESTINATION lib
        FILES_MATCHING PATTERN "*.dll"  # 只匹配 .so 文件
)
install(DIRECTORY pkg/dm_driver/include/ DESTINATION include)

# 安装数yaml相关依赖
install(DIRECTORY pkg/yaml-cxx/bin/ DESTINATION lib
        FILES_MATCHING PATTERN "*.dll"  # 只匹配 .so 文件
)
install(DIRECTORY pkg/yaml-cxx/include/ DESTINATION include)

if (USE_FILESYSTEM)
     # 安装文件系统相关依赖
     install(FILES ./config.yaml DESTINATION .)
else()
     install(FILES ./config.yaml DESTINATION .)
endif ()

