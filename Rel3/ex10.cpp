#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Item {
    string name;
    int quantity;
};

void addItem(vector<Item>& stock) {
    Item newItem;
    cout << "Digite um item: ";
    cin >> newItem.name;
    cout << "Digite a quantidade: ";
    cin >> newItem.quantity;


    bool itemExists = false;
    for (auto& item : stock) {
        if (item.name == newItem.name) {
            item.quantity += newItem.quantity;
            itemExists = true;
            break;
        }
    }


    if (!itemExists) {
        stock.push_back(newItem);
    }

    cout << "Operação efetuada com sucesso!" << endl;
}

void removeItem(vector<Item>& stock) {
    string itemName;
    cout << "digite o nome do item para se remover: ";
    cin >> itemName;

    bool itemFound = false;
    for (auto it = stock.begin(); it != stock.end(); ++it) {
        if (it->name == itemName) {
            stock.erase(it);
            itemFound = true;
            cout << "item removido com sucesso!" << endl;
            break;
        }
    }

    if (!itemFound) {
        cout << "Item não encontrado" << endl;
    }
}

void viewStock(const vector<Item>& stock) {
    if (stock.empty()) {
        cout << "Stoque vazio." << endl;
    } else {
        cout << "Estoque atual:" << endl;
        for (const auto& item : stock) {
            cout << "Item: " << item.name << ", Quantidade: " << item.quantity << endl;
        }
    }
}

int main() {
    vector<Item> stock;
    int choice;

    do {
        cout << "\nShinoStocks\n";
        cout << "1. Adicione um Item\n";
        cout << "2. Remova um Item\n";
        cout << "3. Ver Estoque\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addItem(stock);
                break;
            case 2:
                removeItem(stock);
                break;
            case 3:
                viewStock(stock);
                break;
            case 4:
                cout << "Saindo." << endl;
                break;
            default:
                cout << "Escolha não Existente, tente novamente." << endl;
        }
    } while (choice != 4);

    return 0;
}
