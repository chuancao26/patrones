#define GAMEMANAGER_H
#ifdef GAMEMANAGER_H 
#include <iostream>
using namespace std;
class GameManager
{
private:
    static GameManager* instance;
    string gameName;
    GameManager(const string& name)
    {
        gameName = name;
    }
    GameManager(const GameManager&) = delete;
    GameManager operator=(const GameManager&) = delete;
    ~GameManager()
    {
        delete instance;
    }
    
public:
    static GameManager* getInstance(const string& name)
    {
        if (!instance)
        {
            instance = new GameManager(name);
        }
        return instance;
    }
    void playGame()
    {
        cout << "Playing " << gameName << endl;
    }
    void setGameName(const string& name)
    {
        gameName = name;
    }
    string getGameName() const
    {
        return gameName;
    }
};
GameManager* GameManager::instance = nullptr;
#endif