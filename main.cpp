#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

struct Karta {
    int wartosc; // 2-14 (2 do Asa)
    string nazwa;

    bool operator>(const Karta& other) const {
        return wartosc > other.wartosc;
    }

    bool operator==(const Karta& other) const {
        return wartosc == other.wartosc;
    }
};

vector<Karta> utworzTalie() {
    vector<Karta> talia;
    vector<string> nazwy = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            talia.push_back({j + 2, nazwy[j]});
        }
    }
    shuffle(talia.begin(), talia.end(), default_random_engine(time(nullptr)));
    return talia;
}

void wojna(queue<Karta>& g1, queue<Karta>& g2) {
    deque<Karta> stol;

    while (!g1.empty() && !g2.empty()) {
        Karta k1 = g1.front(); g1.pop();
        Karta k2 = g2.front(); g2.pop();

        stol.push_back(k1);
        stol.push_back(k2);

        cout << "Gracz 1: " << k1.nazwa << " vs Gracz 2: " << k2.nazwa << "\n";

        if (k1 > k2) {
            while (!stol.empty()) {
                g1.push(stol.front());
                stol.pop_front();
            }
            cout << "Gracz 1 wygrywa runde.\n";
        } else if (k2 > k1) {
            while (!stol.empty()) {
                g2.push(stol.front());
                stol.pop_front();
            }
            cout << "Gracz 2 wygrywa runde.\n";
        } else {
            cout << "WOJNA!\n";

            if (g1.size() < 2 || g2.size() < 2) {
                cout << "Brak kart do wojny u jednego z graczy.\n";
                break;
            }

            for (int i = 0; i < 2; ++i) {
                stol.push_back(g1.front()); g1.pop();
                stol.push_back(g2.front()); g2.pop();
            }

            cout << "Kontynuacja wojny...\n";
        }
    }
}

int main() {
    vector<Karta> talia = utworzTalie();

    queue<Karta> gracz1, gracz2;
    for (int i = 0; i < 26; ++i) {
        gracz1.push(talia[i]);
        gracz2.push(talia[i + 26]);
    }

    int runda = 0;
    while (!gracz1.empty() && !gracz2.empty()) {
        cout << "\n--- Runda " << ++runda << " ---\n";
        wojna(gracz1, gracz2);
    }

    if (gracz1.empty()) cout << "\nGracz 2 wygrywa gre!\n";
    else cout << "\nGracz 1 wygrywa gre!\n";

    return 0;
}

