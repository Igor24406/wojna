#include <karty.h>
#include <gra.h>
#include <iostream>
#include <future>

using namespace std;

future<vector<Karta>> losowanieTalii()
{
	cout << "Tasowanie talii w osobnym watku..." << endl;
	return async(launch::async, utworzTalie);
}

int main()
{
	//losowanie talii w osobnym watku
	auto future_talia = losowanieTalii();
	vector<Karta> talia = future_talia.get();

	queue<Karta> gracz1, gracz2;

	for (int i = 0; i < 26; ++i)
	{
		gracz1.push(talia[i]);
		gracz2.push(talia[i + 26]);
	}

	int tura = 0;
	const int maksymalnaLiczbaTur = 5000;

	//petla gry
	while (!gracz1.empty() && !gracz2.empty() && tura < maksymalnaLiczbaTur)
	{
		cout << endl << "--- RUNDA " << ++tura << " ---" << endl;
		cout << "Liczba kart na reku: Gracz 1 [" << gracz1.size() << "] | Gracz 2 [" << gracz2.size() << "]" << endl;
		bool runda = rozegranieRundy(gracz1, gracz2);
		if (!runda)
		{
			break;
		}
	}

	//wyswietlanie zwyciezcy
	if (gracz1.empty())
	{
		cout << endl << "Koniec gry. Gracz 1 nie ma juz kart na rece. Gracz 2 wygrywa!" << endl;
	}
	else if (gracz2.empty())
	{
		cout << endl << "Koniec gry. Gracz 2 nie ma juz kart na rece. Gracz 1 wygrywa!" << endl;
	}
	else if (tura >= maksymalnaLiczbaTur && gracz1.size() > gracz2.size())
	{
		cout << endl << "Koniec gry. Osiagnieto maksymalna liczbe tur (" << maksymalnaLiczbaTur << "). Gracz 1 wygrywa ze wzgledu na wieksza ilosc kart.";
	}
	else if (tura >= maksymalnaLiczbaTur && gracz2.size() > gracz1.size())
	{
		cout << endl << "Koniec gry. Osiagnieto maksymalna liczbe tur (" << maksymalnaLiczbaTur << "). Gracz 2 wygrywa ze wzgledu na wieksza ilosc kart.";
	}
	else if (tura >= maksymalnaLiczbaTur && gracz1.size() == gracz2.size())
	{
		cout << endl << "Koniec gry. Osiagnieto maksymalna liczbe tur (" << maksymalnaLiczbaTur << "). Remis ze wzgledu na rowna ilosc kart miedzy graczami.";
	}

	return 0;
}