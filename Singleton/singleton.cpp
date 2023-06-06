#include <iostream>
#include "Singleton.h"
using namespace std;
int main()
{
    Singleton* a = Singleton::getInstance("Instancia 1");
    Singleton* b = Singleton::getInstance("Instancia 2");
    cout << *a << *b;
}