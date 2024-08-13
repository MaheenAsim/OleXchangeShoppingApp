//Ole extra home page
#ifndef __EHOME_STATE_H__
#define __EHOME__STATE_H__

#include<string>
using namespace std;

class State {
    protected:
    string image1, image2, image3, image4, image5, image6,image7, image8, image9;
    string OleByte_text,NewEntry_text, sort_text, Home, OleExtra, OleRide, notification ; 
  // fill in member data and functions here
  public:

  string _get_OleByte_text(){
    return OleByte_text;
  };
  string _get_NewEntry_text(){
    return NewEntry_text; 
  };
  string _get_sort_text(){
    return sort_text; 
  };
   string _get_Home(){
    return Home; 
  };  string _get_OleExtra(){
    return OleExtra;
  };
  string _get_OleRide(){
    return OleRide;
  };string _get_Notification(){
    return notification;
  };

  string _get_image1(){
    return image1;
  };
  string _get_image2(){
    return image2;
  };string _get_image3(){
    return image3;
  };string _get_image4(){
    return image4;
  };string _get_image5(){
    return image5;
  };string _get_image6(){
    return image6;
  };string _get_image7(){
    return image7;
  };string _get_image8(){
    return image8;
  };string _get_image9(){
    return image9;
  };
  void read_from(const char *mem);
  void write_to(char *mem) const;
};

#endif
