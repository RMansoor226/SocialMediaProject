#include <iostream>
#include "Network.h"

int main() {
    Profile catalog;
    catalog.createUser("Jeffrey Dom", 32, "jeffreydom21@gmail.com", 01);
    catalog.createUser("Bob Bildech", 27, "builderbob@gmail.com", 02);
    catalog.createUser("William Hemprheys", 41, "willIam@gmail.com", 03);
    catalog.printUsers();
    return 0;
}
