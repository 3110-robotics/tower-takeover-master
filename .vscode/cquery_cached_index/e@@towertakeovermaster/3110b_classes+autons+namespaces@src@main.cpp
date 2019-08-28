#include "vex.h"

using namespace vex;

int main() {
    Competition.autonomous( aprograms::auton );  //standard competition callbacks
    Competition.drivercontrol( dcontrol::usercontrol );
    
    //Run the pre-autonomous function. 
    aprograms::pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
       
}