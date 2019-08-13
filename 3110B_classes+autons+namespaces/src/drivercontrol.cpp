#include "vex.h"

using namespace vex;

//////////////////////////////////////////////////////
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
/*            Date Written: 17/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

void dcontrol::usercontrol( void ) {
  // User control code here, inside the loop
  int speedlim = 2;  //sets the limiting factors for the chassis drive
  int turnlim = 3;
  while (1) {                                                                 //runs the driver control functions
    drive(juulsticc.Axis3.value(), juulsticc.Axis4.value(), speedlim, turnlim);
    pushyboi(totcalc(juulsticc.ButtonR1.pressing(), juulsticc.ButtonR2.pressing())); //initiates the pushing motor
    barlift(totcalc(juulsticc.ButtonL1.pressing(), juulsticc.ButtonL2.pressing()));  // moves the bar
    chaincont(totcalc(juulsticc.ButtonA.pressing(), juulsticc.ButtonB.pressing()));  //controls the chain
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}
