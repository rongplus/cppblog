#include "../myinc.h"


struct S1
{
    int b;
    int c;
    char bb[10];
};

struct S2
{
    S1 s1;
};

int main()
{
    S1 ss1(1,2);
    S2* s2 = new S2;
    s2->s1.b = 10;
    s2->s1.c = 20;
    memcpy(s2->s1.bb, "Good", 10);

    S1 s1 = s2->s1;
    s1.b = 30;
    s1.c = 40;
    memcpy(s1.bb, "Morning", 10);

    cout << s2->s1.b << " " << s2->s1.c << " " << s2->s1.bb<< endl;
    cout << s1.b << " " << s1.c << " " << s1.bb << endl;


    char abv[10];
    abv = "dd";
    return 0;
}