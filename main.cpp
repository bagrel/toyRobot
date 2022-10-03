#include <iostream>
#include <type_definitions.hpp>
#include <robot.hpp>
#include <line_parser.hpp>
#include <toy_cmd.hpp>
#include <memory>

using namespace std;

int main(int, char** argv) {
    cout<<"Welcome to ToyRobot APP"<<endl;
    cout<<"Please use this following commands"<<endl;
    cout<<"[PLACE x,y,direction]: Places a robot on specific coordinate(x,y) the table, facing (direction)"<<endl;
    cout<<"[LEFT]: Rotates the robot counterclockwise"<<endl;
    cout<<"[RIGHT]: Rotates the robot clockwise"<<endl;
    cout<<"[REPORT]: Prints the robot's position and direction; Ends the APP"<<endl;
    
    CCommand_Invalid* init = new CCommand_Invalid("Init");
    unique_ptr<CCommand> curCmdCls;
    curCmdCls.reset(init);
    CTable gameTable(5,5);
    shared_ptr<CRobot> gameRobot;

    while(ECommand_Report != curCmdCls->getCmdType())
    {
        string l;
        getline(cin,l);
        CLineParser cmdLine(l);
        switch(cmdLine.getCommand())
        {
            case ECommand_Place:
            {
                curCmdCls.reset(new CCommand_Place(&gameRobot, cmdLine.get_args(), &gameTable));
            }
            break;
            case ECommand_Rotate:
            {
                curCmdCls.reset(new CCommand_Rotate(gameRobot.get(), cmdLine.get_args()));
            }
            break;
            case ECommand_Move:
            {
                curCmdCls.reset(new CCommand_Move(&gameTable));
            }
            break;
            case ECommand_Report:
            {
                curCmdCls.reset(new CCommand_Report(gameRobot.get()));
            }
            break;
            case ECommand_Invalid:
            {
                curCmdCls.reset(new CCommand_Invalid(l));
            }
            break;
            default:
            {
                cout<<"Unknown CommandType"<<endl;
            }
            break;
        }
        curCmdCls->execute();
    }
}
