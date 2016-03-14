cmake_minimum_required(VERSION 3.3)
project(clandrewsouls)

file(GLOB_RECURSE clandrewsouls_SOURCES "src/*.cpp")
file(GLOB_RECURSE clandrewsouls_HEADERS "src/*.h")

set (clandrewsouls_INCLUDE_DIRS "")
foreach (_headerFile ${clandrewsouls_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND clandrewsouls_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES clandrewsouls_INCLUDE_DIRS)

include_directories(${clandrewsouls_INCLUDE_DIRS})

add_executable (clandrewsouls ${clandrewsouls_SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(clandrewsouls ${SFML_LIBRARIES})
endif()