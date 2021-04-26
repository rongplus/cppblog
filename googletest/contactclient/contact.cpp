#include "contact.h"
#include <iostream>
using namespace std;
Contact::Contact(string name, string gender) : m_name(name), m_gender(gender)
{
    cout << "Construct " << name << endl;
}

string Contact::name() const
{
    return m_name;
}

string Contact::gender() const
{
    return m_gender;
}

list<string> Contact::phones() const
{
    return m_phones;
}

list<string> Contact::addresses() const
{ // NOLINT
    return m_addresses;
}

bool Contact::addPhone(const string &phone)
{
    m_phones.push_back(phone);
    return true;
}

bool Contact::addAddress(const string &address)
{
    m_addresses.push_back(address);
    return true;
}
