#include <karty.h>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

//tworzenie talii
vector <Karta> utworzTalie()
{
	vector<Karta> talia;
	vector<string> nazwy = { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			talia.push_back({ j + 2, nazwy[j] });
		}
	}

	shuffle(talia.begin(), talia.end(), default_random_engine(time(nullptr)));
	return talia;
}