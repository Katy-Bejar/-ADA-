#include <iostream>
#include <vector>
using namespace std;

struct Nodo {
    int nivel;
    int beneficio;
    int peso;
    int beneficioAcumulado;
};

int CapacidadMochila = 7;
vector<int> beneficios = {2, 3, 4, 5};
vector<int> pesos = {1, 2, 3, 4};
int mejorBeneficio = 0;

void MostrarMejorSolucion(const vector<int>& solucion) {
    cout << "Mejor solución encontrada:" << endl;
    int totalBeneficio = 0;
    for (int i = 0; i < solucion.size(); ++i) {
        if (solucion[i] == 1) {
            cout << "Objeto " << i + 1 << ": Beneficio = " << beneficios[i] << ", Peso = " << pesos[i] << endl;
            totalBeneficio += beneficios[i];
        }
    }
    cout << "Total beneficio: " << totalBeneficio << endl;
}

void Backtracking() {
    vector<int> solucion(beneficios.size(), 0);
    vector<Nodo> cola;
    Nodo nodoRaiz = {0, 0, 0, 0};
    cola.push_back(nodoRaiz);
    
    while (!cola.empty()) {
        Nodo nodoActual = cola.back();
        cola.pop_back();
        
        int nivel = nodoActual.nivel;
        int beneficioAcumulado = nodoActual.beneficioAcumulado;
        int pesoAcumulado = nodoActual.peso;
        
        if (nivel == beneficios.size()) {
            if (beneficioAcumulado > mejorBeneficio && pesoAcumulado <= CapacidadMochila) {
                mejorBeneficio = beneficioAcumulado;
                solucion = vector<int>(nodoActual.nivel, 0);
                for (int i = 0; i < nodoActual.nivel; ++i) solucion[i] = 1; 
            }
            continue;
        }
        
        if (pesoAcumulado + pesos[nivel] <= CapacidadMochila) {
            Nodo hijoIzquierdo = {nivel + 1, beneficioAcumulado + beneficios[nivel], pesoAcumulado + pesos[nivel], 0};
            hijoIzquierdo.beneficioAcumulado = hijoIzquierdo.beneficio + (CapacidadMochila - hijoIzquierdo.peso) * (beneficios[nivel] / pesos[nivel]);
            if (hijoIzquierdo.beneficioAcumulado > mejorBeneficio) cola.push_back(hijoIzquierdo);
            
        }
        
        Nodo hijoDerecho = {nivel + 1, beneficioAcumulado, pesoAcumulado, 0};
        hijoDerecho.beneficioAcumulado = hijoDerecho.beneficio + (CapacidadMochila - hijoDerecho.peso) * (beneficios[nivel] / pesos[nivel]);
        if (hijoDerecho.beneficioAcumulado > mejorBeneficio) cola.push_back(hijoDerecho);
    }
    MostrarMejorSolucion(solucion);
}

int main() {
    Backtracking();
    return 0;
}
