
#include "contactmanager.h"
#include <algorithm>


void ContactManager::addContact(const Contact &con) 
{
    m_contacts.push_back(con);
}

void ContactManager::delContact(int index) 
{
    //m_contacts.remove(index);
    auto cond = get(index) ;
    //m_contacts.remove(cond);

}

void ContactManager::insertContact(int index, const Contact& con) 
{
    auto con1 = get(index);
    //m_contacts.insert(con, con);
}

void ContactManager::modifyContact(int index, const Contact& con) 
{
    auto con1 = get(index);

}

const list<Contact>& ContactManager::getContacts() const
{
    return m_contacts;
}

Contact ContactManager::contact(int index) const
{
    auto con = get(index);
    return con;
}

Contact ContactManager::get(int index) const
{
    auto con = m_contacts.begin();
    while ( index-- > 0 && con != m_contacts.end())
    {
        /* code */
        con++;
    }
    return *con;
    
}

ContactManager::ContactManager() 
{
    
}
