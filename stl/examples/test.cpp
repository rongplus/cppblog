#include "test.h"

int g_value = 0;

int ainit()
{
    g_value = 10;
    return g_value;
}

int aget()
{
    return g_value;
}

void aset(int n)
{
    g_value = n;
}