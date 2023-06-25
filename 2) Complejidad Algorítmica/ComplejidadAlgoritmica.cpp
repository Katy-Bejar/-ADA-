#include<iostream>
#include<array>
using namespace std;

//COMPLEJIDAD O(N)
void function1(int N){
    int complejidad = 0;

    for(int i=0; i<=N; i++){ // N+1
        complejidad++;

        if(i%2 == 0){ // N+1
            complejidad++;

            //cout << i << "\n Complejidad "; // (N+1)/2 
            complejidad++;
        }
    }
    cout << "\n Complejidad function1 = " << complejidad;
} 

//COMPLEJIDAD O(N*N)
void function2(int N){
    int complejidad = 0;

    for(int i=0; i<=N; i++){ // N+1  
        complejidad++;

        for(int j=0; j<=N; j++){ // N+1(N+1)
            complejidad++;

            //cout << i << ";" << j; // N+1(N+1)
            complejidad++;
        }
    }
    cout << "\n Complejidad function2 = " << complejidad;
}

//COMPLEJIDAD O(A*B)
void function3(int A[], int B[], int lengthA, int lengthB){
    int complejidad = 0; 

    for(int i=0; i<lengthA; i++){ // A
        complejidad++; 

        for(int j=0; j<lengthB; j++){ // A*B 
            complejidad++; 

            //cout << A[i] << ";" << B[j]; // A*B
            complejidad ++; 
        }
    }
    cout << "\n Complejidad function3 = " << complejidad;
}

//COMPLEJIDAD O(N*log N)
void function4(int N){
    int complejidad = 0;

    for(int i=0; i<=N; i++){ // N+1
        complejidad++;

        int j=1; // N+1
        complejidad++;

        while(j<N){ 
        //en cada iteracion de este bucle j se multiplica por 2
        //la complejidad de este bucle sera θ(log N)
        //las iteraciones puede aproximarse a log de N en base 2 
            complejidad++;

            //cout << j; // θ(1)
            complejidad++;

            j = j*2;  // θ(1)
            complejidad++;
        }
    }
    cout << "\n Complejidad function4 = " << complejidad;
}

//COMPLEJIDAD O(N)
void function5(int N){
    int complejidad = 0;

    for(int i=0; i<=N; i++){ // N+1
        complejidad++;

        if(i%2 == 0){ // N+1
            complejidad++;
            
            //cout << i; // (N+1)/2
            complejidad++;
        }
    }
    for(int i=0; i<=N; i++){ // N+1
        complejidad++;

        if(i%2 != 0){ // N+1
            complejidad++;

            //cout << i; // (N+1)/2
            complejidad++;
        }
    }
    cout << "\n Complejidad function5 = " << complejidad;
}

//COMPLEJIDAD O(log N)
void function6(int N){
    int complejidad = 0;

    int i=1; // θ(1)
    complejidad++;

    while(i<N){ // se ejecuta mientras i<N
    //en este bucle el valor de i se duplica, 
    //por lo que tiene una complejidad de O(log N)
        complejidad++;

        //cout << i; //θ(1)
        complejidad++;

        i = i*2; // el valor de i se duplica //θ(1)
        complejidad++;
    }
    cout << "\n Complejidad function6 = " << complejidad;
}

//COMPLEJIDAD O(1)
void function7(int N){
    int complejidad = 0;

    N = 1000; // θ(1)
    complejidad++;

    if(N%2 == 0){ // θ(1)
        complejidad++;

        //cout << "par"; // θ(1)
        complejidad++;
    }
    else{
        //cout << "impar"; // θ(1)
        complejidad++;
    }
    cout << "\n Complejidad function7 = " << complejidad;
}

int  main(){
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {6, 7, 8, 9, 10};

    int lengthA = sizeof(A) / sizeof(A[0]);
    int lengthB = sizeof(B) / sizeof(B[0]);

    function1(10);
    function2(10);
    function3(A, B, lengthA, lengthB);
    function4(10);
    function5(10);
    function6(10);
    function7(10);
}