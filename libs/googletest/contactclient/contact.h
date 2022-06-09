#pragma once
#include <string>
#include <list>

using namespace std;

class Contact
{
public:
    Contact() = delete;
    Contact(string name, string gender = "man");

    string name() const;
    string gender() const;
    list<string> phones() const;
    list<string> addresses() const;

    bool addPhone(const string &phone);
    bool addAddress(const string &address);

    void setName() {m_name = "MockName";}

private:
    string m_name;
    string m_gender;
    list<string> m_phones;
    list<string> m_addresses;
};