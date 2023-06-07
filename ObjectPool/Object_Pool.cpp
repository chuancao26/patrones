#include <iostream>

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
        cout << "Ave volando" << endl;
    }
};

class ObjectPool {
private:
    Ave* avesDisponibles;
    int maxSize;
    int currentIndex;

public:
    ObjectPool(int size) {
        avesDisponibles = new Ave[size];
        maxSize = size;
        currentIndex = 0;
    }

    ~ObjectPool() {
        delete[] avesDisponibles;
    }

    Ave* ObtenerAve() {
        if (currentIndex < maxSize) {
            Ave* ave = &avesDisponibles[currentIndex];
            currentIndex++;
            return ave;
        } else {
            return nullptr;
        }
    }

    void LiberarAve(Ave* ave) {
        if (currentIndex > 0 && currentIndex <= maxSize) {
            currentIndex--;
            avesDisponibles[currentIndex] = *ave;
        }
    }
};

int main() {
    int tamanoMaximo = 5;
    ObjectPool pool(tamanoMaximo);

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
