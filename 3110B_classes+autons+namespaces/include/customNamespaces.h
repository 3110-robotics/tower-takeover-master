
///////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*         VEXcode Driver Control Namespace         */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/*  Purpose: To isolate the driver control functio- */
/*  ns and allow for expandability of both driver   */
/*  control and autonomous programming              */
/*                                                  */
/*            Date Written: 27/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

namespace dcontrol{  
  void drive(int a, int b, int c, int d); //drive function
  void pushyboi(int a); //stack pusher function
  int sgn(int a); //Signum function for limiting functions
  void usercontrol(); //main user control 
  void barlift(int a); //Lifts the 2bar attached to the chain
  void chaincont(int a); //controls chain
  int totcalc(int a, int b); //uses a system to calculate a numerical value for motors which are either at full power or not at all
}
//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*           VEXcode Autonomous Namespace           */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/*  Purpose: To isolate the autonomous control      */
/*  functions and allow for expandability of both   */
/*  driver control and autonomous programming       */
/*                                                  */
/*            Date Written: 27/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

namespace aprograms{  
  void pre_auton(); //standard pre-autonomous code. Maybe removed from the autonomous namespace provided other use is found for it
  void auton();  //Autonomous triggering code, points to autonomous programs in the autons class
  void autonselect();  //autonomous selection code 
  void Picking(vex::color colors,int padding);   //colour picker for buttons
  void Where_Pressed(); //Pressed location determiner
  class autons{
    public:
      void aprogram1();
      void aprogram2(); 
      void aprogram3(); 
      void aprogram4(); 
      void aprogram5(); 
      void aprogram6(); 
      void aprogram7(); 
      void aprogram8(); 
      void nothing(); 
  };
}