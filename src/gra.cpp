#include <gra.h>
#include <iostream>

using namespace std;

//funkcja realizujaca pojedyncza runde
bool rozegranieRundy(queue<Karta>& gracz1, queue<Karta>& gracz2)
{
	deque<Karta> stol;

	while (!gracz1.empty() && !gracz2.empty())
	{
		Karta k1 = gracz1.front(); gracz1.pop();
		Karta k2 = gracz2.front(); gracz2.pop();

		stol.push_back(k1);
		stol.push_back(k2);

		cout << "Gracz 1: " << k1.nazwa << " | Gracz 2: " << k2.nazwa << endl;

		if (k1.wartosc > k2.wartosc)
		{
			while (!stol.empty())
			{
				gracz1.push(stol.front());
				stol.pop_front();
			}
			cout << "Gracz 1 wygrywa runde." << endl;
			break;
		}
		else if (k2.wartosc > k1.wartosc)
		{
			while (!stol.empty())
			{
				gracz2.push(stol.front());
				stol.pop_front();
			}
			cout << "Gracz 2 wygrywa runde." << endl;
			break;
		}
		else
		{
			cout << "WOJNA!" << endl;
		}

		//sprawdzenie, czy obaj gracze maja wystarczajaco kart
		if (gracz1.size() < 2)
		{
			if (gracz1.size() == 1)
			{
				cout << "Koniec gry. Gracz 1 nie ma wystarczajaco kart do kontynuowania wojny. Gracz 2 wygrywa!" << endl;
			}
			return false;
		}

		if (gracz2.size() < 2)
		{
			if (gracz2.size() == 1)
			{
				cout << "Koniec gry. Gracz 2 nie ma wystarczajaco kart do kontynuowania wojny. Gracz 1 wygrywa!" << endl;
			}
			return false;
		}

		stol.push_back(gracz1.front()); gracz1.pop();
		stol.push_back(gracz2.front()); gracz2.pop();

		cout << "Gracze dokladaja po jednej zakrytej karcie..." << endl;
	}
	return true;
}