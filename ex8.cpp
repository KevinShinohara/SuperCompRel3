//Crie um programa que peça ao usuário para inserir uma matriz 3x3 e depois exiba a
//soma dos elementos na diagonal principal.

#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];
    int sum = 0;

    cout << "digite os elementos:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Elemento ij [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        sum += matrix[i][i];
    }

    cout << "A soma da diagonal principal é: " << sum << endl;

    return 0;
}
