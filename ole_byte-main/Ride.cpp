#include<iostream>
#include <string>
#include "User.h"

using namespace std;



class Ride {
    private: 
    bool Chip_in_money, ride_taken;
    int posted_date, desired_date, desired_time, 
    string origin, destination; 
    // User* poster;
    // User* interested_user;

    public:
    
    Ride(bool ch, bool rt, int pd, int dd, int dt, string ori, string dest){
        Chip_in_money = ch;
        ride_taken = rt;
        posted_date = pd;
        desired_date = dd;
        desired_time = dt;
        string origin = ori;
        string destination = dest;
        // poster pointer
        // interested_user
    }

    Ride()
    //setter 
    void set_Chip_in_money(bool ch){
        Chip_in_money = cm;
    }


    //setter
    void set_posted_date(int pd){
        posted_date = pd; 

    }
    //setter
    void set_desired_date (int dd){
        desired_date = dd;
    }
    //setter
    void set_desired_time(int dt){
        desired_time = dt;
    }

    bool chip_in_mone
    //getter
    int get_posted_date(){
        return posted_date;
    }    
    //getter
    int get_desired_date(){
        return desired_date; 
    }
    
    //getter
    int get_desired_date(){
        return desired_date;
    }



    // destructor 
    /*~Ride() {
        
    }*/
};
