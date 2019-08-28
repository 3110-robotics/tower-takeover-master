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




static lv_res_t btn_click_action(lv_obj_t * a){

  uint8_t id = lv_obj_get_free_num(a); //gets the position of the button, for acting on in the switch
  int length = sizeof(autonModes[count]) + 5;

  if(id == next){
    count+=1;
    (count>10 ? count=0:count);
    lv_label_set_text(autonLabel, const_cast<char*>(autonModes[count]));
  }
  else if(id == previous){
     count-=1;
     (count<0 ? count=10:count);
     lv_label_set_text(autonLabel, (char *)autonModes[count]);
  }
  else if(id == run){
    aSelector.clear_screen();
  }
  else if(id == auton){
    aSelector.clear_screen();
    autonomous();
  }
  return LV_RES_OK;
}


//style_setter sets the settings of the inputted style, using the plain button style and the rgb values given here
void style_setter(lv_style_t style, uint8_t rgb[9]){
  lv_style_copy(&style, &lv_style_plain);  //sets the style to plain
  style.body.main_color = LV_COLOR_MAKE(rgb[0], rgb[1], rgb[2]); // sets the colours of the style
  style.body.grad_color = LV_COLOR_MAKE(rgb[3], rgb[4], rgb[5]);
  style.body.radius = 0;
  style.text.color = LV_COLOR_MAKE(rgb[6], rgb[7], rgb[8]);
}

void acontrol::aselector::clear_screen(){

}
void acontrol::aselector::button_create(lv_obj_t * myButton, lv_style_t stylerel, lv_style_t stylepr, lv_align_t align, uint8_t place, uint8_t myWidth, uint8_t myHeight){
  myButton = lv_btn_create(lv_scr_act(), NULL);  //creates the button object
  lv_obj_set_free_num(myButton, place);  //sets it's identifyer to "place" for access in the btn_click_action
  lv_btn_set_action(myButton, LV_BTN_ACTION_CLICK, btn_click_action);  //sets its action when pressed to be running the btn_click_action
  lv_btn_set_style(myButton, LV_BTN_STYLE_REL, &stylerel);  //sets the released style to the stylerel
  lv_btn_set_style(myButton, LV_BTN_STYLE_PR, &stylepr); //sets the pressed style to the stylepr
  lv_obj_set_size(myButton, myWidth, myHeight); //sets the button's height and width
  lv_obj_align(myButton, NULL, align, 0, 0); //set the button alignment
}
void acontrol::aselector::button_label_create(lv_obj_t * myButtonLabel, lv_obj_t * myButton, const char * label){
  myButtonLabel = lv_label_create(myButton, NULL); //creates the label on the button
  lv_label_set_text(myButtonLabel, label);  //Sets the text for the button
}

void acontrol::aselector::label_create(lv_obj_t * myLabel, lv_align_t align, const char * text){
  myLabel = lv_label_create(lv_scr_act(), NULL); //creates the label
  lv_label_set_text(myLabel, text);  //sets the text within it
  lv_obj_align(myLabel, NULL, align, 10, 0); //aligns the label
}
