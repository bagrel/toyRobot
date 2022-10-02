#include <iostream>
#include <type_definitions.hpp>
#include <robot.hpp>

using namespace std;

int main(int, char** argv) {
    cout<<"Welcome to ToyRobot APP"<<endl;
    cout<<"Please use this following commands"<<endl;
    cout<<"[PLACE x,y,direction]: Places a robot on specific coordinate(x,y) the table, facing (direction)"<<endl;
    cout<<"[LEFT]: Rotates the robot counterclockwise"<<endl;
    cout<<"[RIGHT]: Rotates the robot clockwise"<<endl;
    cout<<"[REPORT]: Prints the robot's position and direction; Ends the APP"<<endl;
    ECommand curCmd = ECommand_Invalid;
    string last;
    string l;
    while(ECommand_Report != curCmd)
    {
        last = l;
        getline(cin,l);
        if("REPORT" == l)
        {
            curCmd = ECommand_Report;
        }
    }

    cout<<"out: "<<last<<endl;

    
}
