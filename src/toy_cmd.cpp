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

