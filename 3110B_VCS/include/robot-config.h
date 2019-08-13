///////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*         Standard C++ Pro Header for VCS          */
/*                                                  */
/*          Created By: Vex Coding Studio           */
/*                                                  */
/*  Purpose: To create a global region for libraries*/
/*  to be declared and for motors to be defined     */
/*                                                  */
/*                                                  */
/*            Date Written: 05/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "v5.h"
#include "v5_vcs.h"

using namespace vex;
vex::brain Brain;
vex::motor FL (vex::PORT1, vex::gearSetting::ratio18_1,true);
vex::motor FR (vex::PORT2, vex::gearSetting::ratio18_1,false);
vex::motor BL (vex::PORT11, vex::gearSetting::ratio18_1,true);
vex::motor BR (vex::PORT12, vex::gearSetting::ratio18_1,false);
vex::motor Pushyboi (vex::PORT13, vex::gearSetting::ratio36_1,false);
vex::controller Controller1;
vex::competition Competition;