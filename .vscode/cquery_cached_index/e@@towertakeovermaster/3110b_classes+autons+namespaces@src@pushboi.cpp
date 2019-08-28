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

void dcontrol::pushyboi(int a){
  //uses the booleans a and b, defined in the drivercontrol program as the r1 and r2 buttons, and depending on which one is true, the pusher will push the stack forwards or back 
  if(sgn(a) == -1 && B.pressing()){pusher.spin(fwd, 0, pct);}
  else{pusher.spin(fwd,a,pct);}
}