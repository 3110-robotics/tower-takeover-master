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
  Pid.set_dT(15);
  auton_type Type = static_cast<auton_type>(count);
  switch (Type){
    case n: Autons.doNothing();    //Doing Nothing
    case r1: Autons.aprogram1();   //1-4 Red Programs
    case r2: Autons.aprogram2();
    case r3: Autons.aprogram3();
    case r4: Autons.aprogram4();
    case b1: Autons.aprogram5();   //5-8 Blue Programs
    case b2: Autons.aprogram6();
    case b3: Autons.aprogram7();
    case b4: Autons.aprogram8();
    case s: Autons.skills();
    case PIDTune: Autons.PIDTuner();
    default: Autons.doNothing();   //sets up an error catcher to run nothing in the event of an auton picker error
  }
}
