#include "StakONP.h"

using namespace std;

StakONP::StakONP() {
	this->poczatek = new KontenerONP;
	this->koniec = poczatek;
	this->poczatek->zawartosc = nullptr;
}



/*
------DODANIA----------
*/

void StakONP::dodaj(int operand) {
	if (poczatek->zawartosc == nullptr) {
		poczatek->zawartosc = new ZawartoscONP;
		poczatek->zawartosc->operand = operand;
		poczatek->zawartosc->operacja = BRAK_OPERACJI;
	}
	else {
		KontenerONP* tmpointer = koniec;

		koniec->nastepny = new KontenerONP;
		koniec = koniec->nastepny;

		koniec->zawartosc = new ZawartoscONP;
		koniec->zawartosc->operand = operand;
		koniec->zawartosc->operacja = BRAK_OPERACJI;

		koniec->poprzedni = tmpointer;
	}
}

void StakONP::dodaj(char operacja, int iloscArg = 2) {
	if (poczatek->zawartosc == nullptr) {
		poczatek->zawartosc = new ZawartoscONP;
		poczatek->zawartosc->operacja = operacja;
		poczatek->zawartosc->iloscArgumentow = iloscArg;
	}
	else {
		KontenerONP* tmpointer = koniec;

		koniec->nastepny = new KontenerONP;
		koniec = koniec->nastepny;
		
		koniec->zawartosc = new ZawartoscONP;
		koniec->zawartosc->operacja = operacja;
		koniec->zawartosc->iloscArgumentow = iloscArg;

		koniec->poprzedni = tmpointer;
	}
}

void StakONP::nalozOperacje(char operacja, StakInt* ilosciArg) {
	if (operacja == 'm' || operacja == 'M') this->dodaj(operacja, ilosciArg->zdejmij());
	else if (operacja == 'I') this->dodaj(operacja, 3);
	else if (operacja == 'N') this->dodaj(operacja, 1);
	else this->dodaj(operacja, 2);
}

/*
------ZDEJMOWANIA--------
*/

int StakONP::zdejmijOperand() {
	int wynik = koniec->zawartosc->operand;
	
	
	if (poczatek == koniec) {
		delete koniec->zawartosc;
		koniec->zawartosc = nullptr;
	}
	else {
		KontenerONP* tmpointer = koniec;
		koniec = tmpointer->poprzedni;
		delete tmpointer->zawartosc;
		delete tmpointer;
	}
	
	return wynik;
}

char StakONP::zdejmijOperacje(int* iloscArg) {
	char wynik = koniec->zawartosc->operacja;
	*iloscArg = koniec->zawartosc->iloscArgumentow;

	if (poczatek == koniec) {
		delete koniec->zawartosc;
		koniec->zawartosc = nullptr;
	}
	else {
		KontenerONP* tmpointer = koniec;
		koniec = koniec->poprzedni;

		delete tmpointer->zawartosc;
		delete tmpointer;
	}
	
	return wynik;
}


/*
----WYSUWANIA--------
*/

int StakONP::wysunOperand() {
	int wynik = poczatek->zawartosc->operand;


	if (poczatek == koniec) {
		delete koniec->zawartosc;
		koniec->zawartosc = nullptr;
	}
	else {
		KontenerONP* tmpointer = poczatek;
		poczatek = tmpointer->nastepny;

		delete tmpointer->zawartosc;
		delete tmpointer;
	}

	return wynik;
}

char StakONP::wysunOperacje(int* iloscArg) {
	char wynik = poczatek->zawartosc->operacja;
	*iloscArg = poczatek->zawartosc->iloscArgumentow;

	if (poczatek == koniec) {
		delete koniec->zawartosc;
		koniec->zawartosc = nullptr;
	}
	else {
		KontenerONP* tmpointer = poczatek;
		poczatek = tmpointer->nastepny;

		delete tmpointer->zawartosc;
		delete tmpointer;
	}

	return wynik;
}

/*
-----METODY INNE-------
*/

bool StakONP::czyPusty() {
	if (poczatek->zawartosc == nullptr) return true;
	return false;
}

int StakONP::rodzajTop() {
	if (!(this->czyPusty())) {
		if (this->koniec->zawartosc->operacja == BRAK_OPERACJI) return RODZAJ_OPERAND;
		return RODZAJ_OPERACJA;
	}
	return RODZAJ_PUSTY;
}

int StakONP::rodzajBottom() {
	if (!(this->czyPusty())) {
		if (this->poczatek->zawartosc->operacja == BRAK_OPERACJI) return RODZAJ_OPERAND;
		return RODZAJ_OPERACJA;
	}
	return RODZAJ_PUSTY;
}

void StakONP::wypisz() {

	KontenerONP* tmpointer = poczatek;

	while (tmpointer != koniec) {
		if (tmpointer->zawartosc->operacja == BRAK_OPERACJI) cout << tmpointer->zawartosc->operand<<" ";
		else {
			if (tmpointer->zawartosc->operacja == 'm') cout << "MIN" << tmpointer->zawartosc->iloscArgumentow<<" ";
			else if (tmpointer->zawartosc->operacja == 'M') cout << "MAX" << tmpointer->zawartosc->iloscArgumentow << " ";
			else if (tmpointer->zawartosc->operacja == 'I') cout << "IF" << " ";
			else cout << tmpointer->zawartosc->operacja<<" ";
		}
		tmpointer = tmpointer->nastepny;
	}

	if (poczatek != koniec) {
		if (tmpointer->zawartosc->operacja == BRAK_OPERACJI) cout << tmpointer->zawartosc->operand << " ";
		else {
			if (tmpointer->zawartosc->operacja == 'm') cout << "MIN" << tmpointer->zawartosc->iloscArgumentow << " ";
			else if (tmpointer->zawartosc->operacja == 'M') cout << "MAX" << tmpointer->zawartosc->iloscArgumentow << " ";
			else if (tmpointer->zawartosc->operacja == 'I') cout << "IF" << " ";
			else cout << tmpointer->zawartosc->operacja << " ";
		}
	}
	//cout << endl;
}


StakONP::~StakONP() {
	int tmp;
	int* tmpointer = &tmp;

	while (!(this->czyPusty())) {
		if (this->rodzajTop() == RODZAJ_OPERACJA) this->zdejmijOperacje(tmpointer);
	}
}