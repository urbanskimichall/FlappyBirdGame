cmake_minimum_required(VERSION 3.15)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)
add_executable(FlappyBird main.cpp Bird.cpp Bird.h Pipe.cpp Pipe.h PipeManagement.cpp PipeManagement.h GameOver.cpp GameOver.h CordsOfPipes.h)
include_directories(C:/SFML/include)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

if(SFML_FOUND)
    include_directories(C:/SFML/include)
    target_link_libraries(FlappyBird sfml-system sfml-window sfml-graphics sfml-audio)
endif()

