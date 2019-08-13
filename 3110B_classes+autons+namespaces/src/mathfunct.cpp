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

int dcontrol::sgn(int a){
  //signum function for drive calculations
  ((a > 0) ?  a=1 : (a<0) ? a = -1 : a = 0);
  return a;
}
int dcontrol::totcalc(int a, int b){
  int c = 100*(a - b);
  return c;
}