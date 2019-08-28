#include "vex.h"

vex::competition Competition;

vex::controller juulsticc;

vex::brain thinkboi;

vex::motor FL(vex::PORT1, true);
vex::motor BL(vex::PORT11, true);
vex::motor FR(vex::PORT2, false);
vex::motor BR(vex::PORT12, false);
vex::motor pusher(vex::PORT13);
vex::motor_group L(FL, BL);
vex::motor_group R(FR, BR);
