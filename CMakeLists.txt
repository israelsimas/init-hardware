cmake_minimum_required(VERSION 2.8)

project (InitHardware)

SET(CMAKE_SYSTEM_NAME Linux)

if(APPLE)
  include_directories( /usr/local/include )
  link_directories( /usr/local/lib/ )
  set(CMAKE_MACOSX_RPATH ON)
endif()

include_directories( app/include/ )
file(GLOB headers "app/include/*.h" )
file(GLOB sources "app/src/*.c" )

add_executable(init-hardware ${sources} ${headers})

target_link_libraries( init-hardware utils database iniparser pthread )
