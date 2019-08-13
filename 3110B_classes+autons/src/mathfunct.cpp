#include "vex.h"

using namespace vex;

int sgn(int a){
  ((a > 0) ?  a=1 : (a<0) ? a = -1 : a = 0);
  return a;
}
int totcalc(int a, int b){
  int c = 100*(a - b);
  return c;
}