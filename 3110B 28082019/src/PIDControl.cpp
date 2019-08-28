#include "main.h"

///////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*       PROS PID Control For Autonomous Use        */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/*  Purpose: To create a PID system independent of  */
/*  VEX's solution of a motor-integrated PID for    */
/*  better co-operation with our team's hardware    */
/*  and software                                    */
/*                                                  */
/*            Date Written: 01/08/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

acontrol::pid Pid;

std::pair<int, int> acontrol::pid::pidCalc(float error, float pError, float integral, float derivative, float Kp, float Ki, float Kd){
  error = error * Kp;
  integral = Ki * (integral + error);
  ((error == 0 || fabs(error) > 10000) ? integral = 0: integral);
  derivative = Kd * (error - pError);
  double final = error + integral + derivative;
  pros::Task::delay(dT);
  return std::make_pair(final, integral);
}

int acontrol::pid::get_dT(){
  return this->dT;
}

void acontrol::pid::set_dT(float dT){
  this->dT = dT;
}
