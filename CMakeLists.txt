cmake_minimum_required(VERSION 3.5)

project(PlayWithPocoMultiCast)

set (CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include .)
link_directories(/usr/local/lib)

set(EXECUTABLE_OUTPUT_PATH bin)

add_executable( mcastSendReceive src/mcastSendReceive.cpp )



target_link_libraries(

    mcastSendReceive

    PocoFoundation
    PocoNet

)


