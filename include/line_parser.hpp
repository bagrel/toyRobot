#ifndef LINE_PARSER
#define LINE_PARSER

#include "type_definitions.hpp"
#include <string>
#include <table.hpp>

class CLineParser
{
    public:
        CLineParser(std::string input_line);
        ECommand_t getCommand();
    private:
        std::string line;
};

class CCommand
{
    public:
        virtual void execute(CTable &table);
};

class CCommand_Place : CCommand
{
    private:
        SPosition_t new_place;
};

class CCommand_Rotate : CCommand
{
    private:
        ERobotRotate_t rotate_direction;
};

class CCommand_Report : CCommand
{

};

#endif