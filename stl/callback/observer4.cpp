#include "observer4.h"
#include <iostream>
Observer4::Observer4() 
{
    
}

void Observer4::notified(const std::string &msg) 
{
    std::cout <<"Observer 4 - " <<  "Got message " << msg << std::endl;
}
