#ifndef __USER_H__
#define __USER_H__
#include<iostream>
#include <string>
//#include "Image.h"
#include "Post.h"
#include "Notification.h"
#include <ctime>
using namespace std;
class User {
    private: 
        int user_id; //uniquely identifies a user
        string email;
        string password;
        string first_name;
        string last_name;
        //Image profile_pic;
        string phone;
        string profile_pic;
        int length_post_arr;
        string* post_history; //give each post an id. Storing the string here  or array of PostIDs
        int length_ride_arr;
        string* ride_history;
        int length_notification_arr;
        Notification* notificationList;
        User* userListPointer;
        Post* postListPointer;

    public: 
        User(){//:profile_pic(){
            first_name = ""; last_name = "";
            email = ""; password = "";
            phone = "";
            profile_pic = "";
            //notificationList = new Notification[1];
        }

        //copy constructor (needs to be finished)
        User(const User &user):profile_pic(){

        }
        void set_userid(int id){
            user_id = id;
        }
        void set_email(string val);
        void set_phone(string ph);
        void set_password(string pwd);
        void set_image(string filename);
        void set_userListPointer(User* pointer){
            userListPointer = pointer; //making the userList of the state class accessable 
        }
        void set_postListPointer(Post* pointer){
            postListPointer = pointer; //making the postList of the state class accessable 
        }
        void get_image();
        int get_user_id() const{return user_id;}
        int get_length_notification_arr() const{
            return length_notification_arr;
        }
        int get_length_post_arr()const{
            return length_post_arr;
        }
        int get_length_ride_arr()const{
            return length_ride_arr;
        }

        void like_post(int index);


        const string* const get_post_history_pointer(){
            return post_history;
        }

        const string* const get_ride_history_pointer(){
            return ride_history;
        }

        Notification*  get_notification_pointer(){
            return notificationList;
        }


        
        string get_first() const {return first_name;}
        string get_last() const {return last_name;}
        string get_email() const {return email;}
        string get_phone() const {return phone;}
        string get_password() const {return password;}
        string get_profile_pic() const {return profile_pic;}
        /*void like_post(){
            cout <<  userListPointer[0].get_first() << endl;
        } This was for testing accesibility of the array*/
        void make_post();
        void read_from(const char* &mem);
        void write_to(char* &mem) const;
        ~User(){
            delete [] post_history;
            delete [] ride_history;
            delete [] notificationList;
        }
        void get_notifications(){
            cout << notificationList[0].get_invoker() << endl;
            cout << notificationList[0].get_posted_date() << endl;

        }

        int size_in_bytes() const;
};

#endif