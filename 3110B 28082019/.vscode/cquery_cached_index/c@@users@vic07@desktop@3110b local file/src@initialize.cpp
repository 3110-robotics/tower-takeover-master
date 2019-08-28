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
/*            Date Written: 28/08/2019              */
/*                                                  */
/*                                                  */
//////////////////////////////////////////////////////

const char * autonModes[11];  //creates the variable to store the autonomous mode strings
int count = 0;  //creates a variable to store the count of the autonModes variable

lv_obj_t * nBut;    //next button variables
lv_obj_t * nButLabel;

lv_obj_t * pBut;    //previous button variables
lv_obj_t * pButLabel;

lv_obj_t * confBut;   //confirm button variables
lv_obj_t * confButLabel;

lv_obj_t * rBut;     //run autonomous button variables
lv_obj_t * rButLabel;

lv_obj_t * autonLabel;  //autonomous label

lv_obj_t * batLabel;

lv_style_t norButtonStyleREL; //creates released and pressed normal button style
lv_style_t norButtonStylePR;

lv_style_t confButtonStyleREL; //creates confirmatory released and pressed button style
lv_style_t confButtonStylePR;

lv_style_t rButtonStyleREL;  //creates autonomous running button pressed and released style
lv_style_t rButtonStylePR;

static lv_res_t btn_click_action(lv_obj_t * a){

  uint8_t id = lv_obj_get_free_num(a); //gets the position of the button, for acting on in the if statements
  if(id <= 1){
    count+=(id = 0 ? 1 : -1);
    count %= 11;

    return LV_RES_OK;
  }
  lv_obj_clean(lv_scr_act());

  batLabel = lv_label_create(lv_scr_act(), NULL);
  lv_obj_align(batLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 0);

  if(id == 3){
    autonomous();
  }
  return LV_RES_INV;
}

void batFunct(void * param){
  while (true){
    std::string vBuffer;
    vBuffer += " ";
    vBuffer += pros::battery::get_capacity();
    lv_label_set_text(batLabel, vBuffer.c_str());
    pros::Task::delay(50);
  }
}

void autonLFunct(void * param){
  while (true){
    try{
      lv_label_set_text(autonLabel, autonModes[count]);
    }
    catch(const std::exception& e){
      break;
    }
    pros::Task::delay(20);
  }
}

void initialize() {
  lv_obj_t * scr = lv_page_create(NULL, NULL);

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
  autonModes[10] = "PID Autonomous Tuning Program";
  /*
  there are many many declarations for these GUi. I wrote all of these out, not through functions, because the functions werent working and didnt produce GUI. I will look into it soon.
  */
  lv_style_copy(&norButtonStyleREL, &lv_style_plain);
  norButtonStyleREL.body.main_color = LV_COLOR_MAKE(143, 143, 143);
  norButtonStyleREL.body.grad_color = LV_COLOR_MAKE(69, 69, 69);
  norButtonStyleREL.body.radius = 0;
  norButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

  lv_style_copy(&norButtonStylePR, &lv_style_plain);
  norButtonStylePR.body.main_color = LV_COLOR_MAKE(100, 100, 100);
  norButtonStylePR.body.grad_color = LV_COLOR_MAKE(20, 20, 20);
  norButtonStylePR.body.radius = 0;
  norButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

  lv_style_copy(&confButtonStyleREL, &lv_style_plain);
  confButtonStyleREL.body.main_color = LV_COLOR_MAKE(12, 255, 0);
  confButtonStyleREL.body.grad_color = LV_COLOR_MAKE(143, 0, 255);
  confButtonStyleREL.body.radius = 0;
  confButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

  lv_style_copy(&confButtonStylePR, &lv_style_plain);
  confButtonStylePR.body.main_color = LV_COLOR_MAKE(40, 115, 36);
  confButtonStylePR.body.grad_color = LV_COLOR_MAKE(64, 97, 62);
  confButtonStylePR.body.radius = 0;
  confButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

  lv_style_copy(&rButtonStyleREL, &lv_style_plain);
  rButtonStyleREL.body.main_color = LV_COLOR_MAKE(255, 0, 0);
  rButtonStyleREL.body.grad_color = LV_COLOR_MAKE(128, 1, 1);
  rButtonStyleREL.body.radius = 0;
  rButtonStyleREL.text.color = LV_COLOR_MAKE(255, 255, 255);

  lv_style_copy(&rButtonStylePR, &lv_style_plain);
  rButtonStylePR.body.main_color = LV_COLOR_MAKE(153, 52, 52);
  rButtonStylePR.body.grad_color = LV_COLOR_MAKE(89, 57, 57);
  rButtonStylePR.body.radius = 0;
  rButtonStylePR.text.color = LV_COLOR_MAKE(255, 255, 255);

  nBut = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
  lv_obj_set_free_num(nBut, 0); //set button pos
  lv_btn_set_action(nBut, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
  lv_btn_set_style(nBut, LV_BTN_STYLE_REL, &norButtonStyleREL); //set the relesed style
  lv_btn_set_style(nBut, LV_BTN_STYLE_PR, &norButtonStylePR); //set the pressed style
  lv_obj_set_size(nBut, 200, 50); //set the button size
  lv_obj_align(nBut, NULL, LV_ALIGN_IN_TOP_RIGHT, 10, 10); //set the position to top mid

  pBut = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
  lv_obj_set_free_num(pBut, 1); //set button pos
  lv_btn_set_action(pBut, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
  lv_btn_set_style(pBut, LV_BTN_STYLE_REL, &norButtonStyleREL); //set the relesed style
  lv_btn_set_style(pBut, LV_BTN_STYLE_PR, &norButtonStylePR); //set the pressed style
  lv_obj_set_size(pBut, 200, 50); //set the button size
  lv_obj_align(pBut, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 10, 10); //set the position to top mid

  confBut = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
  lv_obj_set_free_num(confBut, 2); //set button pos
  lv_btn_set_action(confBut, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
  lv_btn_set_style(confBut, LV_BTN_STYLE_REL, &confButtonStyleREL); //set the relesed style
  lv_btn_set_style(confBut, LV_BTN_STYLE_PR, &confButtonStylePR); //set the pressed style
  lv_obj_set_size(confBut, 200, 50); //set the button size
  lv_obj_align(confBut, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 10, 10); //set the position to top mid

  rBut = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
  lv_obj_set_free_num(rBut, 3); //set button pos
  lv_btn_set_action(rBut, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
  lv_btn_set_style(rBut, LV_BTN_STYLE_REL, &norButtonStyleREL); //set the relesed style
  lv_btn_set_style(rBut, LV_BTN_STYLE_PR, &norButtonStylePR); //set the pressed style
  lv_obj_set_size(rBut, 200, 50); //set the button size
  lv_obj_align(rBut, NULL, LV_ALIGN_IN_BOTTOM_MID, 10, 10); //set the position to top mid

  nButLabel = lv_label_create(nBut, NULL); //creates the label on the button
  lv_label_set_text(nButLabel, "Next");  //Sets the text for the button

  pButLabel = lv_label_create(pBut, NULL); //creates the label on the button
  lv_label_set_text(pButLabel, "Previous");  //Sets the text for the button

  confButLabel = lv_label_create(confBut, NULL); //creates the label on the button
  lv_label_set_text(confButLabel, "Confirm");  //Sets the text for the button

  nButLabel = lv_label_create(nBut, NULL); //creates the label on the button
  lv_label_set_text(nButLabel, "Next");  //Sets the text for the button

  autonLabel = lv_label_create(lv_scr_act(), NULL); //creates the label
  lv_label_set_text(autonLabel, autonModes[count]);  //sets the text within it
  lv_obj_align(autonLabel, NULL, LV_ALIGN_IN_LEFT_MID, 10, 0); //aligns the label

  batLabel = lv_label_create(lv_scr_act(), NULL);

  const char * batTaskName = "Battery Task";
  pros::Task batTask(batFunct, &batTaskName);

  const char * autonLName = "Auton label Task";
  pros::Task autonLTask(autonLFunct, &autonLName);
}

void disabled() {}

void competition_initialize() {}
