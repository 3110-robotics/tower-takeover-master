//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*        PROS Global Object Initialisation         */
/*                                                  */
/*         Created By: Victor Radoslavov            */
/*                                                  */
/*  Purpose: To declare the objects to be used glo- */
/*  bally and, in the header file, to be accessed   */
/*  project-wide                                    */
/*                                                  */
/*                                                  */
/*            Date Written: 27/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

#include "main.h"
extern pros::Controller juulsticc;
extern pros::Motor fl;
extern pros::Motor bl;
extern pros::Motor fr;
extern pros::Motor br;
extern pros::Motor pusher;
extern pros::Motor bar;
extern pros::Motor lc;
extern pros::Motor rc;

extern lv_obj_t * nBut;
extern lv_obj_t * nButLabel;
extern lv_obj_t * pBut;
extern lv_obj_t * pButLabel;
extern lv_obj_t * confBut;
extern lv_obj_t * confButLabel;
extern lv_obj_t * rBut;
extern lv_obj_t * rButLabel;
extern lv_obj_t * autonLabel;
extern lv_style_t norButtonStyleREL;
extern lv_style_t norButtonStylePR;
extern lv_style_t confButtonStyleREL;
extern lv_style_t confButtonStylePR;
extern lv_style_t rButtonStyleREL;
extern lv_style_t rButtonStylePR;

extern const char * autonModes[10];
extern int count;
