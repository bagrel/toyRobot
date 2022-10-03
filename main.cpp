#include <iostream>
#include <type_definitions.hpp>
#include <robot.hpp>
#include <line_parser.hpp>
#include <gameCommand.hpp>
#include <memory>

using namespace std;

bool handleLineInput(CTable& gameTable, string line) {
    CLineParser cmdLine(line);
    unique_ptr<CCommand> curCmdCls;
    bool cont = true;
    switch(cmdLine.parse())
    {
        case ECommand_Place:
        {
            curCmdCls.reset(new CCommand_Place(cmdLine.get_args(), &gameTable));
        }
        break;
        case ECommand_Left:
        {
            curCmdCls.reset(new CCommand_Rotate(gameTable.getRobotOnTable(), ECommand_Left));
        }
        break;
        case ECommand_Right:
        {
            curCmdCls.reset(new CCommand_Rotate(gameTable.getRobotOnTable(), ECommand_Right));
        }
        break;
        case ECommand_Move:
        {
            curCmdCls.reset(new CCommand_Move(&gameTable));
        }
        break;
        case ECommand_Report:
        {
            curCmdCls.reset(new CCommand_Report(gameTable.getRobotOnTable()));
            cont = false;
        }
        break;
        default:
        {
            cout<<"Unknown CommandType"<<endl;
        }
        break;
    }
    curCmdCls->execute();
    return cont;
}

int main(int, char** argv) {
    cout<<"Welcome to ToyRobot APP"<<endl;
    cout<<"Please use this following commands"<<endl;
    cout<<"[PLACE x,y,direction]: Places a robot on specific coordinate(x,y) the table, facing (direction)"<<endl;
    cout<<"[LEFT]: Rotates the robot counterclockwise"<<endl;
    cout<<"[RIGHT]: Rotates the robot clockwise"<<endl;
    cout<<"[REPORT]: Prints the robot's position and direction; Ends the APP"<<endl;
    
    CTable gameTable(5,5);

    bool cont = true;
    while(cont)
    {
        string l;
        getline(cin,l);
        cont = handleLineInput(gameTable, l);
    }
}
