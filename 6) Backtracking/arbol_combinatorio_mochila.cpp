#include <iostream>
#include <vector>
using namespace std;

int CapacidadMochila = 7;
vector<int> beneficios = {2, 3, 4, 5};
vector<int> pesos = {1, 2, 3, 4};
vector<int> mejorSolucion;
int mejorBeneficio = 0;

void MostrarMejorSolucion() {
    cout << "Mejor solución:" << endl;
    int totalBeneficio = 0;
    for (int i = 0; i < mejorSolucion.size(); ++i) {
        if (mejorSolucion[i] == 1) {
            cout << "Objeto " << i + 1 << ": Beneficio = " << beneficios[i] << ", Peso = " << pesos[i] << endl;
            totalBeneficio += beneficios[i];
        }
    }
    cout << "Total beneficio: " << totalBeneficio << endl;
}

void Backtracking(int nivel, vector<int>& solucion, int beneficioActual, int pesoActual) {
    if (nivel == beneficios.size()) {
        if (beneficioActual > mejorBeneficio && pesoActual <= CapacidadMochila) {
            mejorBeneficio = beneficioActual;
            mejorSolucion = solucion;
        }
        return;
    }

    solucion[nivel] = 0;
    Backtracking(nivel + 1, solucion, beneficioActual, pesoActual);
    solucion[nivel] = 1;
    Backtracking(nivel + 1, solucion, beneficioActual + beneficios[nivel], pesoActual + pesos[nivel]);
}

int main() {
    vector<int> solucion(beneficios.size(), 0);
    Backtracking(0, solucion, 0, 0);
    MostrarMejorSolucion();
    return 0;
}
