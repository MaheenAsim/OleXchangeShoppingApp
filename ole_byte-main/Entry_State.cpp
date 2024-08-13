#include<iostream>
using namespace std;
#include"Entry_State.h"
#include"/usr/local/cs/cs251/show_mem.h"


void State::read_from(const char *mem) {
  price = _get_int(mem, 3);
  mem += 3;
  //OleByte_text, description_text, add_text, sort_text, Product_Name_text
  OleByte_text =_get_tilde_terminated_string(mem);
  mem += 2;
  //OleByte_text.size() + 1;  
  add_text = _get_tilde_terminated_string(mem);
  mem += add_text.size() + 1;
  sort_text = _get_tilde_terminated_string(mem);
  mem += sort_text.size() + 1; 
  product_Name_text = _get_tilde_terminated_string(mem);
  mem += product_Name_text.size() + 1;
  description_text =_get_tilde_terminated_string(mem);
  mem += description_text.size() + 1;
  image = _get_tilde_terminated_string(mem);
  mem += image.size() +1; 
  tags = _get_tilde_terminated_string(mem);
  mem += tags.size() +1; 
}
void State::write_to(char *mem) const{
  _put_int(price, mem, 3);
  mem += 3;
  _put_tilde_terminated_string(OleByte_text, mem);
  mem += OleByte_text.size() + 1;  
  _put_tilde_terminated_string(add_text, mem);
  mem += add_text.size() + 1;
  _put_tilde_terminated_string(sort_text, mem);
  mem += sort_text.size() + 1;
  _put_tilde_terminated_string(product_Name_text, mem);
  mem += product_Name_text.size() + 1;
  _put_tilde_terminated_string(description_text, mem);
  mem += description_text.size() + 1;
  _put_tilde_terminated_string(image, mem);
  mem += image.size() + 1;
 _put_tilde_terminated_string(tags, mem);
  mem += tags.size() + 1;

}
