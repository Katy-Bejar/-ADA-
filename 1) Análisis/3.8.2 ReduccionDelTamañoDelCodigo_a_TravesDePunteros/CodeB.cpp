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

typedef float (*lpfnOperation)(float, float);

int main() {
    lpfnOperation vpf[4] = {&Addition, &Subtraction, &Multiplication, &Division};
    float a, b, c;
    int opt;

    // Ingresar los operandos
    cin >> a >> b;

    // Ingresar la operación 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division
    cin >> opt;

    // La siguiente línea reemplaza el switch y realiza la llamada a través del puntero a función
    c = (*vpf[opt])(a, b);

    cout << "Resultado: " << c << endl;

    return 0;
}
