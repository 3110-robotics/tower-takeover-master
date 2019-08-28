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

const char * autonModes[10];  //creates the variable to store the autonomous mode strings
int count = 0;  //creates a variable to store the count of the autonModes variable

//style_setter sets the settings of the inputted style, using the plain button style and the rgb values given here
void acontrol::aselector::style_setter(lv_style_t style, uint8_t r1, uint8_t b1, uint8_t g1, uint8_t r2, uint8_t g2, uint8_t b2, uint8_t r3, uint8_t g3, uint8_t b3){
  lv_style_copy(&style, &lv_style_plain);  //sets the style to plain
  style.body.main_color = LV_COLOR_MAKE(r1, b1, g1); // sets the colours of the style
  style.body.grad_color = LV_COLOR_MAKE(r2, b2, g2);
  style.body.radius = 0;
  style.text.color = LV_COLOR_MAKE(r3, b3, g3);
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
  uint8_t id = lv_obj_get_free_num(a); //gets the position of the button
  char buffer[100];
  switch(id){ //triggers a 4 way switch
    case 0: count+=1;sprintf(buffer, "%s", autonModes[count]); lv_label_set_text(autonLabel, buffer); (count>9 ? count=0:count);//increases count and updates the auton Mode label
    case 1: count-=1;sprintf(buffer, "%s", autonModes[count]); lv_label_set_text(autonLabel, buffer); (count<0 ? count=8:count);  //decreases count and updates the auton Mode label
    case 2: return LV_RES_OK; aSelector.clear_screen();//finishes and waits
    case 3: return LV_RES_OK; aSelector.clear_screen(); autonomous(); //finishes and runs autonomous
  }
  return LV_RES_OK; //finishes in case of an error
}
//button_create creates a button with the name, style released, style pressed, alignment location, it's position both in the button list and on the screen
void acontrol::aselector::button_create(lv_obj_t * myButton, lv_style_t stylerel, lv_style_t stylepr, lv_align_t align, uint8_t place, uint8_t myWidth, uint8_t myHeight){
  myButton = lv_btn_create(lv_scr_act(), NULL);  //creates the button object
  lv_obj_set_free_num(myButton, place);  //sets it's identifyer to "place" for access in the btn_click_action
  lv_btn_set_action(myButton, LV_BTN_ACTION_CLICK, aSelector.btn_click_action);  //sets its action when pressed to be running the btn_click_action
  lv_btn_set_style(myButton, LV_BTN_STYLE_REL, &stylerel);  //sets the released style to the stylerel
  lv_btn_set_style(myButton, LV_BTN_STYLE_PR, &stylepr); //sets the pressed style to the stylepr
  lv_obj_set_size(myButton, myWidth, myHeight); //sets the button's height and width
  lv_obj_align(myButton, NULL, align, 0, 0); //set the button alignment
}
//creates the labels for buttons. uses the button Label object, the Button object, and a const char label
void acontrol::aselector::button_label_create(lv_obj_t * myButtonLabel, lv_obj_t * myButton, const char * label){
  myButtonLabel = lv_label_create(myButton, NULL); //creates the label on the button
  lv_label_set_text(myButtonLabel, label);  //Sets the text for the button
}
//creates label with attributes of the Label, the alignment and the text within it as a const char
void acontrol::aselector::label_create(lv_obj_t * myLabel, lv_align_t align, const char * text){
  myLabel = lv_label_create(lv_scr_act(), NULL); //creates the label
  lv_label_set_text(myLabel, text);  //sets the text within it
  lv_obj_align(myLabel, NULL, align, 10, 0); //aligns the label
}
