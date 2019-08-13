#include "vex.h"

using namespace vex;
bool autonDone; //Boolean used to identify whether the autonomous has been activated or not
int count; //Integer to identify which autonomous option should be displayed in the autonomous selection
const char *autonModes[9]; //Pointer to autonomous 

//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*        VEXCode/VCS Autonomous Picker             */
/*                                                  */
/* Created By: Victor Radoslavov and Kieran Higham  */
/*                                                  */
/* Purpose: To create a graphical UI in order to    */
/* control the autonomous program triggered in the  */
/* autonomous phase.                                */
/*                                                  */
/*            Date Written: 14/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

void aprograms::Where_Pressed(){
    while(!thinkboi.Screen.pressing()){} //Lines 21 and 22 ensure that the screen isn't in a glitchy state while not being pressed
    while(thinkboi.Screen.pressing()){} 
    int X = thinkboi.Screen.xPosition(); //Finds the pressed X co-ordinate
    int Y = thinkboi.Screen.yPosition(); //Finds the pressed Y co-ordinate
    /*
    Please Note that within this Graphical UI code, the Ternary Operator is used for the Button Checks. The Ternary Operator is the "?", and it acts as an if statement but with less lines, allowing for more efficiency
    */
    (( X > 370 && X < 470 && Y > 130 && Y < 230) ? count = 0: count); //Checks whether the button pressed is the "Do Nothing" Button - if so the count will be set to 0 in order for the blank autonomous to be activated
    ((X > 370 && X < 470 && Y > 10 && Y < 110) ? autonDone = true: autonDone = false); //Checks whether the button pressed is the "Confirm" Button - if so autonDone will be set to true and the preautonomous will stop
    ((X > 10 && X < 170 && Y > 130 && Y < 230) ? count = count - 1: count); //Checks whether the button pressed is the "Previous" Button - if so then the count will be one less and when the next preautonomous loopthrough runs it will be the prior autonomous option
    ((count < 0) ? count = 8: count); //Checks whether the count is below 0, if so it will overflow back to 8, the maximum value
    ((X > 190 && X < 350 && Y > 130 && Y < 230) ? count = count + 1: count); //Checks whether the button pressed is the "Next" Button - if so then the count will be one more and when the next preautonomous loopthrough runs it will be the next autonomous option
    ((count > 8) ? count = 0: count); //Checks whether the count is above 8, if so it will underflow back to 0, the minimum value
}
void aprograms::Picking(color colors,int padding){
    thinkboi.Screen.setFillColor(color::white); //The Autonomous Label Colour is set to White
    thinkboi.Screen.setPenColor(color::white);
    thinkboi.Screen.drawRectangle(10, 40, 340, 70); // The Autonomous Label is made
    thinkboi.Screen.setFillColor(colors); //The colour to show which alliance is which is set here
    thinkboi.Screen.drawRectangle(10, 40, 70, 70); //The alliance square is drawn
    thinkboi.Screen.setFillColor(color::white); //The autonomous text colour is set
    thinkboi.Screen.setPenColor(color::black);
    thinkboi.Screen.printAt(padding, 80, autonModes[count]); //Prints the autonomous mode in text here, with the paddin and the autonomous.
    Where_Pressed();//Runs the button checking function
}
void aprograms::autonselect() {
    autonModes[0] = "Do Nothing";         //Lines 49 to 57 set the autonomous text for use in the Picking() Function
    autonModes[1] = "Big Zone - No Towers";
    autonModes[2] = "Small Zone - No Towers";
    autonModes[3] = "Small Zone - Same Towers";
    autonModes[4] = "Small Zone - Mixed Towers";
    autonModes[5] = "Big Zone - No Towers";
    autonModes[6] = "Small Zone - No Towers";
    autonModes[7] = "Small Zone - Same Towers";
    autonModes[8] = "Small Zone - Mixed Towers";
    autonDone = false; //Sets the autonDone to false so the auton Selection loops
    count = 1;  //Sets the count varible to 1, so that it begins with "red Big Zone - No Towers"
    while(autonDone == false){
        /*
          Draws the UI. Uncertain whether it needs to be within the loop, however I will keep it until a further update since I lack access to a v5 thinkboi currently
        */
        thinkboi.Screen.setPenColor(color::white); //Sets the text colour
        thinkboi.Screen.setFillColor(color::black);
        thinkboi.Screen.printAt(71, 25, "Select Autonomous Mode"); //Writes Text
        thinkboi.Screen.setFillColor(color::white);
        thinkboi.Screen.drawRectangle(10, 40, 340, 70); //Draws Buttons
        thinkboi.Screen.drawRectangle(10, 130, 160, 100); 
        thinkboi.Screen.drawRectangle(190, 130, 160, 100);
        thinkboi.Screen.setPenColor(color::black);
        thinkboi.Screen.printAt(251, 185, "Next"); //Writes Next Button
        thinkboi.Screen.printAt(51, 185, "Previous"); //Writes the Previous Button
        thinkboi.Screen.setPenColor(color::white);
        thinkboi.Screen.setFillColor(color::green);//Sets Colours for Confirm Button
        thinkboi.Screen.drawRectangle(370, 10, 100, 100);
        thinkboi.Screen.setPenColor(color::black);
        thinkboi.Screen.printAt(386, 65, "Confirm");//Writes Confirm Button
        thinkboi.Screen.setPenColor(color::white);
        thinkboi.Screen.setFillColor(vex::color::red);//Sets colour for Do Nothing Button
        thinkboi.Screen.drawRectangle(370, 130, 100, 100);
        thinkboi.Screen.setPenColor(color::black);
        thinkboi.Screen.printAt(410, 175, "Do"); // Lines 83 and 84 write do nothing Button
        thinkboi.Screen.printAt(385, 195, "Nothing");
        ((count == 0) ? Picking(black,168):(count == 1) ? Picking(red,116):(count == 2) ? Picking(red,106):(count == 3) ? Picking(red,96):(count == 4) ? Picking(red,91):(count == 5) ? Picking(blue,116): (count == 6) ? Picking(blue,106):(count == 7) ? Picking(blue,96):(count == 8) ? Picking(blue,91): Picking(blue, 91));
        //This long ternary operation checks for each value of count and for each one runs the "Picking()" command with the colour and padding required, it nests to conserve vertical space, 0 being black for doing nothing, 1-4 being red for red alliance autonomous and 5-8 being blue for blue alliance autonomous
    }
    thinkboi.Screen.clearScreen(); //Clears the Screen ready for other text (diagnostics, control messages etc.)
}