#include "robot.hpp"
#include <iostream>

CRobot::CRobot(SPosition_t pos, ERobotDirection_t direction) : cur_position(pos), cur_face(direction)
{
}

void CRobot::set_position(SPosition_t new_coordinates)
{
    cur_position.x = new_coordinates.x;
    cur_position.y = new_coordinates.y;
}

void CRobot::rotate(ERobotRotate_t direction)
{
    switch(direction)
    {
        case ERobotRotate_Left:
        {
            ERobotDirection_values::adv_left(cur_face);
        }
        break;

        case ERobotRotate_Right:
        {
            ERobotDirection_values::adv_right(cur_face);
        }
        break;
        default:
            std::cout<<"Invalid Rotation command"<<std::endl;
    }
}

int CRobot::get_x_position()
{
    return cur_position.x;
}

int CRobot::get_y_position()
{
    return cur_position.y;
}

ERobotDirection_t CRobot::get_direction()
{
    return cur_face;
}

void CRobot::set_direction(ERobotDirection_t new_direction)
{
    cur_face = new_direction;
}

void CRobot::report()
{
    std::string face[] ={"NORTH", "EAST", "SOUTH", "WEST"};
    std::cout<<cur_position.x<<","<<cur_position.y<<","<<face[cur_face]<<std::endl;
}
