#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain thinkboi;

vex::motor FL(vex::PORT1, true);
vex::motor BL(vex::PORT11, true);
vex::motor FR(vex::PORT2, false);
vex::motor BR(vex::PORT12, false);
vex::motor pusher(vex::PORT13);
vex::motor_group L(FL, BL);
vex::motor_group R(FR, BR);

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
/*            Date Written: 05/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

int sgn(int a){
  //Signum mathematical function, used as a hard limit on the motor strengh on the drive
  ((a > 0) ?  a=1 : (a<0) ? a = -1 : a = 0);
  return a;
}
void drive(int a, int b, int c, int d){
  //single stick arcade drive, with divisiors for a soft limit
  int motorl = (a/c + b/d); //defines the left and right motor values
  int motorr = (a/c - b/d);
  ((motorl > 100) ? motorl = sgn(motorl) * 100: motorl); //apply the hard limit "buffer"
  ((motorr > 100) ? motorr = sgn(motorr) * 100: motorr);
  FL.spin(fwd, motorl, pct); //moves the drive motors based on 
  FR.spin(fwd, motorr, pct);
  BL.spin(fwd, motorl, pct);
  BR.spin(fwd, motorr, pct);
}
void pushyboi(bool a, bool b){
  //2 Booleans check what buttons are pressed, and from there spin the motors based on them
  if(a){pusher.spin(fwd, 100, pct);}
  else if(b){pusher.spin(fwd,-100,pct);}
  else{pusher.spin(fwd, 0, pct);}
}