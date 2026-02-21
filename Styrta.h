#pragma once
#include <iostream>
#include <stdbool.h>
#include "Stale.h"

using namespace std;

struct Zawartosc {
	char stan;
	char operacja;
	int operand;
};

struct Kontener
{
	Zawartosc* zawartosc;
	Kontener* nastepny;
	Kontener* poprzedni;
};

class Styrta {
public:

	Styrta();
	~Styrta();

	void dodaj(char kladzone);
	void dodaj(int kladzone);
	char sprawdzStanWierzchu();
	int zdejmijOperand();
	char zdejmijOperacje();
	bool czyPusty();

private:
	Kontener* poczatek;
	Kontener* koniec;
};