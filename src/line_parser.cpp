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
    while(cmd_index < ECommand_Invalid && commands[cmd_index] != cmd)
    {
        cmd_index++;
    }
    ECommand_t a = ECommand_t(cmd_index);
    return ECommand_t(cmd_index);
}

std::vector<std::string> CLineParser::get_args()
{
    return args;
}