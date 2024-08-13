#include<iostream>
#include<fstream>
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"
#include"State.h"

State state;
void test_read_from() {
  state.read_from(_global_mem + 2);
  state.displayChange();
}

int main() {
  _read_global_mem_from_file("frame1.txt");
  test_read_from();
  delete _global_mem; 
}
