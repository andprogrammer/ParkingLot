# ParkingLot
Parking Lot Solver


Run the program:

clear && mkdir build && cd build && cmake .. && make && ./parking_lot file_inputs.txt

file_inputs.txt should be automatically copied to build directory because of additional instruction in CMakeLists.txt:

file(COPY data/file_inputs.txt DESTINATION .)


Used Design Patterns:

-Strategy

-Singleton


No Google Test/Mock. Only g++ compiler is required.

Program activated and tested.
