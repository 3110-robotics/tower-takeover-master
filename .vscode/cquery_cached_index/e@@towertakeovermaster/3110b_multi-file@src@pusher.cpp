#include "vex.h"

using namespace vex;

void pushyboi(bool a, bool b){
  if(a){pusher.spin(fwd, 100, pct);}
  else if(b){pusher.spin(fwd,-100,pct);}
  else{pusher.spin(fwd, 0, pct);}
}