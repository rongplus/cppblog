#pragma once

#include "contact.h"
#include <list>
using namespace std;
class ContactManager
{
public:
    ContactManager();
    void addContact(const Contact &con);
    void delContact(int index);
    void insertContact(int index, const Contact& con);
    void modifyContact(int index, const Contact& con);
    const list<Contact>& getContacts() const;
    Contact contact(int index) const;

    void init();

private:
    list<Contact> m_contacts;
    Contact get(int) const;
};