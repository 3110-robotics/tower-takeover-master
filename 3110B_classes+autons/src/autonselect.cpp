#include "vex.h"

using namespace vex;
const char* autonModes[9];bool autonDone;int count;
void Where_Pressed(){
    while(!thinkboi.Screen.pressing()){}
    while(thinkboi.Screen.pressing()){}
    int X = thinkboi.Screen.xPosition();int Y = thinkboi.Screen.yPosition();
    ((X > 370 && X < 470 && Y > 130 && Y < 230) ? count = 0: count);
    ((X > 370 && X < 470 && Y > 10 && Y < 110) ? autonDone = true: autonDone);
    ((X > 10 && X < 170 && Y > 130 && Y < 230) ? count = count - 1: count);
    ((count < 0) ? count = 8: count);
    ((X > 190 && X < 350 && Y > 130 && Y < 230) ? count = count + 1: count);
    ((count > 8) ? count = 0: count);
}
void Picking(color colors,int padding){
  thinkboi.Screen.setFillColor(color::white);thinkboi.Screen.setPenColor(vex::color::white);thinkboi.Screen.drawRectangle(10, 40, 340, 70);thinkboi.Screen.setFillColor(colors);thinkboi.Screen.drawRectangle(10, 40, 70, 70);thinkboi.Screen.setFillColor(color::white);thinkboi.Screen.setPenColor(color::black);thinkboi.Screen.printAt(padding, 80, autonModes[count]);Where_Pressed();
}
void autonselect(){
  autonModes[0] = "Do Nothing";autonModes[1] = "Big Zone - No Towers";autonModes[2] = "Small Zone - No Towers";autonModes[3] = "Small Zone - Same Towers";autonModes[4] = "Small Zone - Mixed Towers";autonModes[5] = "Big Zone - No Towers";autonModes[6] = "Small Zone - No Towers";autonModes[7] = "Small Zone - Same Towers";autonModes[8] = "Small Zone - Mixed Towers";autonDone = false;count = 1;
    while(autonDone == false){
        thinkboi.Screen.setPenColor(color::white);thinkboi.Screen.setFillColor(color::black);thinkboi.Screen.printAt(71, 25, "Select Autonomous Mode");thinkboi.Screen.setFillColor(color::white);thinkboi.Screen.drawRectangle(10, 40, 340, 70); thinkboi.Screen.drawRectangle(10, 130, 160, 100); thinkboi.Screen.drawRectangle(190, 130, 160, 100);thinkboi.Screen.setPenColor(color::black);thinkboi.Screen.printAt(251, 185, "Next");thinkboi.Screen.printAt(51, 185, "Previous");thinkboi.Screen.setPenColor(color::white);thinkboi.Screen.setFillColor(color::green);thinkboi.Screen.drawRectangle(370, 10, 100, 100);thinkboi.Screen.setPenColor(color::black);thinkboi.Screen.printAt(386, 65, "Confirm");thinkboi.Screen.setPenColor(color::white);thinkboi.Screen.setFillColor(vex::color::red);thinkboi.Screen.drawRectangle(370, 130, 100, 100); thinkboi.Screen.setPenColor(color::black);thinkboi.Screen.printAt(410, 175, "Do");thinkboi.Screen.printAt(385, 195, "Nothing");
        ((count == 0) ? Picking(black,168):(count == 1) ? Picking(red,116):(count == 2) ? Picking(red,106):(count == 3) ? Picking(red,96):(count == 4) ? Picking(red,91):(count == 5) ? Picking(blue,116): (count == 6) ? Picking(blue,106):(count == 7) ? Picking(blue,96):(count == 8) ? Picking(blue,91): Picking(blue, 91));
    }
    thinkboi.Screen.clearScreen();
    juulsticc.Screen.print(autonModes[count]);
    juulsticc.rumble("-.-");
}