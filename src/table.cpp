#include "table.hpp"
#include <iostream>

CTable::CTable(int x, int y):size_x(x),size_y(y)
{
}

bool CTable::place_robot(SPosition_t new_position, ERobotDirection dir)
{
    if(new_position.x >= size_x || new_position.y >= size_y || new_position.x < 0 || new_position.y < 0) {
        return false;
    }

    active_robot.reset(new CRobot(new_position, dir));

    return true;
}

CRobot* CTable::getRobotOnTable()
{
    return active_robot.get();
}

bool CTable::move_robot_forward()
{
    CRobot* rob = active_robot.get();
    if(NULL == rob)
    {
        return false;
    }

    ERobotDirection face = rob->get_direction();
    SPosition_t pos = {rob->get_x_position(), rob->get_y_position()};
    switch(face) {
        case ERobotDirection_North:
        {
            pos.y++;
            if(pos.y >= size_y) {
                return false;
            }
        }
        break;
        case ERobotDirection_East:
        {
            pos.x++;
            if(pos.x >= size_x) {
                return false;
            }
        }
        break;
        case ERobotDirection_South:
        {
            pos.y--;
            if(pos.y < 0) {
                return false;
            }
        }
        break;
        case ERobotDirection_West:
        {
            pos.x--;
            if(pos.x < 0) {
                return false;
            }
        }
        break;
        default:
            std::cout<<"Invalid Robot Direction"<<std::endl;
            return false;
    }

    rob->set_position(pos);
    return true;
}