#include <iostream>
#include "Guest.h"

#include "User.h"

#include "PowerUser.h"

#include "Vip.h"

#include "Admin.h"


using namespace std;

int main()
{
    Guest g("09.211.134.222.111");
    g.print();

    User u("1110.2982.311.1009.201", "James", "5s89", "First");
    u.print();
    u.change_password("5s89", "s589");
    u.print();

    PowerUser p("1090.1345.2211.0211", "Jim", "asddsa", "Second");
    p.print();
    p.change_password("aaaa", "afgd");
    p.print();

    Vip v("1923.3309.213.11", "Caitlyn", "154321", "This is title");
    v.print();
    v.change_password("154321", "1000");
    v.set_title("Changed title");
    v.print();

    Admin a1("121.451.332.11111", "Nails", "0982", "Third");
    a1.print();
    Admin a2("9135.4111.4213.0911", "Jane", "1234", "Fourth");

    a1.change_password("1111", "123");

    a1.rate(a2);

    a1.print();
    a2.print();

    a1.change_password("111", "123");

    a2.set_title("Change");
    a1.set_username("New");

    a1.print();

    a2.print();

    a1.rate(a2);
    a2.print();

    p.rate(a2);
    a2.print();

    a2.change_username(p, "Mollie");
    p.print();

    a1.change_username(a1, "Lays");
    a1.print();
    a1.set_username("Chio");
    a1.print();

    return 0;
}

