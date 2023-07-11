#include <iostream>
using namespace std;

struct Vector {
    int* m_pVect; // Puntero al búfer
    int m_nCount; // Controla cuántos elementos se utilizan realmente
    int m_nMax; // Controla cuántos elementos están asignados como máximo
    int m_nDelta; // Para controlar el crecimiento
};


void Resize(Vector* pThis) {
    pThis->m_pVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));
    // El máximo debe incrementarse por delta
    pThis->m_nMax += pThis->m_nDelta;
}

void Insert(Vector* pThis, int elem) {
    if (pThis->m_nCount == pThis->m_nMax) // Verificar el desbordamiento
        Resize(pThis); // Cambiar el tamaño del vector antes de insertar elem
    // Insertar el elemento al final de la secuencia
    pThis->m_pVect[pThis->m_nCount++] = elem;
}


int main() {
    Vector v;
    v.m_pVect = nullptr;
    v.m_nCount = 0;
    v.m_nMax = 0;
    v.m_nDelta = 10;

    // Valores predefinidos para el vector
    int valoresPredefinidos[] = {5, 10, 15, 20, 25};
    int numElementos = sizeof(valoresPredefinidos) / sizeof(int);

    // Asignar memoria para el vector
    v.m_pVect = (int*)malloc(sizeof(int) * numElementos);
    v.m_nMax = numElementos;

    // Copiar los valores predefinidos al vector
    for (int i = 0; i < numElementos; i++) {
        v.m_pVect[i] = valoresPredefinidos[i];
        v.m_nCount++;
    }

    // Imprimir los elementos del vector
    cout << "Elementos en el vector: ";
    cout << "[ ";
    for (int i = 0; i < v.m_nCount; i++)
        cout << v.m_pVect[i] << " ";
    cout << "]";
    cout << endl;

    // Liberar la memoria asignada al vector
    free(v.m_pVect);
    v.m_pVect = nullptr;
    v.m_nCount = 0;
    v.m_nMax = 0;

    return 0;
}
