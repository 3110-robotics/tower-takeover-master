#include "main.h"


//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*        PROS Global Object Initialisation         */
/*                                                  */
/*         Created By: Victor Radoslavov            */
/*                                                  */
/*  Purpose: To declare the objects to be used glo- */
/*  bally and, in the header file, to be accessed   */
/*  project-wide                                    */
/*                                                  */
/*                                                  */
/*            Date Written: 29/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

pros::Controller juulsticc(CONTROLLER_MASTER);          //declares the controller
pros::Motor fl(1,pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); //front left chassis motor
pros::Motor bl(11,pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES); //back left chassis motor
pros::Motor fr(2,pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); //front right chassis motor
pros::Motor br(12,pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_DEGREES); //back right chassis motor
pros::Motor pusher(13,pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES); //stack pusher motor
pros::Motor bar(14,pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES);  //2bar lift motor
pros::Motor lc(15,pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES); //left chain motor
pros::Motor rc(16,pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_DEGREES); //right chain motor
