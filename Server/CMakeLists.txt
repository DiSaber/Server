cmake_minimum_required(VERSION 3.13)

add_executable (Server "Server.cpp")

set_property(TARGET Server PROPERTY CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS system)
target_link_libraries(Server PRIVATE Boost::boost)
