#include "main.h"


///////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*           PROS Driver Control Program            */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/*  Purpose: To Provide the ability to drive and    */
/*  control the robot during ther driver control    */
/*  period.                                         */
/*                                                  */
/*            Date Written: 29/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

//uses the Left analog joysticc, a and b, and limiting constants c and d, to drive the chassis motors
void dcontrol::dfunctions::drive(double a, double b, double c, double d){
  double motorl = (a/c + b/d);  //calculates the left motor by limiting a and b and then adding them
  double motorr = (a/c - b/d); //calculates the left motor by limiting a and b and then subtracting b from a
  fl = motorl; //24 to 27 set the respective motors to spin the direction they need to
  bl = motorl;
  fr = motorr;
  br = motorr;
}

//uses the double values a and b to to find the value to be used for the pusher
void dcontrol::dfunctions::push(double a, double b){
  double c = 127*(a-b);
  pusher = c;
}

//controls the chain through the use of the Digital Values for buttons pushed in opcontrol.cpp
void dcontrol::dfunctions::chainspin(double a, double b){
  double c = 127*(a-b);//calculates the direction by multiplying the difference by 127, the analog constant in this case
  lc = c;
  rc = -c; //spins the chain motors at the speed calculated above
}

//controls the bar through the use of the Digital Values for buttons pushed in opcontrol.cpp
void dcontrol::dfunctions::barlift(double a, double b){
  double c = 127*(a-b); //calculates the direction by multiplying the difference by 127, the analog constant in this case
  bar = c;  //spins the bar motor at the speed calculated above
}
