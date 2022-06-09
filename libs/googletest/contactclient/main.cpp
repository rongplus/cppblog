
#include <map>
#include <iostream>
#include "contactmanager.h"
#include "contactclient.h"
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
    Contact *ct = nullptr;
    get11Contact(&ct);

    cout << "Test = " << ct->name() << endl;



    for (auto it = cm.getContacts().begin(); it != cm.getContacts().end(); ++it)
    {
        cout << "cn = " << (*it).name() << endl;
    }

    return 0;
}