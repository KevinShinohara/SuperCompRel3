#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Escreva um Palíndromo: ";
    cin >> str;

    bool isPalindrome = true;
    int n = str.length();

    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    // Exibe o resultado
    if (isPalindrome) {
        cout << "É um palindromo." << endl;
    } else {
        cout << "Não é um palindromo." << endl;
    }

    return 0;
}
