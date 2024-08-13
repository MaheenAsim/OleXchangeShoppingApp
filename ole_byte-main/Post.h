//#include "User.h"
//#include "Image.h"
//#include "Text.h"
#ifndef __POST_H__
#define __POST_H__
#include <string>
using namespace std;

class Post
{
private:
    string post_id;
    string product_name;
    float price;
    int poster;
    int num_likes;
    //Text description; Don't know how to integrate into React yet
    //Image product_picture; Don't know how to into React yet
    string description;
    string product_picture;
    string tag;

public:
    Post(){//: poster(){
        product_name = "";
        price = 0;
        num_likes = 0;
        description = "";
        product_picture = "";
    }

    void set_post_id(string id){post_id = id;}
    void set_product_name(string name){product_name = name;}
    void set_price(float money){price = money;}
    void set_poster(int userID){poster = userID;}
    void set_num_likes(int likes){num_likes = likes;}
    void set_description(string about_post){description = about_post;}
    void set_product_picture(string picLink){product_picture = picLink;}
    void set_tag(string tgs){tag = tgs;}
    string get_post_id()const{
        return post_id;
    }
    string get_product_tag()const{
        return tag;
    }
    string get_product_name()const{
        return product_name;
    }
    float get_price()const{
        return price;
    }
    int get_poster(){
        return poster;
    }
    int get_num_likes()const{
        return num_likes;
    }

    string get_description()const{
        return description;
    }
    string get_product_picture()const{
        return product_picture;
    }

    void read_from(const char* &mem);
    void write_to(char *mem) const;
    //~Post();
    int size_in_bytes() const;
};

#endif
