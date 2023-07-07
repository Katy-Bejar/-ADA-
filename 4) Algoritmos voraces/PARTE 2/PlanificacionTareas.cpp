#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Tareas {
private:
    int id;
    int prioridad;
    int duracion;

public:
    Tareas(int id, int prioridad, int duracion)  {
            this -> id = id;
            this -> prioridad = prioridad;
            this -> duracion = duracion;
        }

    int getId() const { 
        return id; 
    }

    int getPrioridad() const { 
        return prioridad; 
    }

    int getDuracion() const { 
        return duracion; 
    }
};

class Planificador_tareas {
private:
    vector<Tareas> lista_de_tareas;

public:
    void addTask(const Tareas& tarea) {
        lista_de_tareas.push_back(tarea);
    }

    void programarTarea() {
        sort(lista_de_tareas.begin(), lista_de_tareas.end(), [](const Tareas& tarea1, const Tareas& tarea2) {
            if (tarea1.getPrioridad() != tarea2.getPrioridad())
                return tarea1.getPrioridad() > tarea2.getPrioridad();
            else
                return tarea1.getDuracion() < tarea2.getDuracion();
        });

        while (!lista_de_tareas.empty()) {
            Tareas actual = lista_de_tareas.back();
            lista_de_tareas.pop_back();

            cout << "Ejecutando tarea " << actual.getId() << endl;
            for (int i = 0; i < actual.getDuracion(); i++) {
                cout << "Tarea " << actual.getId() << ": Progreso " << i + 1 << "\t/\t" << actual.getDuracion() << endl;
            }
        }
    }
};

int main() {
    Planificador_tareas planificador;
    planificador.addTask(Tareas(1, 2, 5)); 
    planificador.addTask(Tareas(2, 1, 3));
    planificador.addTask(Tareas(3, 3, 4));
    planificador.programarTarea();

    return 0;
}
