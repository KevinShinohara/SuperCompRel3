//Escreva um programa que peça ao usuário para inserir uma string e exiba o número de
//caracteres na string.
#include <iostream>
using namespace std;

int main()
{
    string txt = "";

    cout << "Digite um palavra: ";
    cin >> txt;

cout << "O tamanho da palavra é: " << txt.length();
}


