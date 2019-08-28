#include "vex.h"

using namespace vex;

void barlift(){
  if(juulsticc.ButtonL1.pressing()){
    bar.spin(fwd, 50, pct);
  }
  else if(juulsticc.ButtonL2.pressing()){
    bar.spin(fwd, -50, pct);
  }
  else{
    bar.spin(fwd, 0, pct);
  }
}