cmake_minimum_required(VERSION 2.8.9)
project(ParkingLot)

include_directories(include)

file(COPY data/file_inputs.txt DESTINATION .)
file(GLOB SOURCES "src/*.cpp")

add_executable(parking_lot ${SOURCES})
