/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       vex.h                                                     */
/*    Author:       Vex Robotics                                              */
/*    Created:      1 Feb 2019                                                */
/*    Description:  Default header for V5 projects                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "v5.h"
#include "v5_vcs.h"

void drive(int a, int b, int c, int d);
void pushyboi(bool a, bool b);
void Where_Pressed();
void Picking(vex::color colors,int padding, char label);

extern vex::brain thinkboi;
extern int count;
extern bool autonDone;