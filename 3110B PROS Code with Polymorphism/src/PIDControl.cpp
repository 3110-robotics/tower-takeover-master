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

double * acontrol::pid::pidCalc(int error, int pError, double integral, double derivative, double Kp, double Ki, double Kd){
  error = error * Kp;
  integral = Ki * (integral + error);
  ((error == 0 || abs(error) > 10000) ? integral = 0: integral);
  derivative = Kd * (error - pError);
  double final = error + integral + derivative;
  double * results = new double[2];
  results[0] = final;
  results[1] = integral;
  pros::Task::delay(dT);
  return results;
  delete[] results;
}
