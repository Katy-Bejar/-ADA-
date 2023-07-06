#include <iostream>
using namespace std;

void cambioMoneda(int monedas[], int sizeArray, int cantidad) {
    int resultado[sizeArray] = {0};
    
    // Recorre de mayor a menor las monedas
    for (int i = 0; i < sizeArray; i++) {
        while (cantidad >= monedas[i]) {
            resultado[i]++;
            cantidad -= monedas[i];
        }
    }
    
    // Imprimie el resultado
    for (int i = 0; i < sizeArray; i++) {
        if (resultado[i] > 0) cout << "Se necesita " << resultado[i] << " monedas de '" << monedas[i] << "'" << endl; 
    }
}

int main() {
    int monedas[] = {50, 20, 10, 5, 2, 1};
    int n = sizeof(monedas) / sizeof(monedas[0]);
    int cantidad = 93;
    
    cambioMoneda(monedas, n, cantidad);
    
    return 0;
}