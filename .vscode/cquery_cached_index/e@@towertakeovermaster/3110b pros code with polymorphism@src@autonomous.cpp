#include "main.h"

//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*               PROS Autonomous Code               */
/*                                                  */
/*         Created By: Victor Radoslavov            */
/*                                                  */
/*  Purpose: To Run the autonomous Program Selected */
/*  in the autonomous picker                        */
/*                                                  */
/*            Date Written: 27/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

acontrol::autons Autons; //creates autons object for the autonomous functions

void autonomous() {
  Pid.dT = 15;
  switch (count){
    case 0: Autons.doNothing();    //Doing Nothing
    case 1: Autons.aprogram1();   //1-4 Red Programs
    case 2: Autons.aprogram2();
    case 3: Autons.aprogram3();
    case 4: Autons.aprogram4();
    case 5: Autons.aprogram5();   //5-8 Blue Programs
    case 6: Autons.aprogram6();
    case 7: Autons.aprogram7();
    case 8: Autons.aprogram8();
    case 9: Autons.skills();
    default: Autons.doNothing();   //sets up an error catcher to run nothing in the event of an auton picker error
  }
}
