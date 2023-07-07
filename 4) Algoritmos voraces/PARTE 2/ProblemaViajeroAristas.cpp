#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Arista {
public:
    int vert_inicio, vert_final, peso_arista;

    Arista(int vert_inicio, int vert_final, int peso_arista) {
        this->vert_inicio = vert_inicio;
        this->vert_final = vert_final;
        this->peso_arista = peso_arista;
    }
};

class Grafo {
private:
    int V; 
    vector<Arista> aristas; 

public:
    Grafo(int V) {
        this->V = V;
    }

    void insertar_arista(int vert_inicio, int vert_final, int peso_arista) {
        Arista arista(vert_inicio, vert_final, peso_arista);
        aristas.push_back(arista);
    }

    static bool compararPesoAristas(const Arista& a, const Arista& b) {
        return a.peso_arista < b.peso_arista;
    }

    int encontrar(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return encontrar(parent, parent[i]);
    }

    // Función para unir dos conjuntos en un conjunto único
    void unirConjuntos(vector<int>& parent, int x, int y) {
        int xset = encontrar(parent, x);
        int yset = encontrar(parent, y);
        parent[xset] = yset;
    }

    void ProblemaViajeroAristas() {
        sort(aristas.begin(), aristas.end(), compararPesoAristas);
        vector<int> parent(V, -1);
        vector<Arista> caminoResultante;

        int costoCamino = 0;

        for (auto arista : aristas) {
            int x = encontrar(parent, arista.vert_inicio);
            int y = encontrar(parent, arista.vert_final);

            if (x != y) {
                caminoResultante.push_back(arista);
                costoCamino += arista.peso_arista;

                // Unir los conjuntos de las ciudades conectadas por la arista
                unirConjuntos(parent, x, y);
            }
        }

        cout << "Camino del viajero con aristas:\n";
        for (auto arista : caminoResultante) {
            cout << arista.vert_inicio << " -- " << arista.vert_final << "\n";
        }
        cout << "Costo total: " << costoCamino << endl;
    }
};

int main() {
    int V, E;
    cout << "Ingresar el número de ciudades: ";
    cin >> V;
    cout << "Ingresar el número de aristas: ";
    cin >> E;

    Grafo graph(V);

    cout << "Ingresar las aristas: " << endl;
    for (int i = 0; i < E; i++) {
        int vert_inicio, vert_final, peso_arista;
        cin >> vert_inicio >> vert_final >> peso_arista;
        graph.insertar_arista(vert_inicio, vert_final, peso_arista);
    }

    graph.ProblemaViajeroAristas();

    return 0;
}
