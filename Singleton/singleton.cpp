#include <iostream>
#include "Singleton.h"
using namespace std;
int main()
{
    GameManager* gameManager = GameManager::getInstance("MyGame");
    cout << "Game name: " << gameManager -> getGameName() << endl;
    gameManager -> playGame();
    gameManager -> setGameName("NewGame");
    cout << "Game name: " << gameManager -> getGameName() << endl;
    GameManager* gameManager2 = GameManager::getInstance("MyGame");
    if (gameManager == gameManager2) cout << "El puntero de ambos apunta a la unica instancia activa" << endl;
    gameManager2 -> setGameName("NewGame2");
    cout << "Game name: " << gameManager -> getGameName() << endl;
    return 0;
}