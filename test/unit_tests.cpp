#include <gtest/gtest.h>
#include <robot.hpp>
#include <table.hpp>
#include <line_parser.hpp>

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

TEST(Table_Test, add_robot)
{
    CTable test_table(5, 5);
    SPosition_t pos = {1, 2};
    test_table.place_robot(pos, ERobotDirection_South);
}

TEST(Table_Test, move_no_robot)
{
    CTable test_table(5, 5);
    ASSERT_FALSE(test_table.move_robot_forward());
}

TEST(Table_Test, move_north)
{
    CTable test_table(5, 5);
    SPosition_t pos = {0, 0};
    test_table.place_robot(pos, ERobotDirection_North);
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_FALSE(test_table.move_robot_forward());
}

TEST(Table_Test, move_south)
{
    CTable test_table(5, 5);
    SPosition_t pos = {0, 4};
    test_table.place_robot(pos, ERobotDirection_South);
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_FALSE(test_table.move_robot_forward());
}

TEST(Table_Test, move_east)
{
    CTable test_table(5, 5);
    SPosition_t pos = {0, 0};
    test_table.place_robot(pos, ERobotDirection_East);
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_FALSE(test_table.move_robot_forward());
}

TEST(Table_Test, move_west)
{
    CTable test_table(5, 5);
    SPosition_t pos = {4, 0};
    test_table.place_robot(pos, ERobotDirection_West);
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_FALSE(test_table.move_robot_forward());
}

TEST(Table_Test, rotate_fail)
{
    CTable test_table(5, 5);
    ASSERT_FALSE(test_table.rotate(ERobotRotate_Left));
}

TEST(Table_Test, rotate_success)
{
    CTable test_table(5, 5);
    SPosition_t pos = {4, 0};
    test_table.place_robot(pos, ERobotDirection_West);
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.rotate(ERobotRotate_Left));
    ASSERT_FALSE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.rotate(ERobotRotate_Left));
    ASSERT_TRUE(test_table.move_robot_forward());
    ASSERT_TRUE(test_table.rotate(ERobotRotate_Left));
    ASSERT_TRUE(test_table.move_robot_forward());
}

TEST(LineParser_Test, decode)
{
    CLineParser cmd("test");
    ASSERT_EQ(ECommand_Invalid, cmd.getCommand());
}