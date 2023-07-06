#include <iostream>
#include <vector>

using namespace std;

// Función para sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

// Función para restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

// Función para multiplicar dos matrices cuadradas
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int mitad = n / 2;

    // División de las matrices en submatrices
    vector<vector<int>> A11(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A12(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A21(mitad, vector<int>(mitad, 0));
    vector<vector<int>> A22(mitad, vector<int>(mitad, 0));

    vector<vector<int>> B11(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B12(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B21(mitad, vector<int>(mitad, 0));
    vector<vector<int>> B22(mitad, vector<int>(mitad, 0));

    for (int i = 0; i < mitad; i++) {
        for (int j = 0; j < mitad; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mitad];
            A21[i][j] = A[i + mitad][j];
            A22[i][j] = A[i + mitad][j + mitad];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mitad];
            B21[i][j] = B[i + mitad][j];
            B22[i][j] = B[i + mitad][j + mitad];
        }
    }

    // Productos necesarios para la multiplicación de Strassen
    vector<vector<int>> P1 = multiplicarMatrices(A11, restarMatrices(B12, B22));
    vector<vector<int>> P2 = multiplicarMatrices(sumarMatrices(A11, A12), B22);
    vector<vector<int>> P3 = multiplicarMatrices(sumarMatrices(A21, A22), B11);
    vector<vector<int>> P4 = multiplicarMatrices(A22, restarMatrices(B21, B11));
    vector<vector<int>> P5 = multiplicarMatrices(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    vector<vector<int>> P6 = multiplicarMatrices(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    vector<vector<int>> P7 = multiplicarMatrices(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    // Submatrices de resultado
    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(P5, P4), P2), P6);
    vector<vector<int>> C12 = sumarMatrices(P1, P2);
    vector<vector<int>> C21 = sumarMatrices(P3, P4);
    vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(P1, P5), P3), P7);

    // Combinación de las submatrices para obtener la matriz resultado
    vector<vector<int>> resultado(n, vector<int>(n, 0));

    for (int i = 0; i < mitad; i++) {
        for (int j = 0; j < mitad; j++) {
            resultado[i][j] = C11[i][j];
            resultado[i][j + mitad] = C12[i][j];
            resultado[i + mitad][j] = C21[i][j];
            resultado[i + mitad][j + mitad] = C22[i][j];
        }
    }
    return resultado;
}

int main() {
    vector<vector<int>> matrizA = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> matrizB = {{7, 8, 9}, {10, 11, 12}};
    vector<vector<int>> resultado = multiplicarMatrices(matrizA, matrizB);

    for (const auto& fila : resultado) {
        for (int elemento : fila) cout << elemento << " ";     
        cout << endl;
    }
    return 0;
}