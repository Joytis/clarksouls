cmake_minimum_required(VERSION 3.3)
project(clarksouls)

file(GLOB_RECURSE clarksouls_SOURCES "src/*.cpp")
file(GLOB_RECURSE clarksouls_HEADERS "src/*.h")

set (clarksouls_INCLUDE_DIRS "")
foreach (_headerFile ${clarksouls_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND clarksouls_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES clarksouls_INCLUDE_DIRS)

include_directories(${clarksouls_INCLUDE_DIRS})



add_executable (clarksouls ${clarksouls_SOURCES}

        src/Includes.hpp
        src/game_states/StateIncludes.hpp

        src/exceptions/StateSystemExceptions.hpp
        src/exceptions/ManagerExceptions.hpp)



set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(${SFML_ROOT} "D:/dev/SFML-2.3.2_64")

find_package(SFML 2 REQUIRED graphics window network audio system )
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(clarksouls ${SFML_LIBRARIES})
endif()