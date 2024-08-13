//Ole extra home page
#ifndef __SORTING_STATE_H__
#define __SORTING__STATE_H__

#include<string>
using namespace std;

class State {
    protected:
    string Sorting, Price, Clothes, Acessories, Electronics, Other; 
    string Home, Ole_Extra, Ole_Ride, Notification; 
  // fill in member data and functions here
  public:

  string _get_Sorting(){
    return Sorting;
  };
  string _get_Price(){
    return Price; 
  };
  string _get_Clothes(){
    return Clothes; 
  };
   string _get_Acessories(){
    return Acessories; 
  };  string _get_Electronics(){
    return Electronics;
  };
  string _get_Ole_Ride(){
    return Ole_Ride;
  };string _get_Notification(){
    return Notification;
  };

  string _get_Other(){
    return  Other;
  };
  string _get_Ole_Extra(){
    return Ole_Extra;
  };string _get_Home(){
    return Home;
  };
  void read_from(const char *mem);
  void write_to(char *mem) const;
};

#endif
