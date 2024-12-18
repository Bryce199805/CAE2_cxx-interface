cmake_minimum_required(VERSION 3.28)
project(CAE2)

set(CMAKE_CXX_STANDARD 17)

option(USE_FILESYSTEM "Enable file system support" ON)

set(SRC_LIST
        src/CAE.cpp
        src/DBVariant.cpp
        src/Logger.cpp
)

set(HEAD_LIST
        include/CAE.h
        include/DBVariant.h
        include/Logger.h
)

include_directories(./include)

# DAMENG dataset env
include_directories(${CMAKE_SOURCE_DIR}/pkg/dm_driver/include)
link_directories(${CMAKE_SOURCE_DIR}/pkg/dm_driver/bin)

# yaml cxx env
include_directories(${CMAKE_SOURCE_DIR}/pkg/yaml-cxx/include)
link_directories(${CMAKE_SOURCE_DIR}/pkg/yaml-cxx/bin)

# openssl
include_directories(${CMAKE_SOURCE_DIR}/pkg/openssl/include)
link_directories(${CMAKE_SOURCE_DIR}/pkg/openssl/lib)

# parse_ip env
include_directories(pkg/parse_ip/include)
link_directories(pkg/parse_ip/lib)

# parse_sql env
include_directories(pkg/sqltoast/include)
link_directories(pkg/sqltoast/lib)


if (USE_FILESYSTEM)
    message(STATUS "File system support enabled")
    # file system env
    include_directories(pkg/minio/include)
    link_directories(pkg/minio/lib)

    add_library(CAE2 STATIC ${SRC_LIST} ${HEAD_LIST} src/CAEwithFileSystem.cpp pkg/minio/src/ini.c)
    add_executable(CAE2Test ${SRC_LIST} ${HEAD_LIST} src/CAEwithFileSystem.cpp pkg/minio/src/ini.c src/main.cpp)

    target_compile_definitions(CAE2 PRIVATE USE_FILESYSTEM)
    target_compile_definitions(CAE2Test PRIVATE USE_FILESYSTEM)

    set(OBJ_TEMP_DIR ${CMAKE_BINARY_DIR}/obj)
    file(MAKE_DIRECTORY ${OBJ_TEMP_DIR})

    add_custom_command(OUTPUT ${OBJ_TEMP_DIR}/all_objects
            WORKING_DIRECTORY ${OBJ_TEMP_DIR}
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/openssl/lib/libssl.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/openssl/lib/libcrypto.a
#            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/sqltoast/lib/libsqltoast.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/minio/lib/libcurl.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/minio/lib/libcurlpp.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/minio/lib/libini.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/minio/lib/libinih.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/minio/lib/libINIReader.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/minio/lib/libminiocpp.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/minio/lib/libpugixml.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/minio/lib/libzlib.a
            COMMAND ar -x ${CMAKE_BINARY_DIR}/libCAE2.a
            COMMAND ${CMAKE_COMMAND} -E touch ${OBJ_TEMP_DIR}/all_objects
            COMMENT "Extracting objects from dependency libraries"
    )

    # 创建一个自定义目标 'merge_libs'，依赖于解压操作的输出
    add_custom_target(merge_libs ALL
            DEPENDS ${OBJ_TEMP_DIR}/all_objects
            COMMENT "Merging dependency libraries into libCAEALL2.a"
    )

    # 合并目标文件到新的静态库
    add_custom_command(
            TARGET merge_libs
            POST_BUILD
            COMMAND ar -crsv ${CMAKE_BINARY_DIR}/libCAE2ALL.a ${OBJ_TEMP_DIR}/*.obj ${OBJ_TEMP_DIR}/*.o
            COMMENT "Merging dependency libraries into libCAEALL2.a"
    )

    target_link_libraries(CAE2Test PUBLIC dmdpi yaml-cpp
            miniocpp
            curlpp
            curl
            pugixml
            # inih
            ini inih INIReader bcrypt
            # zlib
            zlib
            # openssl : confirm if contains libeay32.dll. (err-70089)
            crypto ssl ws2_32 crypt32
            # parse_ip
            wpcap Packet IPHlpApi
            # parse_sql
            sqltoast
    )
else ()
    message(STATUS "File system support disabled")

    add_library(CAE2 STATIC ${SRC_LIST} ${HEAD_LIST})
    add_executable(CAE2Test ${SRC_LIST} ${HEAD_LIST} src/main.cpp)

    set(OBJ_TEMP_DIR ${CMAKE_BINARY_DIR}/obj)
    file(MAKE_DIRECTORY ${OBJ_TEMP_DIR})

    add_custom_command(OUTPUT ${OBJ_TEMP_DIR}/all_objects
            WORKING_DIRECTORY ${OBJ_TEMP_DIR}
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/openssl/lib/libcrypto.a
            COMMAND ar -x ${CMAKE_SOURCE_DIR}/pkg/openssl/lib/libssl.a
            COMMAND ar -x ${CMAKE_BINARY_DIR}/libCAE2.a
            COMMAND ${CMAKE_COMMAND} -E touch ${OBJ_TEMP_DIR}/all_objects
            COMMENT "Extracting objects from dependency libraries"
    )

    # 创建一个自定义目标 'merge_libs'，依赖于解压操作的输出
    add_custom_target(merge_libs ALL
            DEPENDS ${OBJ_TEMP_DIR}/all_objects
            COMMENT "Merging dependency libraries into libCAEALL2.a"
    )

    # 合并目标文件到新的静态库
    add_custom_command(
            TARGET merge_libs
            POST_BUILD
            COMMAND ar -crsv ${CMAKE_BINARY_DIR}/libCAE2ALL.a ${OBJ_TEMP_DIR}/*.obj
            COMMENT "Merging dependency libraries into libCAEALL2.a"
    )

    target_link_libraries(CAE2 PUBLIC dmdpi yaml-cpp)
    target_link_libraries(CAE2Test PUBLIC dmdpi yaml-cpp crypto ssl ws2_32 crypt32 wpcap Packet Ws2_32 IPHlpApi sqltoast )
endif ()

# 安装目标
install(FILES ${CMAKE_BINARY_DIR}/libCAE2ALL.a DESTINATION lib)
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

# 安装openssl相关依赖
install(DIRECTORY pkg/openssl/lib/ DESTINATION lib
        FILES_MATCHING PATTERN "*.dll"  # 只匹配 .so 文件
)
install (DIRECTORY pkg/openssl/include/ DESTINATION include)

install(DIRECTORY pkg/parse_ip/lib/ DESTINATION lib
        FILES_MATCHING PATTERN "*.dll"  # 只匹配 .so 文件
)
install(DIRECTORY pkg/parse_ip/include/ DESTINATION include)

install(DIRECTORY pkg/sqltoast/lib/ DESTINATION lib)
install(DIRECTORY pkg/sqltoast/include/ DESTINATION include)

if (USE_FILESYSTEM)
    install(DIRECTORY pkg/minio/include/ DESTINATION include)
    install(FILES ./config.yaml RENAME interface-config.yaml DESTINATION .)

else ()
    install(FILES ./config_withoutFileSystem.yaml RENAME interface-config.yaml DESTINATION .)
endif ()

