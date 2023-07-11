#include <iostream>
using namespace std;

// Definición de la clase CVector
class CVector{
    private:
        int *m_pVect; // Puntero al búfer
        int m_nCount; // Controla cuántos elementos se utilizan realmente
        int m_nMax; // Controla cuántos elementos están asignados como máximo
        int m_nDelta; // Para controlar el crecimiento
        void Init(int delta); // Inicializa nuestras variables privadas, etc.
        void Resize(); // Cambia el tamaño del vector cuando ocurre un desbordamiento
    public:
        CVector(int delta = 10); // Constructor
        void Insert(int elem); // Inserta un nuevo elemento
        // Más métodos van aquí
};

// Implementación de la clase CVector

CVector::CVector(int delta) {
    Init(delta);
}

void CVector::Init(int delta) {
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

void CVector::Resize() {
    const int newMax = m_nMax + m_nDelta;
    int* temp = new int[newMax];
    for (int i = 0; i < m_nCount; i++) {
        temp[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = temp;
    m_nMax = newMax;
}

void CVector::Insert(int elem) {
    if (m_nCount == m_nMax) // Verifica el desbordamiento
        Resize(); // Cambia el tamaño del vector antes de insertar elem
    m_pVect[m_nCount++] = elem; // Inserta el elemento al final
}

int main() {
    CVector vector; // Crear una instancia de CVector

    vector.Insert(5); // Insertar un elemento en el vector

    return 0;
}
