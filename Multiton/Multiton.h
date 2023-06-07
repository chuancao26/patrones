#pragma once
#define MULTITON_H
#ifdef MULTITON_H
#include <iostream>
#include <string>
using namespace std;

class Snake
{
protected:
    string name;
    Snake(const string& name_)
    {
        name = name_;
    }
	Snake(const Snake&) = delete;
	Snake operator=(const Snake&) = delete;
public:
    virtual void attack() = 0;
    string getName() const
    {
        return name;
    }
};
class FireSnake : public Snake
{
public:
    FireSnake() : Snake("Fire Snake") {}

    virtual void attack()
    {
        cout << getName() << " attacks with fire!" << endl;
    }
};
class ElectricSnake : public Snake
{
public:
    ElectricSnake() : Snake("Electric Snake") {}

    virtual void attack()
    {
        cout << getName() << " attacks with electricity!" << endl;
    }
};
class WaterSnake : public Snake
{
public:
    WaterSnake() : Snake("Water Snake") {}

    virtual void attack()
    {
        cout << getName() << " attacks with water!" << endl;
    }
};
class SnakeManager
{
private:
    static map<string, Snake*> snakes;
    static int instanceCount;
    SnakeManager() {}
public:
    static Snake* getInstance(const string& key)
    {
        if (snakes.find(key) == snakes.end() && instanceCount < 3)
        {
            if (key == "Fire")
                snakes[key] = new FireSnake();
            else if (key == "Electric")
                snakes[key] = new ElectricSnake();
            else if (key == "Water")
                snakes[key] = new WaterSnake();
            instanceCount++;
        }
        return snakes[key];
    }
};
map<string, Snake*> SnakeManager::snakes;
int SnakeManager::instanceCount = 0;
#endif

