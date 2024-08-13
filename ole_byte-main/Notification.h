#include <iostream>
using namespace std;

class Notification{
    protected: 
        string invoker;
        string posted_date;

    public: 
        Notification(string invoke, char* date){
            invoker = invoke; 
            posted_date = date; 
        }

        //default constructor
        Notification(){
            invoker = "";
            posted_date = "";
        }

        void read_from(const char* &mem);   
        string get_invoker(){return invoker;}
        string get_posted_date(){return posted_date;}      
};