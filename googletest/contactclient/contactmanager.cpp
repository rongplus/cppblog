
#include "contactmanager.h"
#include "contactclient.h"
#include <algorithm>
#include <iostream>
using namespace std;
void ContactManager::addContact(const Contact &con)
{
    m_contacts.push_back(con);
}

void ContactManager::delContact(int index)
{ // NOLINT
    //m_contacts.remove(index);  // NOLINT
    auto cond = get(index);
    //m_contacts.remove(cond);  // NOLINT
}

void ContactManager::insertContact(int index, const Contact &con)
{
    auto con1 = get(index);
    //m_contacts.insert(con, con);
}

void ContactManager::modifyContact(int index, const Contact &con)
{
    auto con1 = get(index);
}

const list<Contact> &ContactManager::getContacts() const
{
    return m_contacts;
}

Contact ContactManager::contact(int index) const
{
    auto con = get(index);
    return con;
}

void ContactManager::init()
{
     Contact *ct = reinterpret_cast<Contact *>(get10Contact());
     m_contacts.push_back(*ct);
     Abc cc;
     get11Contact(cc);
     std::cout << "Abc.a = " << cc.a << std::endl;
     //m_contacts.push_back(*ct);
     get12Contact(&cc);
     std::cout << "Abc.a = " << cc.a << std::endl;
     get13Contact(ct);
     std::cout << "contact.name = " << ct->name() << std::endl;
     m_contacts.push_back(*ct);
}

Contact ContactManager::get(int index) const
{
    auto con = m_contacts.begin();
    while (index-- > 0 && con != m_contacts.end())
    {
        /* code */
        con++;
    }
    return *con;
}

ContactManager::ContactManager()
{
}
