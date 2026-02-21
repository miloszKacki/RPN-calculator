#include "funkcjeWczytywania.h"
#include <iostream>


char wczytajOperacje(char ramka) {

	if (ramka == 'M')
	{
		ramka = fgetc(stdin);
		ramka = fgetc(stdin);
		if (ramka == 'X') return 'M';
		else return 'm';
	}
	else if (ramka == 'I') {
		ramka = fgetc(stdin);
		return 'I';
	}
	else {
		return ramka;
	}
}

int wczytajOperand(char ramka) {

	int wynik = 0;

	while (ramka <= '9' &&ramka >= '0') {

		wynik *= 10;
		wynik += ramka - '0';
		ramka = fgetc(stdin);

	}
	return wynik;

}

int wczytajToken(int* intowy, char* charowy) {
	char ramka = ' ';
	int wynikInt;
	char wynikChar;
	while (ramka == ' ' || ramka == '\n') {
		ramka = fgetc(stdin);
	}

	if (ramka == '.') return WCZYTAJ_TOKEN_KONIEC;
	else if (ramka == '(') {
		wynikChar = wczytajOperacje(ramka);
		*charowy = wynikChar;
		return WCZYTAJ_TOKEN_NAWIAS_OTW;
	}
	else if (ramka == ')') {
		wynikChar = wczytajOperacje(ramka);
		*charowy = wynikChar;
		return WCZYTAJ_TOKEN_NAWIAS_ZAM;
	}
	else if (ramka == ',') {
		return WCZYTAJ_TOKEN_PRZECINEK;
	}
	else if (ramka <= '9' && ramka >= '0') {
		wynikInt = wczytajOperand(ramka);
		*intowy = wynikInt;
		return WCZYTAJ_TOKEN_INT;
	}
	else {
		wynikChar = wczytajOperacje(ramka);
		*charowy = wynikChar;
		if (wynikChar == 'm' || wynikChar == 'M') return WCZYTAJ_TOKEN_OPERACJA_ARGUMENTOWA;
		return WCZYTAJ_TOKEN_CHAR;
	}
}