#include "vex.h"

using namespace vex;

// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
vex::controller juulsticc;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain thinkboi;

vex::motor FL(vex::PORT1, true);
vex::motor BL(vex::PORT11, true);
vex::motor FR(vex::PORT2, false);
vex::motor BR(vex::PORT12, false);
vex::motor pusher(vex::PORT13);
vex::motor bar(vex::PORT14);
vex::motor chain1(vex::PORT15, true);
vex::motor chain2(vex::PORT16, false);
vex::bumper F(thinkboi.ThreeWirePort.C);
vex::bumper B(thinkboi.ThreeWirePort.A);
vex::motor_group L(FL, BL);
vex::motor_group R(FR, BR);
vex::motor_group chain(chain1, chain2);