#include <iostream>
using namespace std;

float Addition(float a, float b) {
    return a + b;
}

float Subtraction(float a, float b) {
    return a - b;
}

float Multiplication(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    return a / b;
}

typedef float (*ArithmeticFunction)(float, float);

int main() {
    float a, b, c;
    int opt;

    // Ingresar los operandos
    cin >> a >> b;

    // OPT-> 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division
    cin >> opt;

    ArithmeticFunction arithmeticFunction;

    switch (opt) {
        case 0:
            arithmeticFunction = Addition;
            break;
        case 1:
            arithmeticFunction = Subtraction;
            break;
        case 2:
            arithmeticFunction = Multiplication;
            break;
        case 3:
            arithmeticFunction = Division;
            break;
        // Agregar más casos para otras operaciones
        default:
            cerr << "Opción inválida." << endl;
            return 1;
    }

    c = arithmeticFunction(a, b);

    cout << "Resultado: " << c << endl;

    return 0;
}
