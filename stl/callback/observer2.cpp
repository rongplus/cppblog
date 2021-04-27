#include "observer2.h"
#include <iostream>
Observer2::Observer2() 
{
    
}

void Observer2::notified(const std::string &msg) 
{
    std::cout <<"Observer 2 - " <<  "Got message " << msg << std::endl;
}
