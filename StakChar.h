#pragma once
#include <iostream>
#include <stdbool.h>
#include "Stale.h"

using namespace std;

struct KontenerChar
{
	char zawartosc;
	KontenerChar* nastepny;
	KontenerChar* poprzedni;
};

class StakChar {
public:

	StakChar();
	~StakChar();

	void dodaj(char kladzone);
	char zdejmijOperacje();
	bool czyPusty();
	void wypisz();

private:
	KontenerChar* poczatek;
	KontenerChar* koniec;
};