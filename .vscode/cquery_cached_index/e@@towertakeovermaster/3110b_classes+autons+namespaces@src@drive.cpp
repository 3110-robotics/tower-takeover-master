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


void dcontrol::drive(int a, int b, int c, int d){
  //single stick arcade drive, with divisiors for a soft limit
  int motorl = (a/c + b/d);//defines the left and right motor values
  int motorr = (a/c - b/d);
  ((motorl > 100) ? motorl = sgn(motorl) * 100: motorl);//apply the hard limit "buffer"
  ((motorr > 100) ? motorr = sgn(motorr) * 100: motorr);
  L.spin(fwd, motorl, pct);//moves the drive motors based on the values
  R.spin(fwd, motorr, pct);
}