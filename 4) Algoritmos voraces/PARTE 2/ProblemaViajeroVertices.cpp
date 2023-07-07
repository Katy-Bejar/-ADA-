#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Grafo {
private:
    int V;
    vector<vector<int>> matrizAdyacencia;

public:
    Grafo(int V) {
        this->V = V;
        matrizAdyacencia.resize(V, vector<int>(V, 0));
    }

    void addEdge(int vert_origen, int vert_destino, int peso) {
        matrizAdyacencia[vert_origen][vert_destino] = peso;
        matrizAdyacencia[vert_destino][vert_origen] = peso;
    }

    void ProblemaDelViajero() {
        vector<bool> visitados(V, false);

        visitados[0] = true;
        vector<int> ruta;
        ruta.push_back(0);

        int costo = 0;
        int verticeActual = 0;

        // Iterar hasta visitar todos los vértices
        while (ruta.size() < V) {
            int siguiente_vertice = -1;
            int pesoMinimo = numeric_limits<int>::max();

            // Encontrar el vértice no visitado más cercano
            for (int i = 0; i < V; i++) {
                if (!visitados[i] && matrizAdyacencia[verticeActual][i] < pesoMinimo) {
                    pesoMinimo = matrizAdyacencia[verticeActual][i];
                    siguiente_vertice = i;
                }
            }
            visitados[siguiente_vertice] = true;
            costo += pesoMinimo;
            verticeActual = siguiente_vertice;

            ruta.push_back(verticeActual);
        }
        ruta.push_back(0);
        costo += matrizAdyacencia[verticeActual][0];

        cout << "Camino del viajero:\n";
        for (auto vertex : ruta) {
            cout << vertex << " ";
        }
        cout << "\nCosto total: " << costo << endl;
    }
};

int main() {
    int V, E;
    cout << "Ingrese el número de vértices: ";
    cin >> V;
    cout << "Ingrese el número de aristas: ";
    cin >> E;
    
    Grafo graph(V);

    cout << "Ingrese las aristas en el formato" << endl;
    for (int i = 0; i < E; i++) {
        int vert_origen, vert_destino, peso;
        cin >> vert_origen >> vert_destino >> peso;
        graph.addEdge(vert_origen, vert_destino, peso);
    }

    graph.ProblemaDelViajero();

    return 0;
}







