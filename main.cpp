#include <iostream>
#include <type_definitions.hpp>
#include <robot.hpp>

int main(int, char**) {
    SPosition_t pos = {1,2};
    CRobot a(pos, ERobotDirection_North);
    a.report();
    a.rotate(ERobotRotate_Right);
    a.report();
    a.rotate(ERobotRotate_Right);
    a.report();
    a.rotate(ERobotRotate_Right);
    a.report();
    a.rotate(ERobotRotate_Right);
    a.report();
    a.rotate(ERobotRotate_Right);
    a.report();
    a.rotate(ERobotRotate_Left);
    a.report();
    a.rotate(ERobotRotate_Left);
    a.report();
    a.rotate(ERobotRotate_Left);
    a.report();
    a.rotate(ERobotRotate_Left);
    a.report();
    a.rotate(ERobotRotate_Left);
    a.report();
}
