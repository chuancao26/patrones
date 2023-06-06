#pragma once
#define MULTITON_H
#ifdef MULTITON_H
#include <iostream>
#include <string>
using namespace std;
class Multiton
{
	private:
		//Mapa que relaciona clave string con punteros tipo multiton
		static map<string, Multiton*> instances;
		string key; 
		Multiton(string key_){key = key_;}
		friend ostream& operator<<(ostream& os, const Multiton& a)
		{
			os << a.key << endl;
			return os;
		}
		Multiton(const Multiton&) = delete;
		Multiton& operator=(const Multiton&) = delete;
	public:
		static Multiton* getInstance(string key, int maxInstances)
		{
			// verificar si la clave ya existe
			if(instances.find(key) == instances.end())
			{
				if (instances.size() < maxInstances)
				{
					instances[key] = new Multiton(key);
				}
				else
				{
					cout << "Se paso la cantidad de objetos instanciables a la vez" << endl;
					return nullptr;
				} 
				
			}
			return instances[key];

		}
		void print()
		{
			cout << key << endl;
		}
};
map<string, Multiton*>Multiton :: instances;
#endif // MULTITON_H

