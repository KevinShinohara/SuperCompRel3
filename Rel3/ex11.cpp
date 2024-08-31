// Estatísticas de Texto: Escreva um programa que leia um arquivo de texto e calcule as seguintes
// estatísticas: número total de palavras, número total de linhas, número médio de palavras por linha e a palavra mais frequente.
// Em seguida, grave essas estatísticas em um novo arquivo de texto.

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string inputFileName = "input.txt";
    string outputFileName = "output.txt";

    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile.is_open()) {
        cerr << "Arquivo não pode ser input aberto!" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Arquivo não pode ser aberto output!" << endl;
        return 1;
    }

    string line, word;
    int totalWords = 0;
    int totalLines = 0;
    map<string, int> wordFrequency;
    vector<int> wordsPerLine;

    while (getline(inputFile, line)) {
        totalLines++;
        stringstream ss(line);
        int wordsInThisLine = 0;

        while (ss >> word) {
            totalWords++;
            wordsInThisLine++;
            wordFrequency[word]++;
        }

        wordsPerLine.push_back(wordsInThisLine);
    }

    double averageWordsPerLine = totalWords / static_cast<double>(totalLines);

    string mostFrequentWord;
    int maxFrequency = 0;
    for (const auto& pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostFrequentWord = pair.first;
        }
    }

    outputFile << "Total de Letras: " << totalWords << endl;
    outputFile << "Total de Linhas: " << totalLines << endl;
    outputFile << "média de : " << averageWordsPerLine << endl;
    outputFile << "Most frequent word: " << mostFrequentWord << " (Frequency: " << maxFrequency << ")" << endl;

    inputFile.close();
    outputFile.close();

    cout << "Statistics written to " << outputFileName << endl;

    return 0;
}
