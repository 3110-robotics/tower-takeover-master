
#include "vex.h"

using namespace vex;

//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*      VEXCode Global Object Initialisation        */
/*                                                  */
/*         Created By: Victor Radoslavov            */
/*                                                  */
/*  Purpose: To declare the objects to be used glo- */
/*  bally and, in the header file, to be accessed   */
/*  project-wide                                    */
/*                                                  */
/*                                                  */
/*            Date Written: 27/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////





competition Competition;
controller juulsticc;
brain thinkboi;
motor FL(PORT1, gearSetting::ratio18_1,true);
motor BL(PORT11, gearSetting::ratio18_1,true);
motor FR(PORT2, gearSetting::ratio18_1, false);
motor BR(PORT12, gearSetting::ratio18_1,false);
motor pusher(PORT13, gearSetting::ratio36_1, false);
motor bar(PORT14, gearSetting::ratio36_1, false);
motor chain1(PORT15, gearSetting::ratio18_1,true);
motor chain2(PORT16, gearSetting::ratio18_1,false);
bumper B(thinkboi.ThreeWirePort.A);
motor_group L(FL, BL);
motor_group R(FR, BR);
motor_group chain(chain1, chain2);