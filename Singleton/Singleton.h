#define SINGLETON_H
#ifdef SINGLETON_H 
#include <iostream>
using namespace std;
class Singleton
{
    private:
        static Singleton* instance;
        string name;
        Singleton(string name_){name = name_;}
        friend ostream& operator<<(ostream& output, const Singleton& a)
        {
            output << a.name << endl;
            
            return output;
        }
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        ~Singleton()
        {
            delete instance;
        }
    public:
        static Singleton* getInstance(string name_)
        {
            if(!instance)
            {
                instance = new Singleton(name_);
            }
            return instance;
        }
};
Singleton* Singleton::instance = nullptr;
#endif