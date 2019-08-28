#include "main.h"

///////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*           PROS Driver Control Namespace          */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/*  Purpose: To isolate the driver control functio- */
/*  ns and allow for expandability of both driver   */
/*  control and autonomous programming              */
/*                                                  */
/*            Date Written: 30/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////
namespace mcontrol{
  class mfunctions{
    public:
      bool dControl;
      void drive(int8_t a, int8_t b, float c, float d);
      void push(int8_t a, int8_t b);
      void barlift(int8_t a, int8_t b);
      void chainspin(int8_t a, int8_t b);
  };
}

void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);

//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*            PROS Autonomous Namespace             */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/*  Purpose: To isolate the autonomous control      */
/*  functions and allow for expandability of both   */
/*  driver control and autonomous programming       */
/*                                                  */
/*            Date Written: 30/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

namespace acontrol{
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
      void skills();
      void doNothing();
      void PIDTuner();
  };
  class pid{
    private:
      int dT;
    public:
      int get_dT();
      void set_dT(float dT);
      std::pair<int, int> pidCalc(float error, float pError, float integral, float derivative, float Kp, float Ki, float Kd);
  };
}

//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*                PROS PID Namespace                */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/*  Purpose: To isolate the PID control functions   */
/*  and allow for expandability of both the PID     */
/*  alongside driver control and autonomous progr-  */
/*  amming                                          */
/*                                                  */
/*            Date Written: 01/08/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////


extern mcontrol::mfunctions drivercontrol;
extern mcontrol::mfunctions autonomouscontrol;
extern acontrol::autons Autons;
extern acontrol::pid Pid;
