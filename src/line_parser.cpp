#include "line_parser.hpp"
#include <iostream>
#include <sstream>
#include <string>

CLineParser::CLineParser(std::string input_line) : 
line(input_line)
{
}

std::string const CLineParser::cmdStrings[] = {"PLACE", "LEFT", "RIGHT", "MOVE", "REPORT","CLOSE"};

ECommand_t CLineParser::parse()
{
    std::transform(line.begin(), line.end(), line.begin(),::toupper);
    std::stringstream cmdStream(line);
    std::string cmd;
    std::getline(cmdStream, cmd, ' ');

    int cmdIndex = 0;
    while(cmdIndex < ECommand_Invalid && cmdStrings[cmdIndex] != cmd)
    {
        cmdIndex++;
    }
    ECommand_t parsedCmd = ECommand_t(cmdIndex);

    std::string arg;
    while(std::getline(cmdStream, arg, ','))
    {
        args.push_back(arg);
    }
    return parsedCmd;
}

std::vector<std::string> CLineParser::get_args()
{
    return args;
}