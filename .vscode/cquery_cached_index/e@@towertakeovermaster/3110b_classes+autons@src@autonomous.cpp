#include "vex.h"

using namespace vex;

void auton( void ) {
  autons Autons;
  switch(count){
    case 0: Autons.nothing();
    case 1: Autons.aprogram1();
    case 2: Autons.aprogram2();
    case 3: Autons.aprogram3();
    case 4: Autons.aprogram4();
    case 5: Autons.aprogram5();
    case 6: Autons.aprogram6();
    case 7: Autons.aprogram7();
    case 8: Autons.aprogram8();
  }
}