#include "observer1.h"

#include <iostream>

Observer1::Observer1() 
{
    
}

void Observer1::notified(const std::string &msg) 
{
    std::cout <<"Observer 1 - " <<  "Got message " << msg << std::endl;
}
