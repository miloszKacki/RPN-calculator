#pragma once
#include <iostream>
#include <stdbool.h>
#include "Stale.h"

using namespace std;

struct KontenerINT
{
	int zawartosc;
	KontenerINT* nastepny;
	KontenerINT* poprzedni;
};

class StakInt {
public:

	StakInt();
	~StakInt();

	void zwieksz();
	void zmniejsz(int ilosc);
	void dodaj(int kladzone);
	int zdejmij();
	bool czyPusty();
	void wypisz();

private:
	bool pustosc;
	KontenerINT* poczatek;
	KontenerINT* koniec;
};