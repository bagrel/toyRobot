#### Welcome ####
This project is for Toy Robot APP that simulates placing a robot in a table of grid(5,5) using the following commands:
[PLACE x,y,direction]: Places a robot on specific coordinate(x,y) the table, facing (direction)
[LEFT]: Rotates the robot counterclockwise
[RIGHT]: Rotates the robot clockwise
[REPORT]: Prints the robot's position and direction; Ends the APP

To install:
checkout using ```git clone https://github.com/bagrel/toyRobot.git```

Configure CMake project using CMake ver 3.0
Create your build directory
```
mkdir build
cd build
```
Run CMake:
```cmake /[path-to-project]```

Run Make:
```
cd build
make -j10
```

To run program:
```
cd build
./toyRobot
```

To run unit tests:
```
cd build/test
./toyRobot_test
```

To run Module Test:
write Test Case with the following format in [project_directory]/module_test/test_input.py
```
[test case name]
[command input 1]
[command input 2]
...
[command input n]
REPORT
Output: [Expected Output]
```