#include "main.h"

//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*              PROS Autonomous Code                */
/*                                                  */
/*         Created By: Victor Radoslavov            */
/*                                                  */
/*  Purpose: To Run the autonomous Program Selected */
/*  in the autonomous picker                        */
/*                                                  */
/*            Date Written: 27/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

double Ku;
double Pu;
double Kp;
double Ki;
double Kd;
int error;
int pError = 0;
int target;
int encoderValue;
double integral;
double derivative;
mcontrol::mfunctions autonomouscontrol;


//Red Autonomous
void acontrol::autons::aprogram1(){
  autonomouscontrol.dControl = false;
  do{
    error = target - encoderValue;
    double * arr = Pid.pidCalc(error, pError, integral, derivative, Kp, Ki, Kd);
    autonomouscontrol.drive(arr[0], 0, 2, 1);
    integral = arr[1];
    pError = error;
  }while(error!=0);
}
void acontrol::autons::aprogram2(){}
void acontrol::autons::aprogram3(){}
void acontrol::autons::aprogram4(){}

//Blue Autonomous
void acontrol::autons::aprogram5(){}
void acontrol::autons::aprogram6(){}
void acontrol::autons::aprogram7(){}
void acontrol::autons::aprogram8(){}

//Skills Autonomous
void acontrol::autons::skills(){}

//No Autonomous
void acontrol::autons::doNothing(){}
