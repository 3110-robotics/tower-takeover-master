#include "vex.h"

using namespace vex;

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
/*            Date Written: 17/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

void dcontrol::chaincont(int a){
  //chain movement value is calculated using the totcalc function, and it is entered here, and run
  chain.spin(fwd, a, pct);
}