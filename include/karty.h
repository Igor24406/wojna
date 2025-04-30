#ifndef KARTY_H
#define KARTY_H

#include <vector>
#include <string>

//struktura reprezentujaca karte
struct Karta
{
	int wartosc;
	std::string nazwa;
};

std::vector <Karta> utworzTalie();

#endif