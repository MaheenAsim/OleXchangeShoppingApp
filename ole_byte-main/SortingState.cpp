//Ole extra home page
#include<iostream>
using namespace std;
#include"SortingState.h"
#include"/usr/local/cs/cs251/show_mem.h"


void State::read_from(const char *mem) {
  /* name of variables:  string Sorting, Price, Clothes, Acessories, Electronics, Other; 
    string Home, Ole_Extra, Ole_Ride, Notification */
  Sorting =_get_tilde_terminated_string(mem);
   mem += Sorting.size() + 1;  
  Price = _get_tilde_terminated_string(mem);
  mem += Price.size() + 1;
  Clothes = _get_tilde_terminated_string(mem);
  mem +=  Clothes.size() + 1; 
  Home = _get_tilde_terminated_string(mem);
  mem += Home.size() + 1;
  Ole_Extra =_get_tilde_terminated_string(mem);
  mem += Ole_Extra.size() + 1;
  Ole_Ride = _get_tilde_terminated_string(mem);
  mem += Ole_Ride.size() +1; 
  Notification = _get_tilde_terminated_string(mem);
  mem += Notification.size() +1; 
  Acessories = _get_tilde_terminated_string(mem);
  mem += Acessories.size() +1; 
  Electronics = _get_tilde_terminated_string(mem);
  mem += Electronics.size() +1; 
  Other = _get_tilde_terminated_string(mem);
  mem += Other.size() +1; 
}
   /* name of variables:  string Sorting, Price, Clothes, Acessories, Electronics, Other; 
    string Home, Ole_Extra, OLe_Ride, Notification */ 
void State::write_to(char *mem) const{
  _put_tilde_terminated_string( Sorting, mem);
  mem += Sorting.size() + 1;  
  _put_tilde_terminated_string(Price, mem);
  mem +=Price.size() + 1;
  _put_tilde_terminated_string(Clothes, mem);
  mem += Clothes.size() + 1;
  _put_tilde_terminated_string(Home, mem);
  mem += Home.size() + 1;
  _put_tilde_terminated_string(Ole_Extra, mem);
  mem += Ole_Extra.size() + 1;
  _put_tilde_terminated_string(Ole_Ride, mem);
  mem += Ole_Ride.size() + 1;
  _put_tilde_terminated_string(Notification, mem);
  mem += Notification.size() + 1;
  _put_tilde_terminated_string(Acessories, mem);
  mem += Acessories.size() + 1;
  _put_tilde_terminated_string(Electronics, mem);
  mem +=  Electronics.size() + 1;
  _put_tilde_terminated_string(Other, mem);
  mem += Other.size() + 1;

}
