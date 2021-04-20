
#include <map>
#include <iostream>
#include "contactmanager.h"
using namespace std;

int main(int argc, char *argv[])
{
    cout << "Test Make file" << endl;

    ContactManager cm;
    {
        Contact ct("Jack");
        cm.addContact(ct);
    }

    {
        Contact ct("Mike");
        cm.addContact(ct);
    }

    for (auto it = cm.getContacts().begin(); it != cm.getContacts().end(); ++it)
    {
        cout << "cn = " << (*it).name() << endl;
    }

    return 0;
}