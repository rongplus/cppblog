#include "factory.h"

#include "manager.h"

factory::factory(/* args */) { manager *a = new manager(); }

factory::~factory() {}
int factory::GetA() { return 10; }
int factory::GetB() { return 10; }