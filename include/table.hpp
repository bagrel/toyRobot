#ifndef TOY_ROBOT_TABLE
#define TOY_ROBOT_TABLE

#include "type_definitions.hpp"
#include "robot.hpp"
#include <map>

class CTable
{
    public:
        CTable();
        ~CTable();
        bool move_robot_forward(int key);
        bool place_robot(int key, SPosition_t new_position);

    private:
        int size_x;
        int size_y;
        std::map<int, CRobot> active_robots;
};


#endif // TOY_ROBOT_TABLE