 cmake_minimum_required(VERSION 3.2)
 project(PacM)

 set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
 set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "/Users/alexisjauregui/ClionProjects/PacM")
 set(SOURCE_FILES main.cpp)
 add_executable(PacM ${SOURCE_FILES} main.cpp game_state.h main_state.cpp main_state.h pac_game.cpp pac_game.h puck.cpp puck.h score.cpp score.h map.cpp map.h dots.cpp dots.h ghost.cpp ghost.h Lives.cpp Lives.h ghostai.cpp ghostai.h level2.cpp level2.h)
 set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
 find_package(SFML REQUIRED system window graphics network audio)
 if (SFML_FOUND)
     include_directories(${SFML_INCLUDE_DIR})
     target_link_libraries(PacM ${SFML_LIBRARIES})


 endif()