#include <iostream>
using namespace std;

template <typename Type>
class CVector {
private:
    Type* m_pVect; // Puntero al búfer
    int m_nCount; // Controla cuántos elementos se utilizan realmente
    int m_nMax; // Controla el número de elementos asignados
    int m_nDelta; // Para controlar el crecimiento

    void Init(int delta); // Inicializa nuestras variables privadas, etc.
    void Resize(); // Cambia el tamaño del vector cuando ocurre un desbordamiento

public:
    CVector(int delta = 10); // Constructor
    void Insert(Type elem); // Inserta un nuevo elemento
    int GetCount() const; // Obtiene el número de elementos utilizados
    const Type& operator[](int index) const; // Operador de acceso constante
};

// Implementación de la clase CVector
template <typename Type>
CVector<Type>::CVector(int delta) {
    Init(delta);
}

template <typename Type>
void CVector<Type>::Init(int delta) {
    m_pVect = nullptr;
    m_nCount = 0;
    m_nMax = 0;
    m_nDelta = delta;
}

template <typename Type>
void CVector<Type>::Resize() {
    const int newMax = m_nMax + m_nDelta;
    Type* temp = new Type[newMax];
    for (int i = 0; i < m_nCount; i++) {
        temp[i] = m_pVect[i];
    }
    delete[] m_pVect;
    m_pVect = temp;
    m_nMax = newMax;
}

template <typename Type>
void CVector<Type>::Insert(Type elem) {
    if (m_nCount == m_nMax) // Verifica el desbordamiento
        Resize(); // Cambia el tamaño del vector antes de insertar elem
    m_pVect[m_nCount++] = elem; // Inserta el elemento al final
}

template <typename Type>
int CVector<Type>::GetCount() const {
    return m_nCount;
}

template <typename Type>
const Type& CVector<Type>::operator[](int index) const {
    return m_pVect[index];
}

int main() {
    CVector<int> vector; // Crear una instancia de CVector con elementos de tipo int

    vector.Insert(5); // Insertar un elemento en el vector
    vector.Insert(10);
    vector.Insert(15);

    for (int i = 0; i < vector.GetCount(); i++) {
        cout << vector[i] << " ";
    }
    
    cout << endl;

    return 0;
}
