#include <iostream>
#include <string>
#include <unordered_map>

class Character {
public:
    virtual Character* clone() = 0;

    virtual void render() = 0;

    virtual ~Character() {}  // Asegurar que la clase base tenga un destructor virtual
};

class Player : public Character {
public:
    Character* clone() override {
        return new Player(*this);
    }

    void render() override {
        std::cout << "Rendering Player character." << std::endl;
        // Lógica de renderizado específica para el personaje del jugador...
    }
};

class Enemy : public Character {
public:
    Character* clone() override {
        return new Enemy(*this);
    }

    void render() override {
        std::cout << "Rendering Enemy character." << std::endl;
        // Lógica de renderizado específica para los personajes enemigos...
    }
};

class CharacterFactory {
private:
    std::unordered_map<std::string, Character*> characterPrototypes;

public:
    CharacterFactory() {
        characterPrototypes["Player"] = new Player();
        characterPrototypes["Enemy"] = new Enemy();
        // Agregar más prototipos de personajes si es necesario...
    }

    Character* createCharacter(const std::string& type) {
        if (characterPrototypes.find(type) != characterPrototypes.end()) {
            return characterPrototypes[type]->clone();
        }
        return nullptr;
    }

    ~CharacterFactory() {
        for (auto& pair : characterPrototypes) {
            delete pair.second;  // Liberar la memoria de los prototipos
        }
    }
};

int main() {
    CharacterFactory characterFactory;

    Character* player = characterFactory.createCharacter("Player");
    Character* enemy = characterFactory.createCharacter("Enemy");

    player->render();
    enemy->render();

    delete player;
    delete enemy;

    return 0;
}
