#include <iostream>
#include <algorithm>

using namespace std;

int maximoValor(int a, int b) {
    return max(a,b);
}

int mochila(int CapacidadMochila, int PesosObjetos[], int BeneficiosObjetos[], int n) {
    int tabla[n + 1][CapacidadMochila + 1];

    for (int i = 0; i <= n; i++) {
        for (int capacidad_actual = 0; capacidad_actual <= CapacidadMochila; capacidad_actual++) {
            if (i == 0 || capacidad_actual == 0) tabla[i][capacidad_actual] = 0;
            else if (PesosObjetos[i - 1] <= capacidad_actual) tabla[i][capacidad_actual] = maximoValor(BeneficiosObjetos[i - 1] + tabla[i - 1][capacidad_actual - PesosObjetos[i - 1]], tabla[i - 1][capacidad_actual]);
            else tabla[i][capacidad_actual] = tabla[i - 1][capacidad_actual];  
        }
    }

    //Imprimir los datos de entrada
    cout << "DATOS:" << endl;
    cout << "M = " << CapacidadMochila << "; p = " ;
    int contador = 0;
    cout << "( ";
    for (int i = 0; i < n; i++) {
        cout << PesosObjetos[i] << " ";
        contador++;
    }
    cout << "); ";

    cout << "n = " << contador;
    cout << "; b = ";

    cout << "( ";
    for (int i = 0; i < n; i++) {
        cout << BeneficiosObjetos[i] << " ";
    }
    cout << ") " << endl;


    //Imprimir la tabla
    cout << "\nTABLA: " << endl;
    cout << "V  ";
    for (int capacidad_actual = 0; capacidad_actual <= CapacidadMochila; capacidad_actual++) {
        cout << capacidad_actual << "  ";
    }
    cout << endl;

    for (int i = 0; i <= n; i++) {
        cout << i << "  ";
        for (int capacidad_actual = 0; capacidad_actual <= CapacidadMochila; capacidad_actual++) {
            cout << tabla[i][capacidad_actual] << "  ";
        }
        cout << endl;
    }
    return tabla[n][CapacidadMochila];
}

int main() {
    int CapacidadMochila = 6; //Capacidad de la mochila (M)
    int PesosObjetos[] = {2, 3, 4}; //Pesos de los objetos (p)
    int BeneficiosObjetos[] = {1, 2, 5}; //Beneficios de los objetos (b)
    int n = sizeof(PesosObjetos) / sizeof(PesosObjetos[0]); //Numero de objetos disponibles (n)

    int resultado = mochila(CapacidadMochila, PesosObjetos, BeneficiosObjetos, n);

    cout << "\nVALOR MAXIMO = " << resultado << endl;

    return 0;
}
