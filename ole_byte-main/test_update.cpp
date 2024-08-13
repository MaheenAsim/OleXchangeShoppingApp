
#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;
#include"/usr/local/cs/cs251/react.h"
#include"State.h"

State state;

void test_update_1() {
  _read_event_info_file("frame2.event");
  state.update();
  state.write_to(_global_mem + state.offset);

}



int main() {
  _read_global_mem_from_file("frame2.txt");
  state.read_from(_global_mem + state.offset);
  test_update_1();
  delete _global_mem;
}
