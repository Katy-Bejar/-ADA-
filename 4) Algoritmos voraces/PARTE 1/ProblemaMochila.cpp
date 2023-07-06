#include <iostream>
using namespace std;

int problemaMochila(int capacidad, int pesos[], int beneficios[], int n) {
    int dp[n + 1][capacidad + 1]; // Matriz para almacenar los resultados intermedios

    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=capacidad; ++j) {
            if (i==0 || j==0) dp[i][j] = 0;
            else if (pesos[i-1] <= j) dp[i][j] = max(beneficios[i-1] + dp[i-1][j - pesos[i-1]], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][capacidad];
}

int main() {
    int capacidadMochila = 10;
    int pesos[] = {10,3,3,4};
    int beneficios[] = {10,9,9,9};
    int n = sizeof(pesos) / sizeof(pesos[0]);

    int maxValor = problemaMochila(capacidadMochila, pesos, beneficios, n);
    cout << "El valor maximo que se puede obtener es: " << maxValor << endl;

    return 0;
}