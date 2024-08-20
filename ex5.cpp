//Crie um programa que solicite ao usuário para inserir 5 números em um vetor e depois
//exiba a soma desses números

//Escreva um programa que peça ao usuário para inserir uma string e exiba o número de
//caracteres na string.
#include <iostream>
using namespace std;

int main()
{

float valor;    
float vetor[5];
    for (int i = 0; i < 5; i ++) {
        //cout << "Primeiro numero: ";
        cin >> valor;
        vetor[i] = valor;
}
float soma = 0;
  for (int i = 0; i < 5; i ++) {
        soma = soma + vetor[i];
}


    cout << "A soma é: " << soma;

    return 0;
}

