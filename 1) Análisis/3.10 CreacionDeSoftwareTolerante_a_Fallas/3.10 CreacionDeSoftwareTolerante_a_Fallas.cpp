#include <iostream>
using namespace std;

class CArithmetic {
public:
    static double Addition(double a, double b);
    static double Subtraction(double a, double b);
    static double Multiplication(double a, double b);
    static double Division(double a, double b);
};

double CArithmetic::Addition(double a, double b) {
    return a + b;
}

double CArithmetic::Subtraction(double a, double b) {
    return a - b;
}

double CArithmetic::Multiplication(double a, double b) {
    return a * b;
}

double CArithmetic::Division(double a, double b) {
    if (b == 0.0) {
        throw 0; // Se lanza una excepción aquí
    }
    return a / b;
}

int main() {
    double x, y, result;

    // Leer los valores de x e y desde el usuario
    cout << "Ingrese el valor de x: ";
    cin >> x;
    cout << "Ingrese el valor de y: ";
    cin >> y;

    // Ejecutar la suma
    result = CArithmetic::Addition(x, y);
    cout << "Resultado de la suma: " << result << endl;

    // Ejecutar la resta
    result = CArithmetic::Subtraction(x, y);
    cout << "Resultado de la resta: " << result << endl;

    // Ejecutar la multiplicación
    result = CArithmetic::Multiplication(x, y);
    cout << "Resultado de la multiplicación: " << result << endl;

    try {
        // Ejecutar la división
        result = CArithmetic::Division(x, y);
        cout << "Resultado de la división: " << result << endl;
    }
    catch (int errorcode) {
        cout << "Error: División por cero." << endl;
    }

    return 0;
}
