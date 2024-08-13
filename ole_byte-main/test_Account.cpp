#include<iostream>
#include "Account.h"
using namespace std;



int main(){
    Account ole_byte;
    cout << "Hi! Welcome to Ole Byte" << endl;
    ole_byte.make_account();
    //Need copy constructors for these:
    //cout << ole_byte.get_User(0).get_first() << endl;
    //cout << ole_byte.get_User(0).get_last() << endl;
    //ole_byte.get_User(0).profile_pic.print();
}