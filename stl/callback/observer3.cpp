#include "observer3.h"
#include <iostream>
Observer3::Observer3() 
{
    
}

void Observer3::notified(const std::string &msg) 
{
    std::cout <<"Observer 3 - " <<  "Got message " << msg << std::endl;
}
