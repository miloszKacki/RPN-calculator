#include "StakInt.h"

StakInt::StakInt() {
	this->poczatek = new KontenerINT;
	this->koniec = poczatek;
	this->poczatek->zawartosc = NULL;
	pustosc = true;
}

bool StakInt::czyPusty() {
	return pustosc;
}


void StakInt::dodaj(int kladzone) {
	//cout << "k"<<kladzone<<"|";
	
	if (this->czyPusty()) {
		poczatek->zawartosc = kladzone;
		pustosc = false;
	}
	else {
		KontenerINT* tmpointer = new KontenerINT;
		tmpointer->poprzedni = koniec;
		tmpointer->zawartosc = kladzone;
		koniec->nastepny = tmpointer;
		koniec = tmpointer;
	}
}
/*
void StakInt::wypisz() {
	KontenerINT* obecny = poczatek;
	if (!(this->czyPusty())) {
		while (true) {
			cout << obecny->zawartosc << " ";
			if (obecny == koniec) break;
			obecny = obecny->nastepny;
		}

	}
}
*/

void StakInt::wypisz() {
	KontenerINT* obecny = koniec;
	if (!(this->czyPusty())) {
		while (true) {
			cout << obecny->zawartosc << " ";
			if (obecny == poczatek) break;
			obecny = obecny->poprzedni;
		}

	}
}

int StakInt::zdejmij() {
	int wynik = koniec->zawartosc;
	if (koniec == poczatek) {
		pustosc = true;
		koniec->zawartosc = NULL;
		return wynik;
	}
	else {
		KontenerINT* tmpointer = koniec;
		koniec = tmpointer->poprzedni;
		delete tmpointer;
		return wynik;
	}


}

void StakInt::zwieksz() {
	koniec->zawartosc++;
}

void StakInt::zmniejsz(int ilosc) {
	koniec->zawartosc -= ilosc;
}

StakInt::~StakInt() {
	while (!(this->czyPusty())) {
		this->zdejmij();
	}
}