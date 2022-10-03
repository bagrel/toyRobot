#include <iostream>
#include <type_definitions.hpp>
#include <robot.hpp>
#include <line_parser.hpp>
#include <gameCommand.hpp>
#include <memory>
#include <fstream>

#define TABLE_SIZE_X 5
#define TABLE_SIZE_Y 5

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
        }
        break;
        case ECommand_Invalid:
        {
            return cont;
        }
        case ECommand_Close:
        {
            return false;
        }
        default:
        {
            cout<<"Unknown CommandType"<<endl;
            return cont;
        }
        break;
    }
    curCmdCls->execute();
    return cont;
}

int main(int argc, char** argv) {

    CTable gameTable(TABLE_SIZE_X,TABLE_SIZE_Y);
    string l;

    if(argc < 2){
        cout<<"Welcome to ToyRobot APP"<<endl;
        cout<<"You are in CommandLineMode"<<endl;
        cout<<"Please use this following commands"<<endl;
        cout<<"[PLACE x,y,direction]: Places a robot on specific coordinate(x,y) the table, facing (direction)"<<endl;
        cout<<"[LEFT]: Rotates the robot counterclockwise"<<endl;
        cout<<"[RIGHT]: Rotates the robot clockwise"<<endl;
        cout<<"[REPORT]: Prints the robot's position and direction"<<endl;
        cout<<"[CLOSE]: Closes the app"<<endl;
    
        bool cont = true;
        while(cont)
        {
            getline(cin,l);
            cont = handleLineInput(gameTable, l);
        }
        return 0;
    }
    else 
    {
        ifstream inFile;
        inFile.open(argv[1]);
        if(inFile.is_open())
        {
            while(getline(inFile, l)) {
                cout<<l<<endl;
                handleLineInput(gameTable, l);
            }
            inFile.close();
            return 0;
        }
        else
        {
            cout<<"Cannot open file: "<<argv[1]<<endl;
        }
    }
}
