#include "observer5.h"
#include <iostream>

Observer5::Observer5() 
{
    
}

void Observer5::notified(const std::string &msg) 
{
    std::cout <<"Observer 5 - " <<  "Got message " << msg << std::endl;
}
