//Escreva um programa que peça ao usuário para inserir 10 números em um vetor e
//determine qual é o maior número
#include <iostream>
using namespace std;

int main()
{

    float valor;    
    float vetor[10];
    float maior_numero = 0;
    for (int i = 0; i <10; i ++) {
        //cout << "Primeiro numero: ";
        cin >> valor;
        vetor[i] = valor;
        if(valor > maior_numero){
            maior_numero = valor;
        }
    }

        cout << "A maior número é: " << maior_numero;





    return 0;
}

