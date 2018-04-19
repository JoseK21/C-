#ifndef RMLIB_H
#define RMLIB_H

#include <iostream>
#include "tcp_client.h"
#include "rmnode.h"



class RMLib {
public:
    static bool rm_init (std::string ip, int port);
    static void rm_new (std::string j);
    template<class J,class T>
    static void rm_new(J key, T data);
    static RMnode<int,std::__cxx11::string> rm_get(int key);
    static tcp_client client;
    static void rm_delete(int key);

};

#endif // RMLIB_H
