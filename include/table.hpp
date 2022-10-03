#ifndef TOY_ROBOT_TABLE
#define TOY_ROBOT_TABLE

#include "type_definitions.hpp"
#include "robot.hpp"
#include <map>
#include <utility>

class CTable
{
    public:
        CTable(int x, int y);
        bool move_robot_forward();
        bool place_robot(std::shared_ptr<CRobot>* in_robo, SPosition_t new_position, ERobotDirection dir);
        bool rotate(ERobotRotate direction);

    private:
        int size_x;
        int size_y;
        std::weak_ptr<CRobot> active_robot;
};


#endif // TOY_ROBOT_TABLE