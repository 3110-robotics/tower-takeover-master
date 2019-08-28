#include "vex.h"

using namespace vex;

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

void aprograms::auton( void ) {
  //creates an object from the autons class from the aprograms Namespace and uses a switch statement to determine which auton will be run
  autons Autons;
  switch(count){
    case 0: Autons.nothing();     //Doing Nothing
    case 1: Autons.aprogram1();   //1-4 Red Programs
    case 2: Autons.aprogram2();
    case 3: Autons.aprogram3();
    case 4: Autons.aprogram4();
    case 5: Autons.aprogram5();   //5-8 Blue Programs
    case 6: Autons.aprogram6();
    case 7: Autons.aprogram7();
    case 8: Autons.aprogram8();
    default: Autons.nothing();   //sets up an error catcher to run nothing in the event of an auton picker error
  }
}