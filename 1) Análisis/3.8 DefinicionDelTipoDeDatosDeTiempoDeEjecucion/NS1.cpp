#include <iostream>
#include "MyNS.h"

using namespace std;

long MyNS::factorial(int n) {
    // Código complejo va aquí
    // Implementa la función factorial
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

MyNS::CTest::CTest() {
    // Inicializa algo
}

void MyNS::CTest::Method1() {
    // Escribe tu código aquí
}

template <typename T>
void Insert_Elements(CArray<T>& array) {
    // Inserta elementos en el array
    // Código va aquí
}

enum ElementType {
    INT_TYPE_ENUM,
    DOUBLE_TYPE_ENUM,
    // Agrega más tipos de elementos aquí
};

int main() {
    int option;
    cin >> option;
    switch (option) {
        case INT_TYPE_ENUM: {
            CArray<int> a;
            Insert_Elements(a);
            break;
        }
        case DOUBLE_TYPE_ENUM: {
            CArray<double> a;
            Insert_Elements(a);
            break;
        }
        // Más casos para otros tipos aquí
    }

    const unsigned long max = 500 * 1000 * 1000;
    const unsigned long step = 100 * 1000 * 1000;
    unsigned long count;
    for (count = 0L; count < max; count++) {
        if (count % step == 0L) {
            printf("some text ...\n");
        }
    }

    class CVector {
    private:
        void** m_pVect; // Puntero al búfer
        int m_nCount; // Controla cuántos elementos se utilizan realmente
        int m_nMax; // Controla el número de elementos asignados
        int m_nDelta; // Para controlar el crecimiento
        int m_nElemSize; // Tamaño del elemento
        // Puntero a la función para comparar
        int (*m_lpfnCompare)(void*, void*);
        void Init(int delta); // Inicializa nuestras variables privadas, etc.
        void Resize(); // Cambia el tamaño del vector cuando ocurre un desbordamiento
    public:
        CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta = 10); // Constructor
        void Insert(void* elem); // Inserta un nuevo elemento
        // Más métodos van aquí
    };

    // Implementación de la clase CVector
    CVector::CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta) {
        Init(delta);
        m_lpfnCompare = lpfnCompare;
        m_nElemSize = nElemSize;
    }

    void CVector::Insert(void* pElem) {
        if (m_nCount == m_nMax) // Verifica el desbordamiento
            Resize(); // Cambia el tamaño del vector antes de insertar elem
        m_pVect[m_nCount++] = DupBlock(pElem); // Inserta el elemento al final
    }

    void* CVector::DupBlock(void* pElem) {
        void* p = new char[m_nElemSize];
        return memcpy(p, pElem, m_nElemSize);
    }

    // Más implementaciones van aquí

    int fnIntCompare(void* pVar1, void* pVar2) {
        // < 0 si *(int*)pVar1 < *(int*)pVar2,
        // > 0 si *(int*)pVar1 > *(int*)pVar2,
        // 0 en otros casos
        return *(int*)pVar1 - *(int*)pVar2;
    }

    return 0;
}
