#ifndef TOY_ROBOT
#define TOY_ROBOT

#include "type_definitions.hpp"

class CRobot
{
    public:
        CRobot(SPosition_t pos, ERobotDirection_t direction);
        void rotate(ERobotRotate_t direction);
        void set_position(SPosition_t new_coordinates);
        void set_direction(ERobotDirection_t new_direction);
        void report();
        int get_x_position();
        int get_y_position();
        ERobotDirection_t get_direction();

    private:
        SPosition_t cur_position;
        ERobotDirection_t cur_face;
};


#endif // TOY_ROBOT