#include "user.h"
#include <iostream>
using namespace std;

void printStatus(const User& user) {
cout << user.name << " HP: " << user.hp << '\n';
}