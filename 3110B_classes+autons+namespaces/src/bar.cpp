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

void dcontrol::barlift(int a){
  //within the driver control, the l1 and l2 are subtracted and multiplied by 100, to get the motor spinning, and then, halving it for less speed
  bar.spin(fwd, a/2, pct);
}