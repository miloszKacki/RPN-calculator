#pragma once
#include <iostream>
#include <stdbool.h>
#include "Stale.h"
#include "StakInt.h"

struct ZawartoscONP
{
	int operand;
	char operacja;
	int iloscArgumentow;
};

struct KontenerONP
{
	ZawartoscONP* zawartosc;
	KontenerONP* nastepny;
	KontenerONP* poprzedni;
};

class StakONP {
public:

	StakONP();
	~StakONP();

	void dodaj(int operand);
	void dodaj(char operacja,int iloscArg);
	void nalozOperacje(char operacja, StakInt* ilosciArg);
	
	char zdejmijOperacje(int * iloscArg);
	int zdejmijOperand();
	char wysunOperacje(int* iloscArg);
	int wysunOperand();
	
	int rodzajTop();
	int rodzajBottom();

	bool czyPusty();
	void wypisz();

private:
	KontenerONP* poczatek;
	KontenerONP* koniec;
};