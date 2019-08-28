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


void acontrol::autons::autonTriggerer(auton_type Type){
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
    case p: Autons.PIDTuner();
    default: Autons.doNothing();   //sets up an error catcher to run nothing in the event of an auton picker error
  }
}

void autonomous() {
  Pid.dT = 15;
  switch (count){
    case 0: Autons.autonTriggerer(n);    //Doing Nothing
    case 1: Autons.autonTriggerer(r1);   //1-4 Red Programs
    case 2: Autons.autonTriggerer(r2);
    case 3: Autons.autonTriggerer(r3);
    case 4: Autons.autonTriggerer(r4);
    case 5: Autons.autonTriggerer(b1);   //5-8 Blue Programs
    case 6: Autons.autonTriggerer(b2);
    case 7: Autons.autonTriggerer(b3);
    case 8: Autons.autonTriggerer(b4);
    case 9: Autons.autonTriggerer(s);
    default: Autons.autonTriggerer(n);   //sets up an error catcher to run nothing in the event of an auton picker error
  }
}
