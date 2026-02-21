#include <iostream>
#include "StakONP.h"
#include "funkcjeWczytywania.h"
#include "funkcjeObliczania.h"
#include "funkcjePrzetwarzania.h"


using namespace std;

int main() {

	StakONP* stakONP = new StakONP;

	char tmp = fgetc(stdin);
	int ilosc = wczytajOperand(tmp);
	
	for (int i = 0;i < ilosc;i++) {
		przetworzWersONP(stakONP);

		stakONP->wypisz();
		cout << endl;

		obliczZeStaku(stakONP);
		cout << endl << endl;
	}
	

	/*
	StakONP* stakONP = new StakONP;

	przetworzWersONP(stakONP);

	stakONP->wypisz();
	cout << endl;

	int iloscArg = 0;

	while (!(stakONP->czyPusty())) {
		if (stakONP->rodzajBottom() == RODZAJ_OPERACJA) cout << stakONP->wysunOperacje(&iloscArg) << iloscArg<<endl;
		if (stakONP->rodzajBottom() == RODZAJ_OPERAND) cout << stakONP->wysunOperand()<<endl;
	}
	*/
}
