#include "a2.h"
#include <gflags/gflags.h>
#include <iostream>

DEFINE_string(message, "Hello world!", "Message to print");

a2::a2(/* args */) {
  std::cout << "a2::message = " << FLAGS_message << std::endl;
}

a2::~a2() {}
