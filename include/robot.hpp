#ifndef TOY_ROBOT
#define TOY_ROBOT

#include "type_definitions.hpp"

class CRobot
{
    public:
        CRobot(SPosition_t pos, ERobotDirection direction);
        void rotate(ERobotRotate_t direction);
        void set_position(SPosition_t new_coordinates);
        void report();
        int get_x_position();
        int get_y_position();
        ERobotDirection get_direction();

    private:
        SPosition_t cur_position;
        ERobotDirection cur_face;
};


#endif // TOY_ROBOT