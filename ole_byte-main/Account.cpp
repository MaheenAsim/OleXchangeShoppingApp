#include<iostream>
#include "Account.h"
#include <string>
using namespace std;

 bool Account::validate_email(string val){
    string check = "@stolaf.edu";
    int i = 0;
    bool find_at = false;
    for (i = 0; val[i] != 0; ++i){
        if(val[i] == '@'){
            find_at = true;}
        }
    if (find_at == false){return false;}
    for (i = 0; val[i] != '@'; ++i){}
    bool valid = true;
    int index = 0;
    while(val[i] != 0 && valid){
        if (val[i] != check[index]){
        valid = false;
        }
        i++; index++;
    }

    return valid;
 }

 bool Account::validate_pwd(string pwd, string pwd2){
        if(pwd == pwd2){
            return true;
        }
    return false;
}

void Account::make_account(string fname, string lname, string email, string pwd, string pwd2, string ph, string filename){
    if ((num_of_users < maxUsers) && validate_email(email) && validate_pwd(pwd, pwd2)){
        
        userList[num_of_users] = {fname, lname};
        userList[num_of_users].set_email(email);
        userList[num_of_users].set_password(pwd);
        userList[num_of_users].set_phone(ph);
        userList[num_of_users].set_image(filename);
        num_of_users++;
    }

    /*else if(num_of_users == maxUsers){
        User* temp_user_list = new User[maxUsers *= 2];
        //copying the smaller list into a bigger list
        for(int i; i < maxUsers; ++i){
            temp_user_list[i] = userList[i];
        }

        delete [] userList;
        userList = temp_user_list;
    }*/
}

User Account::get_User(int index){
    User tempUser(userList[index]);
    return tempUser;
}
    
    


