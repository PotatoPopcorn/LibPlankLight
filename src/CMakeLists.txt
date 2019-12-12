cmake_minimum_required(VERSION 3.1)

project(LibPlankLight VERSION 0.1
DESCRIPTION "A Lighting Library that allows easy implementation of various lighting hardware")

add_library(planklight SHARED
pldevice.cpp pldevice.h
pldeviceartnet.cpp pldeviceartnet.h
pldeviceenttecpro.cpp pldeviceartnet.h
pldevices.cpp pldevices.h
plenttecutilities.cpp plenttecutilities.h
pluniverse.cpp pluniverse.h)

target_link_libraries(planklight PUBLIC -lpthread)
target_link_libraries(planklight PUBLIC -lftd2xx)
find_package(Boost 1.68 REQUIRED COMPONENTS thread system)


#Handle Installing
#Source: https://foonathan.net/2016/03/cmake-install/

set(tool_dest "bin")
set(include_dest "include")
set(main_lib_dest "lib")

install(TARGETS planklight DESTINATION "${main_lib_dest}")
