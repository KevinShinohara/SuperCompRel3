//Calculadora Simples: Crie um programa que peça ao usuário para inserir dois números e uma operação (adição, subtração,
//multiplicação ou divisão). O programa deve exibir o resultado da operação.

#include <iostream>
using namespace std;

int main()
{
    float num1, num2, sum;

    cout << "Primeiro numero: ";
    cin >> num1;
    cout << "Segundo numero : ";
    cin >> num2;

    sum = num1 + num2;

    cout << "A soma é: " << sum;

    return 0;
}