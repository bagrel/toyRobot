#include <iostream>
#include <toy_cmd.hpp>

CCommand::CCommand(ECommand_t cmd) : cmdType(cmd)
{
}

void CCommand::execute()
{
}

ECommand_t CCommand::getCmdType()
{
    return cmdType;
}

CCommand_Place::CCommand_Place(std::shared_ptr<CRobot>* in_robo, std::vector<std::string> in_args, CTable* in_table) : CCommand(ECommand_Place),
robot(in_robo), args(in_args), table(in_table)
{
}

void CCommand_Place::execute()
{
    if(3 != args.size())
    {
        std::cout<<"Invalid number of arguments for command PLACE"<<std::endl;
        return;
    }
    std::string arg = args.back();
    args.pop_back();

    std::string face[] ={"NORTH", "EAST", "SOUTH", "WEST"};
    int face_index = 0;
    while(face_index < ERobotDirection_Invalid && face[face_index] != arg)
    {
        face_index++;
    }
    ERobotDirection_t newDir = ERobotDirection_t(face_index);
    if(ERobotDirection_Invalid == newDir)
    {
        std::cout<<"Invalid direction for command PLACE"<<std::endl;
        return;
    }

    SPosition_t nPos = {};
    nPos.y = std::stoi(args.back());
    args.pop_back();
    nPos.x = std::stoi(args.back());
    args.pop_back();
    
    if(!table->place_robot(robot, nPos, newDir))
    {
        std::cout<<"Invalid position x: "<<nPos.x<<", y: "<<nPos.y<<std::endl;
        return;
    }
}

CCommand_Rotate::CCommand_Rotate(CRobot* in_robo, std::vector<std::string> in_args) : CCommand(ECommand_Rotate),
robot(in_robo), args(in_args)
{
}

void CCommand_Rotate::execute()
{
    if(NULL!=robot)
    {
        std::string arg = args.back();
        args.pop_back();

        std::string rotateDirList[] ={"CCW","CW"};
        int rotate_index = 0;
        while(rotate_index < ERobotRotate_Invalid && rotateDirList[rotate_index] != arg)
        {
            rotate_index++;
        }
        ERobotRotate_t rotateDir = ERobotRotate_t(rotate_index);
        if(ERobotRotate_Invalid == rotateDir)
        {
            std::cout<<"Invalid rotation"<<std::endl;
            return;
        }
        robot->rotate(rotateDir);
    }
    else
    {
        std::cout<<"Robot is not yet placed. Please restart APP"<<std::endl;
    }
}

CCommand_Move::CCommand_Move(CTable* in_table) : CCommand(ECommand_Move),
table(in_table)
{
}

void CCommand_Move::execute()
{
    if(!table->move_robot_forward())
    {
        std::cout<<"Robot will fall, ignoring command MOVE"<<std::endl;
    }
}

CCommand_Report::CCommand_Report(CRobot* in_robo) : CCommand(ECommand_Report),
robot(in_robo)
{
}

void CCommand_Report::execute()
{
    if(NULL!=robot)
    {
        robot->report();
    }
    else
    {
        std::cout<<"Robot is not yet placed. Please restart APP"<<std::endl;
    }
}

CCommand_Invalid::CCommand_Invalid(std::string cmd) : CCommand(ECommand_Invalid), cmdStr(cmd)
{
}

void CCommand_Invalid::execute()
{
    std::cout<<"Ignoring Command "<<cmdStr<<std::endl;
}