#include<iostream>
#include<fstream>
using namespace std;
#include"/usr/local/cs/cs251/react.h"
#include"State.h"

State state;
void test_display(){
    display(state);
}

int main(){
  _read_global_mem_from_file("state4.txt");
  state.read_from(_global_mem + state.offset);
  //cout << state.offset_for_contact() << endl;
  //state.displayChange();
 
   ifstream f_label("labels.txt");
  f_label.read(_global_mem + state.label_offset, 4000);
  test_display();
  _write_global_yaml_to_file("react.yaml");
  _write_global_mem_to_file("end_mem");
  delete _global_mem;
}