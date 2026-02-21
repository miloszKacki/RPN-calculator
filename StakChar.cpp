#include "StakChar.h"

StakChar::StakChar() {
	this->poczatek = new KontenerChar;
	this->koniec = poczatek;
	this->poczatek->zawartosc = NULL;
}

bool StakChar::czyPusty() {
	if (poczatek->zawartosc == NULL) return true;
	return false;
}


void StakChar::dodaj(char kladzone) {
	//cout << "k"<<kladzone<<"|";
	if (this->czyPusty()) poczatek->zawartosc = kladzone;
	else {
		KontenerChar* tmpointer = new KontenerChar;
		tmpointer->poprzedni = koniec;
		tmpointer->zawartosc = kladzone;
		koniec->nastepny = tmpointer;
		koniec = tmpointer;
	}
}

void StakChar::wypisz() {
	cout <<endl<< "| ";
	KontenerChar* obecny = poczatek;
	if (!(this->czyPusty())) {
		while (true) {
			cout << obecny->zawartosc<<" ";
			if (obecny == koniec) break;
			obecny = obecny->nastepny;
		}
		
	}
	cout << " |"<<endl;
}

char StakChar::zdejmijOperacje() {
	char wynik = koniec->zawartosc;
	if (koniec == poczatek) {
		koniec->zawartosc = NULL;
		return wynik;
	}
	else {
		KontenerChar* tmpointer = koniec;
		koniec = tmpointer->poprzedni;
		delete tmpointer;
		return wynik;
	}
	
	
}

StakChar::~StakChar() {
	while (!(this->czyPusty())) {
		this->zdejmijOperacje();
	}
}