#include "line_parser.hpp"
#include <iostream>
#include <sstream>
#include <string>

CLineParser::CLineParser(std::string input_line) : line(input_line)
{
}

ECommand_t CLineParser::getCommand()
{
    std::string cmd, arg;
    std::transform(line.begin(), line.end(), line.begin(),::toupper);
    std::stringstream cmdStream(line);
    std::getline(cmdStream, cmd, ' ');

    while(std::getline(cmdStream, arg, ','))
    {
        args.push_back(arg);
    }

    std::string commands[] ={"PLACE", "LEFT", "RIGHT", "MOVE", "REPORT"};
    int cmd_index = 0;
    if("PLACE" == cmd)
    {
        return ECommand_Place;
    } else if ("LEFT" == cmd)
    {
        args.push_back("CCW");
        return ECommand_Rotate;
    } else if ("RIGHT" == cmd)
    {
        args.push_back("CW");
        return ECommand_Rotate;
    } else if ("MOVE" == cmd)
    {
        return ECommand_Move;
    } else if ("REPORT" == cmd)
    {
        return ECommand_Report;
    } else
    {
        return ECommand_Invalid;
    }
}

std::vector<std::string> CLineParser::get_args()
{
    return args;
}