#include"/usr/local/cs/cs251/react.h"
#include"Entry_State.h"
const int num_colors = 6;
const int colors[6][3] = { {140,81,10}, {216,179,101}, {246,232,195}, {199,234,229}, {90,180,172}, {1,102,94} };
const int magnification = 20;

void make_entry_button(int i){
 int r, g, b, r2, g2, b2;
 r = colors[i][0]; 
 g = colors[i][1];
 b = colors[i][2]; 
 r2 = colors[i][2]; 
 g2 = colors[i][1];
 b2 = colors[i][0]; 
 _add_yaml("entry_button.yaml" , {{"id", i}, { "r", r}, {"g", g}, {"b", b}, {"r2", r2}, { "g2", g2}, {"b2", b2}}); 

}

void make_Home_button(int i){
 int r, g, b, r2, g2, b2;
 r = colors[i][0]; 
 g = colors[i][1];
 b = colors[i][2]; 
 r2 = colors[i][0]; 
 g2 = colors[i][1];
 b2 = colors[i][2];
 _add_yaml("Home_button.yaml" , {{"id", i}, { "r", r}, {"g", g}, {"b", b}, {"r2", r2}, { "g2", g2}, {"b2", b2}}); 

}

void make_OleExtra_button(int i){
 int r, g, b, r2, g2, b2;
 r = colors[i][0]; 
 g = colors[i][1];
 b = colors[i][2]; 
 r2 = colors[i][0]; 
 g2 = colors[i][1];
 b2 = colors[i][2]; 
 _add_yaml("OleExtra_button.yaml" , {{"id", i}, { "r", r}, {"g", g}, {"b", b}, {"r2", r2}, { "g2", g2}, {"b2", b2}}); 

}

void make_OleDrive_button(int i){
 int r, g, b, r2, g2, b2;
 r = colors[i][0]; 
 g = colors[i][1];
 b = colors[i][2]; 
 r2 = colors[i][0]; 
 g2 = colors[i][1];
 b2 = colors[i][2];
 _add_yaml("OleDrive_button.yaml" , {{"id", i}, { "r", r}, {"g", g}, {"b", b}, {"r2", r2}, { "g2", g2}, {"b2", b2}}); 

}
void make_Notification_button(int i){
 int r, g, b, r2, g2, b2;
 r = colors[i][0]; 
 g = colors[i][1];
 b = colors[i][2]; 
 r2 = colors[i][0]; 
 g2 = colors[i][1];
 b2 = colors[i][2];
 _add_yaml("Notification_button.yaml" , {{"id", i}, { "r", r}, {"g", g}, {"b", b}, {"r2", r2}, { "g2", g2}, {"b2", b2}}); 

}



void display(State &state) {
   //_add_yaml("Extra_Text.yaml", {{"top_index", state.offset_for_status_text()}, {"grid_width", state.get_grid().get_width()}, { "get_height" , state.get_grid().get_height()}, {"get_magnification", state.get_grid().get_magnification()}, {"total_width" , state.get_grid().get_total_width()}, {"total_height", state.get_grid().get_total_height()}, {"grid_offset", state.offset_for_raw_colors()}}); 
  if (state.get_entry_button()) {
    int i = 0;
    make_entry_button(i);
  } 
  //get_entry_button  
  if (state.get_Home_button()) {
    int i = 1;
    make_Home_button(i);
  } 
  if (state.get_Notification_button()) {
   int i = 2;
   make_Notification_button(i);
  } 
  // when ole extra button clicked then these images appear as buttons to be opened
  if (state.get_OleDrive_button()) {
    make_image1_button(2);
    make_image2_button(1);
    make_image3_button(4);
    make_image4_button(3);
    make_image5_button(6);
    make_image6_button(2);
    make_image7_button(1);
    make_image8_button(5);
    make_image9_button(6);

  } 
  if (state.get_OleExtra_button()) {
    int i = 2;
    make_OleExtra_button(i);
  } 
  _add_yaml("Extra_Text.yaml", {{"top_index", state.offset_for_Extra_text()}});
  _add_yaml("Home_Text.yaml", {{"top_index", state.offset_for_Home_text()}});
  _add_yaml("Ride_Text.yaml", {{"top_index", state.offset_for_Ride_text()}});
  _add_yaml("New_Entry_Text.yaml", {{"top_index", state.offset_for_New_Entry_text()}});
  _add_yaml("Notification_Text.yaml", {{"top_index", state.offset_for_Notification_text()}});
  _add_yaml("Login_Text.yaml", {{"top_index", state.offset_for_Login_text()}});
  _add_yaml("Sign_Text.yaml", {{"top_index", state.offset_for_Sign_text()}});

  //images addresses as button text on extra homepage, will change later
  _add_yaml("image1_Text.yaml", {{"top_index", state.offset_for_image1_text()}});
  _add_yaml("image2_Text.yaml", {{"top_index", state.offset_for_image2_text()}});
  _add_yaml("image3_Text.yaml", {{"top_index", state.offset_for_image3_text()}});
  _add_yaml("image4_Text.yaml", {{"top_index", state.offset_for_image4_text()}});
  _add_yaml("image5_Text.yaml", {{"top_index", state.offset_for_image5_text()}});
  _add_yaml("image6_Text.yaml", {{"top_index", state.offset_for_image6_text()}});
  _add_yaml("image7_Text.yaml", {{"top_index", state.offset_for_image7_text()}});
  _add_yaml("image8_Text.yaml", {{"top_index", state.offset_for_image8_text()}});
  _add_yaml("image9_Text.yaml", {{"top_index", state.offset_for_image9_text()}});
  
  //moreeee if statements here and offset etc in State.h

}
