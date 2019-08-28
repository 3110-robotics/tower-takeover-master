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

const char * autonModes[11];  //creates the variable to store the autonomous mode strings
int count = 0;  //creates a variable to store the count of the autonModes variable

//style_setter sets the settings of the inputted style, using the plain button style and the rgb values given here
void acontrol::aselector::style_set(){
  lv_style_copy(&Style, &lv_style_plain);  //sets the style to plain
  Style.body.main_color = LV_COLOR_MAKE(stylergb[0][0], stylergb[0][1], stylergb[0][2]); // sets the colours of the style
  Style.body.grad_color = LV_COLOR_MAKE(stylergb[1][0], stylergb[1][1], stylergb[1][2]);
  Style.body.radius = 0;
  Style.text.color = LV_COLOR_MAKE(stylergb[2][0], stylergb[2][1], stylergb[2][2]);
}
void acontrol::aselector::style_setter(lv_style_t style, uint8_t r1, uint8_t b1, uint8_t g1, uint8_t r2, uint8_t g2, uint8_t b2, uint8_t r3, uint8_t g3, uint8_t b3){
  this->Style = style;
  for (int i = 0; i<9; i++){
    this->stylergb[i / 3][i % 3] = (i == 0 ? r1 : i == 1 ? b1 : i == 2 ? g1 : i == 3 ? r2 : i == 4 ? g2 : i == 5 ? b2 : i == 6 ? r3 : i == 7 ? g3 : i == 8 ? b3 : 0);
  }
  style_set();
}

void acontrol::aselector::clear_screen(){
  lv_obj_clean(nBut);     //clears the Buttons and Labels
  lv_obj_clean(nButLabel);
  lv_obj_clean(pBut);
  lv_obj_clean(pButLabel);
  lv_obj_clean(confBut);
  lv_obj_clean(confButLabel);
  lv_obj_clean(rBut);
  lv_obj_clean(rButLabel);
  lv_obj_clean(autonLabel);
}
//btn_click_action runs when a button is clicked, and depending on what is clicked, the switch will run the code
lv_res_t acontrol::aselector::btn_click_action(lv_obj_t * a){
  uint8_t id = lv_obj_get_free_num(a); //gets the position of the button, for acting on in the switch
  char buffer[100];
  switch(id){ //triggers a 4 way switch
    case 0: count+=1; (count>10 ? count=0:count); sprintf(buffer, "%s", autonModes[count]); lv_label_set_text(autonLabel, buffer); id = 4;//increases count and updates the auton Mode label
    case 1: count-=1; (count<0 ? count=10:count); sprintf(buffer, "%s", autonModes[count]); lv_label_set_text(autonLabel, buffer); id = 4;//decreases count and updates the auton Mode label
    case 2: return LV_RES_OK; aSelector.clear_screen(); id = 4;//finishes and waits
    case 3: return LV_RES_OK; aSelector.clear_screen(); autonomous(); id = 4;//finishes and runs autonomous
    case 4: break;
    default: break;
  }
  return LV_RES_OK; //finishes in case of an error
}
void acontrol::aselector::button_creater(){
  myButton = lv_btn_create(lv_scr_act(), NULL);  //creates the button object
  lv_obj_set_free_num(myButton, mybLocation[0]);  //sets it's identifyer to "place" for access in the btn_click_action
  lv_btn_set_action(myButton, LV_BTN_ACTION_CLICK, aSelector.btn_click_action);  //sets its action when pressed to be running the btn_click_action
  lv_btn_set_style(myButton, LV_BTN_STYLE_REL, &bStyles[0]);  //sets the released style to the stylerel
  lv_btn_set_style(myButton, LV_BTN_STYLE_PR, &bStyles[1]); //sets the pressed style to the stylepr
  lv_obj_set_size(myButton, mybLocation[1], mybLocation[2]); //sets the button's height and width
  lv_obj_align(myButton, NULL, balign, 0, 0); //set the button alignment
}
//button_create creates a button with the name, style released, style pressed, alignment location, it's position both in the button list and on the screen
void acontrol::aselector::button_create(lv_obj_t * myButton, lv_style_t stylerel, lv_style_t stylepr, lv_align_t align, uint8_t place, uint8_t myWidth, uint8_t myHeight){
  this->myButton = myButton;
  this->bStyles[0] = stylerel;
  this->bStyles[1] = stylepr;
  this->balign = align;
  this->mybLocation[0] = place;
  this->mybLocation[1] = myWidth;
  this->mybLocation[2] = myHeight;
  button_creater();
}
void acontrol::aselector::button_label_creater(){
  bLabelObjects[0] = lv_label_create(bLabelObjects[1], NULL); //creates the label on the button
  lv_label_set_text(bLabelObjects[0], label);  //Sets the text for the button
}

//creates the labels for buttons. uses the button Label object, the Button object, and a const char label
void acontrol::aselector::button_label_create(lv_obj_t * myButtonLabel, lv_obj_t * myButton, const char * label){
  this->bLabelObjects[0] = myButtonLabel;
  this->bLabelObjects[1] = myButton;
  this->label = label;
}

void acontrol::aselector::label_creater(){
  mylLabel = lv_label_create(lv_scr_act(), NULL); //creates the label
  lv_label_set_text(mylLabel, text);  //sets the text within it
  lv_obj_align(mylLabel, NULL, lAlign, 10, 0); //aligns the label
}
//creates label with attributes of the Label, the alignment and the text within it as a const char
void acontrol::aselector::label_create(lv_obj_t * myLabel, lv_align_t align, const char * text){
  this->mylLabel = myLabel;
  this->lAlign = align;
  this->text = text;
  label_creater();
}
