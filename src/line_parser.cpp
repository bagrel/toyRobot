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

    if("PLACE" == cmd)
    {
        return ECommand_Place;
    }
    if("LEFT" == cmd)
    {
        return ECommand_Left;
    }
    if("RIGHT" == cmd)
    {
        return ECommand_Right;
    }
    if("REPORT" == cmd)
    {
        return ECommand_Report;
    }

    return ECommand_Invalid;
}