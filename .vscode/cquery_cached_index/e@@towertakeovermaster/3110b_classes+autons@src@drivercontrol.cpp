#include "vex.h"

using namespace vex;

void usercontrol( void ) {
  // User control code here, inside the loop
  int speedlim = 2;
  int turnlim = 3;
  while (1) {
    drive(juulsticc.Axis3.value(), juulsticc.Axis4.value(), speedlim, turnlim);
    pushyboi(juulsticc.ButtonR1.pressing(), juulsticc.ButtonR2.pressing());
    barlift();
    chaincont(totcalc(juulsticc.ButtonA.pressing(), juulsticc.ButtonB.pressing()));
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}
