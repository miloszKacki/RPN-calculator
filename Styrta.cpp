#include "Styrta.h"

Styrta::Styrta() {
	poczatek = new Kontener;
	koniec = poczatek;
	poczatek->zawartosc = new Zawartosc;
	poczatek->zawartosc->stan = ZAWARTOSC_STAN_PUSTY;
}

bool Styrta::czyPusty() {
	if (poczatek->zawartosc->stan == ZAWARTOSC_STAN_PUSTY) return true;
	return false;
}

//Dodanie operacji
void Styrta::dodaj(char kladzione) {
	if (this->czyPusty()) {
		poczatek->zawartosc->operacja = kladzione;
		poczatek->zawartosc->stan = ZAWARTOSC_STAN_OPERACJA;
	}
	else {
		
		koniec->nastepny = new Kontener;
		Kontener* tmpointer = koniec->nastepny;

		tmpointer->zawartosc = new Zawartosc;
		tmpointer->poprzedni = koniec;
		tmpointer->zawartosc->operacja = kladzione;
		tmpointer->zawartosc->stan = ZAWARTOSC_STAN_OPERACJA;


		koniec = tmpointer;
	}
	
}

//Dodanie operandu
void Styrta::dodaj(int kladzione) {
	if (this->czyPusty()) {
		poczatek->zawartosc->operand = kladzione;
		poczatek->zawartosc->stan = ZAWARTOSC_STAN_OPERAND;
	}
	else {

		koniec->nastepny = new Kontener;
		Kontener* tmpointer = koniec->nastepny;

		tmpointer->zawartosc = new Zawartosc;
		tmpointer->poprzedni = koniec;
		tmpointer->zawartosc->operand = kladzione;
		tmpointer->zawartosc->stan = ZAWARTOSC_STAN_OPERAND;


		koniec = tmpointer;
	}
}

char Styrta::sprawdzStanWierzchu() {
	return koniec->zawartosc->stan;
}


char Styrta::zdejmijOperacje() {
	char wynik;
	wynik = koniec->zawartosc->operacja;

	Kontener* tmpointer = koniec;
	koniec = tmpointer->poprzedni;
	free(tmpointer->zawartosc);
	free(tmpointer);

	return wynik;
}

int Styrta::zdejmijOperand() {
	int wynik;
	wynik = koniec->zawartosc->operand;

	Kontener* tmpointer = koniec;
	koniec = tmpointer->poprzedni;
	free(tmpointer->zawartosc);
	free(tmpointer);

	return wynik;
}


Styrta::~Styrta() {
	while (!(this->czyPusty())) {
		if (this->sprawdzStanWierzchu() == ZAWARTOSC_STAN_OPERACJA) zdejmijOperacje();
		else zdejmijOperand();
	}
}