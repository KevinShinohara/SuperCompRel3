//Escreva um programa que peça ao usuário para inserir um número e informe se ele é
//par ou ímpar.

#include <iostream>
using namespace std;

int main()
{
    int num;

    cout << "Digite um numero: ";
    cin >> num;

    if (num%2==0)
        cout <<"É par"<<endl;
    else
        cout <<"É impar"<<endl;
    return 0;
}