#include <iostream>
#include <map>
#include "Multiton.h"
using namespace std;
int main()
{
    Snake* snake1 = SnakeManager::getInstance("Fire");
    Snake* snake2 = SnakeManager::getInstance("Electric");
    Snake* snake3 = SnakeManager::getInstance("Water");
	Snake* snake4 = SnakeManager::getInstance("Water");
    cout << snake1->getName() << endl;
    cout << snake2->getName() << endl;
    cout << snake3->getName() << endl;
	cout << snake4->getName() << endl;
    snake1->attack();
    snake2->attack(); 
	snake3->attack(); 
	snake4->attack(); 
	if (snake3 == snake4) cout << "El puntero de ambos apunta a la unica instancia de WaterSnake activa" << endl;
    return 0;
}