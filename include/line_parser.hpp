#ifndef LINE_PARSER
#define LINE_PARSER

#include "type_definitions.hpp"
#include <string>
#include <table.hpp>
#include <vector>

class CLineParser
{
    public:
        CLineParser(std::string input_line);
        ECommand_t parse();
        std::vector<std::string> get_args();
    private:
        std::string line;
        std::vector<std::string> args;
        static const std::string cmdStrings[];
};


#endif