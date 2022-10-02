#include "line_parser.hpp"
#include <iostream>

CLineParser::CLineParser(std::string input_line)
{
}

ECommand_t CLineParser::getCommand()
{
    std::string cmd;
    std::transform(line.begin(), line.end(), cmd.begin(),::toupper);
    std::cout<<"Command is:"<<cmd.c_str()<<std::endl;

    return ECommand_Invalid;
}