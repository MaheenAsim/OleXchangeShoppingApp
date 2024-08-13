#ifndef __ENTRY_STATE_H__
#define __ENTRY_STATE_H__

#include<string>
using namespace std;

class State {
    protected:
    int price;
    string OleByte_text, description_text, add_text, sort_text, product_Name_text, image, tags ; 
  // fill in member data and functions here
  public:
  int _get_price(){
    return price;
  };
  string _get_OleByte_text(){
    return OleByte_text;
  };
  string _get_description_text(){
    return description_text; 
  };
   string _get_add_text(){
    return add_text; 
  }; string _get_sort_text(){
    return sort_text; 
  }; string _get_Product_Name_text(){
    return product_Name_text;
  };
    string _get_image(){
    return image;
  };
  string _get_tags(){
    return tags;
  };
  void read_from(const char *mem);
  void write_to(char *mem) const;

};

#endif
