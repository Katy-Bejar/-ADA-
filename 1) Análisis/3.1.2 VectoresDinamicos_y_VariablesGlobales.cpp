#include <iostream>
using namespace std;

int *gpVect = NULL; // Búfer dinámico para guardar los elementos int
int gnCount = 0; // Contador para saber el numero de elementos usados ​​int
int gnMax = 0; // Variable que contiene el tamaño del asignado
// memoria
void Resize(); // Prototipo de la función Resize

void Insert(int elem)
{
    if (gnCount == gnMax) // No hay espacio en este momento para elem
        Resize(); // Cambiar el tamaño del vector antes de insertar elem
    gpVect[gnCount++] = elem; // Inserta el elemento al final de la secuencia
}

void Resize()
{
    const int delta = 10; // Usado para aumentar el tamaño del vector
    gpVect = (int*)realloc(gpVect, sizeof(int) * (gnMax + delta));
    // También puedes usar el siguiente código:
    // int *pTemp, i;
    // pTemp = new int[gnMax + delta]; // Asignar un nuevo vector
    // for(i = 0 ; i < gnMax ; i++) // Transferir los elementos
    // pTemp[i] = gpVect[i]; // también podemos usar la función memcpy
    // eliminar [ ] gpVect; // borra el viejo vector
    // gpVect = pTemp; // Actualizar el puntero
    gnMax += delta; // El Max tiene que ser incrementado por delta
}

int main()
{
    // Asigna memoria para el vector
    gpVect = (int*)malloc(sizeof(int) * 5);
    gnMax = 5;

    // Inicializa el vector con algunos números predefinidos
    gpVect[0] = 10;
    gpVect[1] = 20;
    gpVect[2] = 30;
    gpVect[3] = 40;
    gpVect[4] = 50;
    gnCount = 5;

    // Imprime los elementos del vector
    cout << "Elementos en el vector: ";
    cout << "[ ";
    for (int i = 0; i < gnCount; i++)
        cout << gpVect[i] << " ";
    cout << "]";
    cout << endl;

    // Libera la memoria asignada al vector
    free(gpVect);
    gpVect = NULL;
    gnCount = 0;
    gnMax = 0;

    return 0;
}

