
#include <iostream>

using namespace std;

int main() {
    int V, K;

    cout << "Vyska stromu: ";
    cin >> V;

    cout << "Sirka kmene: ";
    cin >> K;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V - i; j++) {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= V - K / 2; j++) {
            cout << " ";
        }
        for (int j = 1; j <= K; j++) {
            cout << "#";
        }
        cout << endl;
    }

    return 0;
}