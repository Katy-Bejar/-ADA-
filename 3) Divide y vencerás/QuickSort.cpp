#include <iostream>
using namespace std;

void intercambiar(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int particion(int arr[], int inicio, int fin) {
    int pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (arr[j] < pivote) {
            i++;
            intercambiar(arr, i, j);
        }
    }
    intercambiar(arr, i + 1, fin);
    return i + 1;
}

void quicksort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int indicePivote = particion(arr, inicio, fin);
        quicksort(arr, inicio, indicePivote - 1);
        quicksort(arr, indicePivote + 1, fin);
    }
}

void imprimirArray(int arr[], int tam) {
    for (int i = 0; i < tam; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {9, 8, 2, 1, 6, 7, 5, 3, 4};
    int tam = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original: "; imprimirArray(arr, tam);
    quicksort(arr, 0, tam - 1);
    cout << "Arreglo ordenado: "; imprimirArray(arr, tam);

    return 0;
}
