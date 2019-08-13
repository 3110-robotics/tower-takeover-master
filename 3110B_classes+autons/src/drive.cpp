#include "vex.h"

using namespace vex;


void drive(int a, int b, int c, int d){
  thinkboi.Screen.clearScreen();
  int motorl = (a/c + b/d);
  int motorr = (a/c - b/d);
  ((motorl > 100) ? motorl = sgn(motorl) * 100: motorl);
  ((motorr > 100) ? motorr = sgn(motorr) * 100: motorr);
  L.spin(fwd, motorl, pct);
  R.spin(fwd, motorr, pct);
}