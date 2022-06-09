#pragma once

class Contact;

int startClient();

void initContact();

void* get10Contact();

struct Abc
{
    int a;
    int b;
};
void get11Contact(Abc &abc);
void get12Contact(Abc *abc);

void get13Contact(Contact *abc);