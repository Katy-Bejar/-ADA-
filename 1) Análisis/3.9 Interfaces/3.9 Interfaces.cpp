#include <iostream>
using namespace std;

class CArithmetic {
private:
    double attribute1;  // Ejemplo de atributo

public:
    CArithmetic();  // Constructor
    double Addition(double a, double b);
    double Subtraction(double a, double b);
    double Multiplication(double a, double b);
    double Division(double a, double b);
    // Mas metodos van aqui
};

CArithmetic::CArithmetic() {
    attribute1 = 0.0;  // Inicializar el atributo en el constructor
}

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
    return a / b;
}

int main() {
    CArithmetic arithmetic;

    double x = 5.0, y = 3.0;

    double sum = arithmetic.Addition(x, y);
    cout << "Suma: " << sum << endl;

    double difference = arithmetic.Subtraction(x, y);
    cout << "Resta: " << difference << endl;

    double product = arithmetic.Multiplication(x, y);
    cout << "Multiplicación: " << product << endl;

    double quotient = arithmetic.Division(x, y);
    cout << "División: " << quotient << endl;

    return 0;
}
