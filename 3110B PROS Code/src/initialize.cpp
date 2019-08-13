#include "main.h"

//////////////////////////////////////////////////////
/*                                                  */
/*                                                  */
/*              PROS Autonomous Picker              */
/*                                                  */
/*          Created By: Victor Radoslavov           */
/*                                                  */
/* Purpose: To create a graphical UI in order to    */
/* control the autonomous program triggered in the  */
/* autonomous phase.                                */
/*                                                  */
/*            Date Written: 30/07/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

lv_obj_t * nBut;    //next button variables
lv_obj_t * nButLabel;

lv_obj_t * pBut;    //previous button variables
lv_obj_t * pButLabel;

lv_obj_t * confBut;   //confirm button variables
lv_obj_t * confButLabel;

lv_obj_t * rBut;     //run autonomous button variables
lv_obj_t * rButLabel;

lv_obj_t * autonLabel;  //autonomous label

lv_style_t norButtonStyleREL; //creates released and pressed normal button style
lv_style_t norButtonStylePR;

lv_style_t confButtonStyleREL; //creates confirmatory released and pressed button style
lv_style_t confButtonStylePR;

lv_style_t rButtonStyleREL;  //creates autonomous running button pressed and released style
lv_style_t rButtonStylePR;

acontrol::aselector aSelector;  //creates the autonomous selector object for the selection functions

void initialize() {
  autonModes[0] = "Do Nothing";                   //Declares all of the auton Label posibilities
  autonModes[1] = "Red Big Zone - No Towers";
  autonModes[2] = "Red Small Zone - No Towers";
  autonModes[3] = "Red Small Zone - Same Towers";
  autonModes[4] = "Red Small Zone - Mixed Towers";
  autonModes[5] = "Blue Big Zone - No Towers";
  autonModes[6] = "Blue Small Zone - No Towers";
  autonModes[7] = "Blue Small Zone - Same Towers";
  autonModes[8] = "Blue Small Zone - Mixed Towers";
  autonModes[9] = "Skills Autonomous Program";
  aSelector.style_setter(norButtonStyleREL, 143, 143, 143, 69, 69, 69, 255, 255, 255);  //sets up all of the released and pressed styles
  aSelector.style_setter(norButtonStylePR, 61, 61, 61, 0, 0, 0, 255, 255, 255);
  aSelector.style_setter(confButtonStyleREL, 13, 255, 0, 7, 143, 0, 255, 255, 255);
  aSelector.style_setter(confButtonStylePR, 40, 115, 36, 64, 97, 62, 255, 255, 255);
  aSelector.style_setter(rButtonStyleREL, 255, 0, 0, 128, 1, 1, 255, 255, 255);
  aSelector.style_setter(rButtonStylePR, 153, 52, 52, 89, 57, 57, 255, 255, 255);

  aSelector.button_create(nBut, norButtonStyleREL, norButtonStylePR, LV_ALIGN_IN_TOP_MID, 0, 80, 80); //creates the buttons
  aSelector.button_create(pBut, norButtonStyleREL, norButtonStylePR, LV_ALIGN_IN_BOTTOM_RIGHT, 1, 80, 80);
  aSelector.button_create(confBut, confButtonStyleREL, confButtonStylePR, LV_ALIGN_IN_BOTTOM_LEFT, 2, 80, 80);
  aSelector.button_create(rBut, rButtonStyleREL, rButtonStylePR, LV_ALIGN_IN_BOTTOM_MID, 3, 40, 120);

  aSelector.button_label_create(nButLabel, nBut, "Next");   //labels the buttons
  aSelector.button_label_create(pButLabel, pBut, "Previous");
  aSelector.button_label_create(confButLabel, confBut, "Confirm");
  aSelector.button_label_create(rButLabel, rBut, "Run Autonomous");

  aSelector.label_create(autonLabel, LV_ALIGN_IN_TOP_LEFT, autonModes[count]);  //creates the label
}

void disabled() {}

void competition_initialize() {}
