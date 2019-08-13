#include "vex.h"

using namespace vex;


int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( auton );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }
       
}