#include <iostream>
#include <vector>

using namespace std;

class Ave {
public:
    Ave() {
        cout << "Ave creada" << endl;
    }

    ~Ave() {
        cout << "Ave destruida" << endl;
    }

    void Volar() {
        // Lógica para volar
        cout << "Ave volando" << endl;
    }
};

class ObjectPool {
private:
    vector<Ave*> avesDisponibles;
    vector<Ave*> avesEnUso;

public:
    ObjectPool(int size) {
        for (int i = 0; i < size; i++) {
            avesDisponibles.push_back(new Ave());
        }
    }

    ~ObjectPool() {
        for (auto ave : avesDisponibles) {
            delete ave;
        }
        for (auto ave : avesEnUso) {
            delete ave;
        }
    }

    Ave* ObtenerAve() {
        if (avesDisponibles.empty()) {
            return nullptr;
        }
        Ave* ave = avesDisponibles.back();
        avesDisponibles.pop_back();
        avesEnUso.push_back(ave);
        return ave;
    }

    void LiberarAve(Ave* ave) {
        for (int i = 0; i < avesEnUso.size(); i++) {
            if (avesEnUso[i] == ave) {
                avesEnUso.erase(avesEnUso.begin() + i);
                avesDisponibles.push_back(ave);
                break;
            }
        }
    }
};

int main() {
    int tamanoMaximo = 5;
    ObjectPool pool(tamanoMaximo);

    // Simulación del juego
    for (int i = 0; i < 8; i++) {
        Ave* ave = pool.ObtenerAve();
        if (ave != nullptr) {
            ave->Volar();
            pool.LiberarAve(ave);
        } else {
            cout << "No hay aves disponibles en el pool" << endl;
        }
    }

    return 0;
}
