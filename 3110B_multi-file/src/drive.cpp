#include "vex.h"

using namespace vex;

void drive(int a, int b, int c, int d){
  thinkboi.Screen.clearScreen();
  int motorl = (a/c + b/d);
  int motorr = (a/c - b/d);
  if(motorl > 100){motorl = sgn(motorl) * 100;}
  if(motorr > 100){motorl = sgn(motorr) * 100;}
  L.spin(fwd, motorl, pct);
  R.spin(fwd, motorr, pct);
  thinkboi.Screen.print("Left: %d, Right: %d", motorl, motorr);
}
