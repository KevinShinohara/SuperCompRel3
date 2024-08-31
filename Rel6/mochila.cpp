#include <iostream>
#include <vector>
#include <algorithm>


int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    // Caso base: não há itens restantes ou capacidade restante é zero
    if (n == 0 || W == 0) {
        return 0;
    }

    // Se o peso do último item é maior que a capacidade da mochila, ele não pode ser incluído
    if (weights[n - 1] > W) {
        return knapsack(W, weights, values, n - 1);
    } else {

        return std::max(
            values[n - 1] + knapsack(W - weights[n - 1], weights, values, n - 1),
            knapsack(W, weights, values, n - 1)
        );
    }
}


void knapsackSolution(int W, const std::vector<int>& weights, const std::vector<int>& values) {
    int n = weights.size();
    int max_value = knapsack(W, weights, values, n);
    std::cout << "Valor máximo na mochila: " << max_value << std::endl;
}

int main() {

    std::vector<int> weights1 = {3, 8, 6, 4, 5, 10, 1, 9, 3, 3};
    std::vector<int> values1 = {70, 56, 17, 91, 77, 69, 98, 54, 13, 54};
    int W1 = 10; // Capacidade da mochila para a primeira entrada

    std::vector<int> weights2 = {1, 1, 2, 2, 1};
    std::vector<int> values2 = {50, 94, 40, 39, 62};
    int W2 = 2; // Capacidade da mochila para a segunda entrada

    std::vector<int> weights3 = {58, 90, 36, 53, 8, 98, 31, 37, 36, 6};
    std::vector<int> values3 = {95, 32, 37, 54, 9, 29, 43, 59, 3, 98};
    int W3 = 100; // Capacidade da mochila para a terceira entrada

    // Solução do problema da mochila para cada entrada
    std::cout << "Entrada 1:" << std::endl;
    knapsackSolution(W1, weights1, values1);

    std::cout << "\nEntrada 2:" << std::endl;
    knapsackSolution(W2, weights2, values2);

    std::cout << "\nEntrada 3:" << std::endl;
    knapsackSolution(W3, weights3, values3);

    return 0;
}
