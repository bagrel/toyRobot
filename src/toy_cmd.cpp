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

CCommand_Invalid::CCommand_Invalid(std::string cmd) : CCommand(ECommand_Invalid), cmdStr(cmd)
{
}

void CCommand_Invalid::execute()
{
    std::cout<<"Ignoring Command "<<cmdStr<<std::endl;
}

CCommand_Report::CCommand_Report(CRobot* in_robo) : CCommand(ECommand_Report), robot(in_robo)
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

