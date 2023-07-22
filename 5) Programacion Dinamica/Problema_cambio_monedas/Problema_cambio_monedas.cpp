#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int minimoValor(int a, int b) {
    return min(a, b);
}

int minMonedas(int monedas[], int n, int cantidad) {
    int dp[cantidad + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0; 
    }

    for (int i = 1; i <= cantidad; i++) {
        // Inicializa todas las cant a un valor infinito
        dp[i][0] = INT_MAX; 
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (monedas[j - 1] <= i && dp[i - monedas[j - 1]][j] != INT_MAX) {
                dp[i][j] = minimoValor(dp[i][j], dp[i - monedas[j - 1]][j] + 1);
            }
        }
    }

    // Imprimir n, P y c
    cout << "DATOS:" << endl;
    cout << "n = " << n << ", P = " << cantidad << ", c = (";
    for (int i = 0; i < n; i++) {
        cout << monedas[i];
        if (i != n - 1)
            cout << ", ";
    }
    cout << ")" << endl;

    // Imprimir la tabla
    cout << "\nTABLA:" << endl;
    cout << "D";
    for (int i = 0; i <= cantidad; i++) {
        cout << "  " << i;
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << monedas[i - 1];
        for (int j = 0; j <= cantidad; j++) {
            if (dp[j][i] == INT_MAX)
                cout << "  INF";
            else
                cout << "  " << dp[j][i];
        }
        cout << endl;
    }
    // Si no es posible formar la cantidad, devuelve -1
    return dp[cantidad][n] == INT_MAX ? -1 : dp[cantidad][n]; 
}

int main() {
    int cantidad = 8; //P
    int monedas[] = {1, 4, 6}; //c
    int n = sizeof(monedas) / sizeof(monedas[0]); //Numero de monedas

    int resultado = minMonedas(monedas, n, cantidad);

    if (resultado != -1) cout << "\nNUMERO MINIMO DE MONEDAS = " << resultado << endl;
    else cout << "ERROR\n";
    

    return 0;
}