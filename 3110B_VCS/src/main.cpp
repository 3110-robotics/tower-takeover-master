#include "robot-config.h"
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

void Where_Pressed(){
    while(!Brain.Screen.pressing()){} //Lines 21 and 22 ensure that the screen isn't in a glitchy state while not being pressed
    while(Brain.Screen.pressing()){} 
    int X = Brain.Screen.xPosition(); //Finds the pressed X co-ordinate
    int Y = Brain.Screen.yPosition(); //Finds the pressed Y co-
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
void Picking(color colors,int padding){
    Brain.Screen.setFillColor(color::white); //The Autonomous Label Colour is set to White
    Brain.Screen.setPenColor(color::white);
    Brain.Screen.drawRectangle(10, 40, 340, 70); // The Autonomous Label is made
    Brain.Screen.setFillColor(colors); //The colour to show which alliance is which is set here
    Brain.Screen.drawRectangle(10, 40, 70, 70); //The alliance square is drawn
    Brain.Screen.setFillColor(color::white); //The autonomous text colour is set
    Brain.Screen.setPenColor(color::black);
    Brain.Screen.printAt(padding, 80, autonModes[count]); //Prints the autonomous mode in text here, with the paddin and the autonomous.
    Where_Pressed();//Runs the button checking function
}
void pre_auton( void ) {
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
          Draws the UI. Uncertain whether it needs to be within the loop, however I will keep it until a further update since I lack access to a v5 brain currently
        */
        Brain.Screen.setPenColor(color::white); //Sets the text colour
        Brain.Screen.setFillColor(color::black);
        Brain.Screen.printAt(71, 25, "Select Autonomous Mode"); //Writes Text
        Brain.Screen.setFillColor(color::white);
        Brain.Screen.drawRectangle(10, 40, 340, 70); //Draws Buttons
        Brain.Screen.drawRectangle(10, 130, 160, 100); 
        Brain.Screen.drawRectangle(190, 130, 160, 100);
        Brain.Screen.setPenColor(color::black);
        Brain.Screen.printAt(251, 185, "Next"); //Writes Next Button
        Brain.Screen.printAt(51, 185, "Previous"); //Writes the Previous Button
        Brain.Screen.setPenColor(color::white);
        Brain.Screen.setFillColor(color::green);//Sets Colours for Confirm Button
        Brain.Screen.drawRectangle(370, 10, 100, 100);
        Brain.Screen.setPenColor(color::black);
        Brain.Screen.printAt(386, 65, "Confirm");//Writes Confirm Button
        Brain.Screen.setPenColor(color::white);
        Brain.Screen.setFillColor(vex::color::red);//Sets colour for Do Nothing Button
        Brain.Screen.drawRectangle(370, 130, 100, 100);
        Brain.Screen.setPenColor(color::black);
        Brain.Screen.printAt(410, 175, "Do"); // Lines 83 and 84 write do nothing Button
        Brain.Screen.printAt(385, 195, "Nothing");
        ((count == 0) ? Picking(black,168):(count == 1) ? Picking(red,116):(count == 2) ? Picking(red,106):(count == 3) ? Picking(red,96):(count == 4) ? Picking(red,91):(count == 5) ? Picking(blue,116): (count == 6) ? Picking(blue,106):(count == 7) ? Picking(blue,96):(count == 8) ? Picking(blue,91): Picking(blue, 91));
        //This long ternary operation checks for each value of count and for each one runs the "Picking()" command with the colour and padding required, it nests to conserve vertical space, 0 being black for doing nothing, 1-4 being red for red alliance autonomous and 5-8 being blue for blue alliance autonomous
    }
    Brain.Screen.clearScreen(); //Clears the Screen ready for other text (diagnostics, control messages etc.)
}

//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*            VEXCode Autonomous Code               */
/*                                                  */
/*         Created By: Victor Radoslavov            */
/*                                                  */
/*  Purpose: To Run the autonomous Program Selected */
/*  in the autonomous picker                        */
/*                                                  */
/*            Date Written: 10/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

void doNothing(){}
void aprogram1(){}
void aprogram2(){}
void aprogram3(){}
void aprogram4(){}
void aprogram5(){}
void aprogram6(){}
void aprogram7(){}
void aprogram8(){}

void autonomous( void ) {
  //a switch statement is used to save lines on if statements
    switch(count){
        case 0: doNothing(); //Does nothing
        case 1: aprogram1(); //programs 1-4 are red alliance
        case 2: aprogram2(); 
        case 3: aprogram3();
        case 4: aprogram4();
        case 5: aprogram5(); //programs 5-8 are blue alliance
        case 6: aprogram6();
        case 7: aprogram7();
        case 8: aprogram8();
    }
}

///////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*         VEXcode Driver Control Program           */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/*  Purpose: To Provide the ability to drive and    */
/*  control the robot during ther driver control    */
/*  period.                                         */
/*                                                  */
/*            Date Written: 05/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

int sgn(int a){
  //Signum mathematical function, used as a hard limit on the motor strengh on the drive
  ((a > 0) ?  a=1 : (a<0) ? a = -1 : a = 0);
  return a;
}
void drive(int a, int b, int c, int d){
  //single stick arcade drive, with divisiors for a soft limit
  int motorl = (a/c + b/d); //defines the left and right motor values
  int motorr = (a/c - b/d);
  ((motorl > 100) ? motorl = sgn(motorl) * 100: motorl); //apply the hard limit "buffer"
  ((motorr > 100) ? motorr = sgn(motorr) * 100: motorr);
  FL.spin(fwd, motorl, pct); //moves the drive motors based on 
  FR.spin(fwd, motorr, pct);
  BL.spin(fwd, motorl, pct);
  BR.spin(fwd, motorr, pct);
}
void pushyboi(bool a, bool b){
  ((a) ? Pushyboi.spin(fwd, 100, pct):(b) ? Pushyboi.spin(fwd,-100,pct): Pushyboi.spin(fwd,0,pct));
  //the ternary operator is utilised to check the booleans of the button R1 and Button R2, and moves the motor based on that
}
void usercontrol( void ) {
  // User control code here, inside the loop
  while (1){
    drive(Controller1.Axis3.value(), Controller1.Axis4.value(), 2, 3);         //runs the driver control functions
    pushyboi(Controller1.ButtonR1.pressing(), Controller1.ButtonR2.pressing());
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );

    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}