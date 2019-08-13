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
      void drive(double a, double b, double c, double d);
      void push(double a, double b);
      void barlift(double a, double b);
      void chainspin(double a, double b);
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
  class aselector{
    public:
      void style_setter(lv_style_t style, uint8_t r1, uint8_t b1, uint8_t g1, uint8_t r2, uint8_t g2, uint8_t b2, uint8_t r3, uint8_t g3, uint8_t b3);
      void button_create(lv_obj_t * myButton, lv_style_t stylerel, lv_style_t stylepr, lv_align_t, uint8_t place, uint8_t myWidth, uint8_t myHeight);
      void button_label_create(lv_obj_t * myButtonLabel, lv_obj_t * myButton, const char * label);
      void label_create(lv_obj_t * myLabel, lv_align_t align, const char * text);
      static lv_res_t btn_click_action(lv_obj_t * a);
      void clear_screen();
  };
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
  };
  class pid{
    public:
      int dT;
      double * pidCalc(int error, int pError, double integral, double derivative, double Kp, double Ki, double Kd);
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
extern acontrol::aselector aSelector;
extern acontrol::autons Autons;
extern acontrol::pid Pid;
