#include "Post.h"
#include"/usr/local/cs/cs251/show_mem.h"
using namespace std;

void Post::read_from(const char* &mem){
    post_id = _get_tilde_terminated_string(mem);
    mem += post_id.size() + 1;
    product_name = _get_tilde_terminated_string(mem); 
    mem += product_name.size() + 1;
    tag = _get_tilde_terminated_string(mem);
    mem += tag.size() + 1;
    poster = _get_int(mem,4);
    mem += 4;
    num_likes = _get_int(mem, 3);
    mem += 3;
    mem += 1;
    description = _get_tilde_terminated_string(mem);
    mem += description.size() + 1;
    price = _get_float(mem, 6);
    mem += 6;
    mem += 1;
    product_picture = _get_tilde_terminated_string(mem);
    mem += product_picture.size() + 1;
}

int Post::size_in_bytes() const{
    return(post_id.size() + 1 + product_name.size() + 1 + tag.size() + 1 + 
            4 + 3 + 1 + description.size() + 1 + 6 + 1 + product_picture.size() + 1

    );
}