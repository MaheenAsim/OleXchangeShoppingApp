#ifndef __STATE_H__
#define __STATE_H__
#include <iostream>
#include <string>
#include "User.h"
//#include "Post.h"
//#include "Ride.h"
using namespace std;

class State{
    private:
        string screen_to_show;
        int user_to_show; // user will be identified by an id
        string post_to_show; //will be useful when the user is viewing the ole extra page and viewing a particular post
        int index_user_to_show;
        int index_post_to_show;
    public:
        static const int offset, label_offset;
        User* userList;
        Post* postList;
        int numofUsers;
        int numofPosts;

   // Ride* rideList;
    
    
    void read_from(const char *mem);
    void write_to(char *mem) const;
    //temporary funciton
    void displayChange();
    string get_screen_to_show()const{return screen_to_show;}
    int get_user_to_show()const{return user_to_show;}
    int get_index_post_to_show(){
        return index_post_to_show;
    }
    int get_index_post_to_show(){
        return index_user_to_show;
    }
    string get_post_to_show()const{return post_to_show;}
    int find_offset_user_to_show()const;
    int offset_for_firstN()const;
    int offset_for_lastN()const;
    int offset_for_email()const;
    int offset_for_contact()const;
    int offset_for_notificationInvoker()const;
    int offset_for_notificationDate()const;
    void set_index_user_to_show(int i){
        index_user_to_show = i;
    }
    void set_index_post_to_show(int i){
        index_post_to_show = i;
    }
    int find_offset_post_to_show()const;
    int offset_for_product_name()const;
    int offset_for_product_price()const;
    int offset_for_product_description()const;
    int offset_for_product_likes()const;
    void update();
};

void display(const State &);
#endif
