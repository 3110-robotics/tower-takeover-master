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
/*            Date Written: 30/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

mcontrol::mfunctions drivercontrol;  //creates the driver control object for the driver functions

void opcontrol() {
	drivercontrol.dControl = true;
	while (true) {
		drivercontrol.drive(juulsticc.get_analog(ANALOG_LEFT_Y), juulsticc.get_analog(ANALOG_LEFT_X), 1.5, 3);	//uses the analog left stick to drive the chassis motors
	  drivercontrol.push(juulsticc.get_digital(DIGITAL_R1), juulsticc.get_digital(DIGITAL_R2));  //uses the digital r1 and r2 to push or retract the stack holder
		drivercontrol.barlift(juulsticc.get_digital(DIGITAL_L1), juulsticc.get_digital(DIGITAL_L2));  //uses the digital l1 and l2 to move the bar which has the chain attached to it
		drivercontrol.chainspin(juulsticc.get_digital(DIGITAL_A), juulsticc.get_digital(DIGITAL_B)); //uses the digital a and b buttons to mo
		pros::delay(20);
	}
}
