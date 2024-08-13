#include<iostream>
#include<fstream>
#include <cassert> 
using namespace std;
#include"/usr/local/cs/cs251/show_mem.h"
#include"Entry_State.h"

State state;

/*void test_read_from() {
  state.read_from(_global_mem + 2);
  assert(state.get_show_buttons() == true);
  assert(state.get_num_moves() == 23);
  assert(state.get_status_text() == "ok");
  assert(state.get_new_game_text() == "new");
  assert(state.get_grid().get_color(GridLocation{1, 2}) == 4); 
}

void test_write_to() {
  state.write_to(_global_mem + 10);
  cerr << string(_global_mem).substr(0, 70) << endl;
  assert(_global_mem[14] == 'o');
}*/

int main() { 
  _read_global_mem_from_file("addentry.txt");
  //cerr << "_global_mem contains " << _global_mem << endl;
 _write_global_mem_to_file("addentry2.txt");

  delete _global_mem;
}
