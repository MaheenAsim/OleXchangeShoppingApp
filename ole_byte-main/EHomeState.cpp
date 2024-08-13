//Ole extra home page
#include<iostream>
using namespace std;
#include"EHomeState.h"
#include"/usr/local/cs/cs251/show_mem.h"


void State::read_from(const char *mem) {
  /* name of variables:  string image1, image2, image3, image4, image5, image6, image7, image8, image9;
    string OleByte_text,NewEntry_text, sort_text, Home, OleExtra, OleRide, notification ; */
  OleByte_text =_get_tilde_terminated_string(mem);
   mem += OleByte_text.size() + 1;  
  NewEntry_text = _get_tilde_terminated_string(mem);
  mem += NewEntry_text.size() + 1;
  sort_text = _get_tilde_terminated_string(mem);
  mem += sort_text.size() + 1; 
  Home = _get_tilde_terminated_string(mem);
  mem += Home.size() + 1;
  OleExtra =_get_tilde_terminated_string(mem);
  mem += OleExtra.size() + 1;
  OleRide = _get_tilde_terminated_string(mem);
  mem += OleRide.size() +1; 
  notification = _get_tilde_terminated_string(mem);
  mem += notification.size() +1; 
  image1 = _get_tilde_terminated_string(mem);
  mem += image1.size() +1; 
  image2 = _get_tilde_terminated_string(mem);
  mem += image2.size() +1; 
  image2 = _get_tilde_terminated_string(mem);
  mem += image2.size() +1; 
  image3 = _get_tilde_terminated_string(mem);
  mem += image3.size() +1; 
  image4 = _get_tilde_terminated_string(mem);
  mem += image4.size() +1; 
  image5 = _get_tilde_terminated_string(mem);
  mem +=  image5.size() +1; 
  image6 = _get_tilde_terminated_string(mem);
  mem += image6.size() +1; 
  image7 = _get_tilde_terminated_string(mem);
  mem += image7.size() +1; 
  image8 = _get_tilde_terminated_string(mem);
  mem += image8.size() +1; 
  image9 = _get_tilde_terminated_string(mem);
  mem += image9.size() +1; 
}
  /* name of variables:  string image1, image2, image3, image4, image5, image6, image7, image8, image9;
    string OleByte_text,NewEntry_text, sort_text, Home, OleExtra, OleRide, notification ; */
void State::write_to(char *mem) const{
  _put_tilde_terminated_string(OleByte_text, mem);
  mem += OleByte_text.size() + 1;  
  _put_tilde_terminated_string(NewEntry_text, mem);
  mem += NewEntry_text.size() + 1;
  _put_tilde_terminated_string(sort_text, mem);
  mem += sort_text.size() + 1;
  _put_tilde_terminated_string(Home, mem);
  mem += Home.size() + 1;
  _put_tilde_terminated_string(OleExtra, mem);
  mem += OleExtra.size() + 1;
  _put_tilde_terminated_string(OleRide, mem);
  mem += OleRide.size() + 1;
  _put_tilde_terminated_string(notification, mem);
  mem += notification.size() + 1;
  //name of variables:  string image1, image2, image3, image4, image5, image6, image7, image8, image9
  _put_tilde_terminated_string(image1, mem);
  mem += image1.size() + 1;
  _put_tilde_terminated_string(image2, mem);
  mem += image2.size() + 1;
  _put_tilde_terminated_string(image3, mem);
  mem += image3.size() + 1;
  _put_tilde_terminated_string(image4, mem);
  mem += image4.size() + 1;
  _put_tilde_terminated_string(image5, mem);
  mem += image5.size() + 1;
  _put_tilde_terminated_string(image6, mem);
  mem += image6.size() + 1;
  _put_tilde_terminated_string(image7, mem);
  mem += image7.size() + 1;
  _put_tilde_terminated_string(image8, mem);
  mem += image8.size() + 1;
  _put_tilde_terminated_string(image9, mem);
  mem += image9.size() + 1;

}
