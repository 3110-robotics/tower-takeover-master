#include "vex.h"

using namespace vex;

// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
vex::controller juulsticc;



/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

void autonomous( void ) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................

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

void usercontrol( void ) {
  // User control code here, inside the loop
  int speedlim = 2;
  int turnlim = 3;
  while (1) {
    drive(juulsticc.Axis3.value(), juulsticc.Axis4.value(), speedlim, turnlim);
    pushyboi(juulsticc.ButtonR1.pressing(), juulsticc.ButtonR2.pressing());
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
       
}