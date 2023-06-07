#include <iostream>
#include <vector>
using namespace std;
class Empresa {
private:
    static Empresa* instancia;
    string nombre;
    Empresa(const Empresa&) = delete;
    Empresa operator=(const Empresa&) = delete;
    Empresa(const string& nombre) : nombre(nombre) {}
    ~Empresa()
    {
        delete instancia;
    }
public:
    static Empresa* getInstance(const string& nombre) {
        if (!instancia)
            instancia = new Empresa(nombre);
        return instancia;
    }
    string getNombre() const {
        return nombre;
    }
};
Empresa* Empresa::instancia = nullptr;
class Departamento {
private:
    static vector<Departamento*> instancias;
    string nombre;
    Departamento(const string& nombre) : nombre(nombre) {}
    Departamento(const Empresa&) = delete;
    Departamento operator=(const Empresa&) = delete;  
    ~Departamento()
    { 
        for (Departamento* instancia : instancias)
        {
            delete instancia;
        }
    }
public:
    static Departamento* getInstance(const string& nombre) {
        for (Departamento* instancia : instancias) {
            if (instancia->nombre == nombre)
                return instancia;
        }
        Departamento* instancia = new Departamento(nombre);
        instancias.push_back(instancia);
        return instancia;
    }
    string getNombre() const {
        return nombre;
    }
};
vector<Departamento*> Departamento::instancias;
class Candidato {
private:
    string nombre;
public:
    Candidato(const string& nombre) : nombre(nombre) {}
    string getNombre() const {
        return nombre;
    }
};
class PoolCandidatos {
private:
    vector<Candidato*> candidatosDisponibles;
public:
    PoolCandidatos(int cantidad) {
        for (int i = 0; i < cantidad; i++) {
            string nombre = "Candidato " + to_string(i + 1);
            candidatosDisponibles.push_back(new Candidato(nombre));
        }
    }
    Candidato* obtenerCandidato() {
        if (candidatosDisponibles.empty())
            return nullptr;

        Candidato* candidato = candidatosDisponibles.back();
        candidatosDisponibles.pop_back();
        return candidato;
    }
    void liberarCandidato(Candidato* candidato) {
        candidatosDisponibles.push_back(candidato);
    }
};
class Empleado {
protected:
    string nombre;
public:
    Empleado(const string& nombre) : nombre(nombre) {}
    virtual Empleado* clonar() const = 0;
    virtual void trabajar() const = 0;
    string getNombre() const {
        return nombre;
    }
};
class Desarrollador : public Empleado {
public:
    Desarrollador(const string& nombre) : Empleado(nombre) {}
    Empleado* clonar() const {
        return new Desarrollador(*this);
    }
    void trabajar() const {
        cout << "El desarrollador " << nombre << " esta programando.\n";
    }
};
class Proyectista : public Empleado {
public:
    Proyectista(const string& nombre) : Empleado(nombre) {}
    Empleado* clonar() const {
        return new Proyectista(*this);
    }
    void trabajar() const {
        cout << "El proyectista " << nombre << " esta creando disenos.\n";
    }
};
int main() {
    Empresa* empresa = Empresa::getInstance("Empresa ABC");
    cout << "Nombre de la empresa: " << empresa->getNombre() << "\n\n";

    Departamento* departamento1 = Departamento::getInstance("Desarrollo");
    Departamento* departamento2 = Departamento::getInstance("Proyectos");
    cout << "Nombre del departamento 1: " << departamento1->getNombre() << "\n";
    cout << "Nombre del departamento 2: " << departamento2->getNombre() << "\n\n";

    PoolCandidatos poolCandidatos(3);
    Candidato* candidato1 = poolCandidatos.obtenerCandidato();
    Candidato* candidato2 = poolCandidatos.obtenerCandidato();
    Candidato* candidato3 = poolCandidatos.obtenerCandidato();

    if (candidato1) {
        cout << "Candidato 1: " << candidato1->getNombre() << "\n";
        poolCandidatos.liberarCandidato(candidato1);
    }

    if (candidato2) {
        cout << "Candidato 2: " << candidato2->getNombre() << "\n";
        poolCandidatos.liberarCandidato(candidato2);
    }

    if (candidato3) {
        cout << "Candidato 3: " << candidato3->getNombre() << "\n";
        poolCandidatos.liberarCandidato(candidato3);
    }
    cout << "\n";

    Desarrollador desarrollador("Max");
    Proyectista proyectista("Ana");

    Empleado* empleado1 = desarrollador.clonar();
    Empleado* empleado2 = proyectista.clonar();

    empleado1->trabajar();
    empleado2->trabajar();

    delete empleado1;
    delete empleado2;

    return 0;
}
