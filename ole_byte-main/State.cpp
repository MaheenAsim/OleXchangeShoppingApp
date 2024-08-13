#include<iostream>
using namespace std;
#include"State.h"
#include"/usr/local/cs/cs251/show_mem.h"
const int State::offset = 2, State::label_offset = 5000;


int State::find_offset_user_to_show()const{
  int index = offset + screen_to_show.size() + 1 + 4 + post_to_show.size() + 1 + 3;
  int i = 0;
  for(i = 0; userList[i].get_user_id() != user_to_show; ++i){
    index += userList[i].size_in_bytes();
  }
  return index;
} 

int State::offset_for_firstN()const{
  int index = find_offset_user_to_show() + 4;
  return index;
  
}

int State::offset_for_lastN()const{
  int index = offset_for_firstN() + userList[index_user_to_show].get_first().size() + 1;
  return index;
}

int State::offset_for_email()const{
  int index = offset_for_lastN() + userList[index_user_to_show].get_last().size() + 1;
  return index;
}


int State::offset_for_contact()const{
  int index = offset_for_email() + userList[index_user_to_show].get_email().size() + 1 +
  userList[index_user_to_show].get_password().size() + 1 +
  userList[index_user_to_show].get_profile_pic().size() + 1
  ;
  return index;
}

//this function needs more planning because there can be multiple notifications at a given time, and we need to display all of them
int State::offset_for_notificationInvoker()const{
  int index = offset_for_contact() + userList[index_user_to_show].get_phone().size()+ 1 + 3;
  for(int i = 0; i < userList[index_user_to_show].get_length_post_arr(); ++i){
    index += (userList[index_user_to_show].get_post_history_pointer())[i].length() + 1;
  }
  index += 3;
  for(int i = 0; i < userList[index_user_to_show].get_length_ride_arr(); ++i){
    index += (userList[index_user_to_show].get_ride_history_pointer())[i].length() + 1;
  }
  index += 3;
  return index;
}

int State::offset_for_notificationDate()const{
  int index = offset_for_notificationInvoker() + userList[index_user_to_show].get_notification_pointer()[0].get_invoker().length() + 1; 
  cout << userList[index_user_to_show].get_notification_pointer()[0].get_invoker() << endl;
  return index;
}

int State::find_offset_post_to_show()const{
  int index = offset + screen_to_show.size() + 1 + 4 + post_to_show.size() + 1 + 3;
  for(int i = 0; i < numofUsers; ++i){
    index += userList[i].size_in_bytes();
  }

index += 3;

  for(int j = 0; postList[j].get_post_id() != post_to_show; ++j){
    index += postList[j].size_in_bytes();
  }

  return index;
}


int State::offset_for_product_name()const{
  int index = find_offset_post_to_show();
  index += postList[index_post_to_show].get_post_id().size() + 1;
  return index;
}

int State::offset_for_product_likes() const{
  int index = offset_for_product_name();
  index += postList[index_post_to_show].get_product_name().size()+1;
  index += postList[index_post_to_show].get_product_tag().size()+1;
  index += 4;

  return index;
}
int State::offset_for_product_description()const{
  int index = offset_for_product_likes();
  index += 4;
  return index;
}

int State::offset_for_product_price()const{
  int index = offset_for_product_description();
  index += postList[index_post_to_show].get_description().size()+1;
  return index;
}
void State::read_from(const char *mem) {
        screen_to_show = _get_tilde_terminated_string(mem);
        mem += screen_to_show.size() + 1;
        user_to_show = _get_int(mem, 4);
        mem += 4;
        post_to_show = _get_tilde_terminated_string(mem);
        mem += post_to_show.size() + 1;
        numofUsers = _get_int(mem, 3);
        userList = new User[numofUsers];
        for(int i = 0; i < numofUsers; ++i){
          userList[i].set_userListPointer(userList);
        }
        mem += 3;
        for(int i = 0; i < numofUsers; ++i){
            userList[i].read_from(mem);
        }
        numofPosts = _get_int(mem, 3);
        //cout << numofPosts << endl;
        postList = new Post[numofPosts];
        mem += 3;
        for(int i = 0; i < numofUsers; ++i){
        userList[i].set_postListPointer(postList);
        }
       for(int i = 0; i < numofPosts; ++i){
          postList[i].read_from(mem);
        }

      // need to find the index for user_to_show in UserList array 
      int i = 0;
      for(i = 0; userList[i].get_user_id() != user_to_show; ++i){}
      set_index_user_to_show(i);

      // need to find the index for post_to_show in PostList array
      int j = 0;
      for(j = 0; postList[j].get_post_id() != post_to_show; ++j){}
      set_index_post_to_show(j);

}
 
void State::write_to(char *mem)const{
  _put_tilde_terminated_string(screen_to_show, mem); //screen to show
  mem += screen_to_show.size() + 1;
  _put_int(user_to_show, mem, 4); //user to show
  mem += 4;
  _put_tilde_terminated_string(post_to_show,mem); //post to show
  mem += post_to_show.size() + 1;
  _put_int(numofUsers, mem,3);
  mem += 3;
  for(int i = 0; i < numofUsers; ++i){
    userList[i].write_to(mem);
  }
  _put_int(numofPosts, mem, 3);
  mem += 3; 
  for(int i = 0; i < numofPosts; ++i){
      postList[i].write_to(mem);
  } 
}



 void State::displayChange(){
      /*cout << userList[0].size_in_bytes() << endl;
      cout << userList[0].get_user_id() << endl;
      cout << userList[0].get_first() << endl;
      cout << userList[0].get_last() << endl;
      cout << userList[0].get_email() << endl;
      cout << userList[0].get_password() << endl;
      cout << userList[0].get_phone() << endl;
      //userList[0].like_post(); This was for testing accesibility of the userList array which worked!!!!! 
           userList[0].get_notifications(); */
      cout << postList[0].get_post_id() << endl;
      cout << postList[0].get_product_name() << endl;
      cout << postList[0].get_description() << endl;
      cout << postList[0].get_num_likes() << endl;
      cout << postList[0].get_price()<< endl;
      cout << postList[0].get_poster() << endl;
      cout << postList[0].get_product_picture() << endl;
      cout << postList[0].size_in_bytes() << endl;
      cout << _global_mem[offset_for_product_price()+1] << endl;
    }

