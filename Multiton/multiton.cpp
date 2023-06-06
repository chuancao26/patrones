#include <iostream>
#include <map>
#include "Multiton.h"
using namespace std;
int main()
{
	Multiton* a = Multiton::getInstance("Instancia1",6);
	Multiton* b = Multiton::getInstance("Instancia2",6);
	Multiton* d = Multiton::getInstance("Instancia3",6);
	Multiton* e = Multiton::getInstance("Instancia4",6);
	Multiton* f = Multiton::getInstance("Instancia5",6);
	Multiton* c = Multiton::getInstance("Instancia6",6);
	Multiton* g = Multiton::getInstance("Instancia7",6);
	cout << *a << *b << *c;
	return 0;
}