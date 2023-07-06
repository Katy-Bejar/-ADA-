#include <iostream>
#include <cmath>
using namespace std;

double potencia(double base, int exponente) {
    if (exponente == 0) return 1.0;

    double mitad = potencia(base, exponente/2);
    double resultado = pow(mitad,2);

    if (exponente % 2 == 1) resultado *= base;

    return resultado;
}

int main() {
    double base = 3.00;
    int exponente = 8;

    double resultado = potencia(base, exponente);
    cout << "El resultado de " << base << " elevado a la " << exponente << " es: " << resultado << endl;

    return 0;
}