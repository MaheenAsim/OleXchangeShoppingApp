#include<iostream>
#include "User.h"
using namespace std; 

class Account{
    protected: 
        User* userList;
        int num_of_users = 0;
        int maxUsers = 30;

    public:
        Account(){
            userList = new User[maxUsers]; //starting with provision for 30 accounts
        }

        ~Account(){delete [] userList;}
        void make_account(string fname, string lname, string email, string pwd, string pwd2, string ph, string filename);
        bool validate_email(string val);
        bool validate_pwd(string pwd, string pwd2);
        User get_User(int index);
};