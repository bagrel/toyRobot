#ifndef TOY_CMD
#define TOY_CMD

#include <string>
#include "type_definitions.hpp"
#include "robot.hpp"

class CCommand
{
    public:
        CCommand(ECommand_t cmd);
        virtual void execute();
        ECommand_t getCmdType();
    private:
        ECommand_t cmdType;
};

class CCommand_Invalid : public CCommand
{
    public:
        CCommand_Invalid(std::string cmd);
        virtual void execute();
    private:
        std::string cmdStr;
};

class CCommand_Report : public CCommand
{
    public:
        CCommand_Report(CRobot* in_robo);
        virtual void execute();
    private:
        CRobot* robot;
        
};

#endif