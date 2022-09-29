#include <gtest/gtest.h>
#include <robot.hpp>

TEST(Robot_Test, init_pos)
{
    SPosition_t pos = {1, 2};
    CRobot test_rob(pos, ERobotDirection_North);

    ASSERT_EQ(1, test_rob.get_x_position());
    ASSERT_EQ(2, test_rob.get_y_position());
    ASSERT_EQ(ERobotDirection_North, test_rob.get_direction());
}

TEST(Robot_Test, rotate_left)
{
    SPosition_t pos = {1, 2};
    CRobot test_rob(pos, ERobotDirection_North);

    ASSERT_EQ(1, test_rob.get_x_position());
    ASSERT_EQ(2, test_rob.get_y_position());
    ASSERT_EQ(ERobotDirection_North, test_rob.get_direction());

    test_rob.rotate(ERobotRotate_Left);

    ASSERT_EQ(1, test_rob.get_x_position());
    ASSERT_EQ(2, test_rob.get_y_position());
    ASSERT_EQ(ERobotDirection_West, test_rob.get_direction());
    test_rob.rotate(ERobotRotate_Left);
    ASSERT_EQ(ERobotDirection_South, test_rob.get_direction());
    test_rob.rotate(ERobotRotate_Left);
    ASSERT_EQ(ERobotDirection_East, test_rob.get_direction());
    test_rob.rotate(ERobotRotate_Left);
    ASSERT_EQ(ERobotDirection_North, test_rob.get_direction());
    test_rob.rotate(ERobotRotate_Left);
    ASSERT_EQ(ERobotDirection_West, test_rob.get_direction());
}

TEST(Robot_Test, rotate_right)
{
    SPosition_t pos = {1, 2};
    CRobot test_rob(pos, ERobotDirection_North);

    ASSERT_EQ(1, test_rob.get_x_position());
    ASSERT_EQ(2, test_rob.get_y_position());
    ASSERT_EQ(ERobotDirection_North, test_rob.get_direction());

    test_rob.rotate(ERobotRotate_Right);

    ASSERT_EQ(1, test_rob.get_x_position());
    ASSERT_EQ(2, test_rob.get_y_position());
    ASSERT_EQ(ERobotDirection_East, test_rob.get_direction());
    test_rob.rotate(ERobotRotate_Right);
    ASSERT_EQ(ERobotDirection_South, test_rob.get_direction());
    test_rob.rotate(ERobotRotate_Right);
    ASSERT_EQ(ERobotDirection_West, test_rob.get_direction());
    test_rob.rotate(ERobotRotate_Right);
    ASSERT_EQ(ERobotDirection_North, test_rob.get_direction());
    test_rob.rotate(ERobotRotate_Right);
    ASSERT_EQ(ERobotDirection_East, test_rob.get_direction());
}