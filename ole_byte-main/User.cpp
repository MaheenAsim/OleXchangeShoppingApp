#include"/usr/local/cs/cs251/show_mem.h"
#include "User.h"
    
void User::set_email(string val){
        email = val;
}
void User::set_phone(string ph){
    phone = ph;
    }
void User::set_password(string pwd){
    password = pwd;
}
void User::set_image(string filename){
        //profile_pic.set_to_file(filename);
    }
void User::get_image(){  
}
void User::read_from(const char* &mem){
   // cout << "hi" << endl;

    user_id = _get_int(mem, 4);
    mem += 4;
    first_name = _get_tilde_terminated_string(mem);
    mem += first_name.size()+1;

    //cout << first_name << endl;

    last_name = _get_tilde_terminated_string(mem);
    mem += last_name.size() +1;
    email += _get_tilde_terminated_string(mem);
    mem += email.size() + 1;
    password = _get_tilde_terminated_string(mem);
    mem += password.size() + 1;
    //string image_name =  _get_tilde_terminated_string(mem); 
    //mem += image_name.size() + 1;
    //set_image(image_name); react will not work with how the image class is structured right now this will be a link
    profile_pic =  _get_tilde_terminated_string(mem); 
    mem += profile_pic.size() + 1;
    phone = _get_tilde_terminated_string(mem);
    mem += phone.size() + 1;
   // cout << phone << endl;
    length_post_arr = _get_int(mem, 3);

   // cout << length_post_arr << endl;

    post_history = new string[length_post_arr];
    mem += 3;
    for(int i = 0; i < length_post_arr; ++i){
        post_history[i] = _get_tilde_terminated_string(mem);
        mem+=post_history[i].size() + 1;
    }

   // cout << post_history[0] << endl;

    length_ride_arr = _get_int(mem, 3);

    //cout << "length_ride_arr: " << length_ride_arr << endl;

    ride_history = new string[length_ride_arr];
    mem += 3;
    for(int i = 0; i < length_ride_arr; ++i){
        ride_history[i] = _get_tilde_terminated_string(mem);
        mem += ride_history[i].size() + 1;
    }

    //cout << "ride id: " << ride_history[0] << endl;
    length_notification_arr = _get_int(mem, 3);
   // cout << "length_notification_arr: " << length_notification_arr << endl;
    notificationList = new Notification[length_notification_arr];
    mem += 3;
    for(int i = 0; i < length_notification_arr; ++i){
        notificationList[i].read_from(mem);
    }
}

   void User::write_to(char* &mem) const{
        _put_int(user_id, mem,4);
        mem += 4;
        _put_tilde_terminated_string(first_name, mem);
        mem += first_name.size() + 1;
        _put_tilde_terminated_string(last_name, mem);
        mem += last_name.size() + 1;
        _put_tilde_terminated_string(email,mem);
        mem += email.size() + 1;
        _put_tilde_terminated_string(password, mem);
        mem += password.size() + 1;
        _put_tilde_terminated_string(profile_pic, mem);
        mem += profile_pic.size() + 1; 
        _put_tilde_terminated_string(phone, mem);
        mem += phone.size() + 1;
        _put_int(length_post_arr, mem, 3);
        mem += 3;
        for(int i = 0; i < length_post_arr; ++i){
            _put_tilde_terminated_string(post_history[i], mem);
            mem += post_history[i].size() + 1;
        }
        _put_int(length_ride_arr, mem, 3);
        mem += 3;
        for (int i  = 0; i < length_ride_arr; ++i){
            _put_tilde_terminated_string(ride_history[i], mem);
            mem += ride_history[i].size() + 1;
        }
        _put_int(length_notification_arr, mem, 3);
        for(int i = 0; i < length_notification_arr; ++i){
            _put_tilde_terminated_string(notificationList[i].get_invoker(), mem);
            mem += notificationList[i].get_invoker().size() + 1;
            _put_tilde_terminated_string(notificationList[i].get_posted_date(), mem);
            mem += notificationList[i].get_posted_date().size() + 1;
        }

    }
    
   // cout << "Invoker: " << notificationList[0].get_invoker() << endl;
    //cout << "Posted Date:" << notificationList[0].get_posted_date() << endl;




void User::like_post(int index){
    int currLikes = postListPointer[index].get_num_likes();
    postListPointer[index].set_num_likes(currLikes + 1);
    int targetUserID = postListPointer[index].get_poster();
    int targetUserIndex = 0; 
    for(;targetUserID != userListPointer[targetUserIndex].get_user_id(); ++targetUserIndex){}
    
    const int MAXLEN = 80;
    char s[MAXLEN];
    time_t t = time(0);
    strftime(s, MAXLEN, "%m/%d/%Y", localtime(&t));

    userListPointer[targetUserIndex].get_notification_pointer()[0].set_post_date(s);
    userListPointer[targetUserIndex].get_notification_pointer()[0].set_invoker(this->first_name);
    



    
}

//void like_post(Post post){
    //add "this" user in the likes
    //get the poster and make changes to the notification list 
    //for the step above:
    //const int MAXLEN = 80;
    //char s[MAXLEN];
    //time_t t = time(0);
    //strftime(s, MAXLEN, "%m/%d/%Y", localtime(&t));
//} 

int User::size_in_bytes() const{
    int length_of_post_ids = 0 , length_of_ride_ids = 0 , length_of_notification = 0; 
    for(int i = 0; i < length_post_arr; ++i){
        length_of_post_ids += post_history[i].length() + 1;
    }

    for(int i = 0; i < length_ride_arr; ++i){
        length_of_ride_ids += ride_history[i].length() + 1;
    }

    for(int i = 0; i < length_notification_arr; ++i){
        length_of_notification += notificationList[i].get_invoker().length() + 1;
        length_of_notification += notificationList[i].get_posted_date().length() + 1;

    }

    return (
        4 + first_name.length()+1 + last_name.length() + 1 + email.length() + 1 + password.length() + 1 +
        profile_pic.length() + 1 + phone.length() + 1 + 3 + length_of_post_ids + 3 +
        length_of_ride_ids + 3 + length_of_notification
    );
}
