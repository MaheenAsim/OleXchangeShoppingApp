#include"/usr/local/cs/cs251/show_mem.h"
#include"Notification.h"
void Notification::read_from(const char* &mem){
            invoker =  _get_tilde_terminated_string(mem);
            mem += invoker.size() + 1;
            posted_date =  _get_tilde_terminated_string(mem);
            mem += posted_date.size() + 1;
        } 