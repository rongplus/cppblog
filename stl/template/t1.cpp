
#include "t1.h"
#include <iostream>

class Widget1 {};
int main() {
  typedef WidgetManager<OpNewCreator<Widget1>> MyWidgetMgr;
  return 0;
}