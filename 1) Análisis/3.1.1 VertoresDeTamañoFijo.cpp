#include <iostream>
using namespace std;

int gVect[100]; // Buffer para almacenar los elementos
int gnCount; // Contador para conocer el número de elementos utilizados

void Insert(int elem){
    if (gnCount < 100) // Solo podemos insertar si hay espacio
        gVect[gnCount++] = elem; // Insertar el elemento al final 
}

int main(){
    // Agregar algunos elementos al vector
    Insert(10);
    Insert(20);
    Insert(30);

    // Imprimir los elementos del vector
    cout << "Elementos en el vector: ";
    for (int i = 0; i < gnCount; i++)
        cout << gVect[i] << " ";
    cout << endl;

    return 0;
}