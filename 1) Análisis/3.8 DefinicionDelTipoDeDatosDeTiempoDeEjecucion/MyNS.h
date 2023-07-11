#include <iostream>
using namespace std;

namespace MyNS {
    int gnCount; // Contador global
    // Algunas funciones pequeñas implementadas en línea
    double Suma(double a, double b) { return a + b; }
    // Algunos prototipos
    long factorial(int n); // Función global
    class CTest {
    public:
        CTest();
        void Metodo1();
    };
    // Más variables, funciones, métodos, clases, estructuras van aquí
};
