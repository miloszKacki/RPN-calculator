#include "funkcjeObliczania.h"


void obliczZeStaku(StakONP* stakONP) {

	StakInt* stakInt = new StakInt;
	
	int wynik,iloscArg, tmp;
	int* toIloscArg = &iloscArg;

	bool errCaller = false;
	bool* toErrCaller = &errCaller;

	char operacja;

	while (!(stakONP->czyPusty())) {
		if (stakONP->rodzajBottom() == RODZAJ_OPERAND) {
			stakInt->dodaj(stakONP->wysunOperand());
		}
		else {
			operacja = stakONP->wysunOperacje(toIloscArg);

			int* argy = (int*)malloc(iloscArg * sizeof(int));
			
			if (operacja == 'm') cout << "MIN" <<iloscArg<< " ";
			else if (operacja == 'M') cout << "MAX"<<iloscArg << " ";
			else if (operacja == 'I') cout << "IF" << " ";
			else cout << operacja << " ";

			stakInt->wypisz();
			cout << endl;

			for (int i = 0;i < iloscArg;i++) {
				argy[i] = stakInt->zdejmij();
			}

			stakInt->dodaj(obliczOperacje(operacja, argy, iloscArg, toErrCaller));
			free(argy);
			if (errCaller){
				cout << "ERROR";
				while (!(stakONP->czyPusty())) {
					if (stakONP->rodzajBottom() == RODZAJ_OPERAND) stakONP->wysunOperand();
					else stakONP->wysunOperacje(toIloscArg);
				}
				return;
			}
		}
		
	}
	
	wynik = stakInt->zdejmij();

	cout << wynik;
	return;
}

int obliczOperacje(char operacja, int* argy, int iloscArg,bool* errCallPointer) {
	if (operacja == '*') {
		return argy[0] * argy[1];
	}
	else if (operacja == '/')
	{
		if (argy[0] != 0) return argy[1] / argy[0];
		else *errCallPointer = true;
	}
	else if (operacja == '+') {
		return argy[1] + argy[0];
	}
	else if (operacja == '-') {
		return argy[1] - argy[0];
	}
	else if (operacja == '+') {
		return argy[1] * argy[0];
	}
	else if (operacja == 'N') {
		return argy[0] * (-1);
	}
	else if (operacja == 'm') {
		int min = argy[0];
		for (int i = 0;i < iloscArg;i++) {
			if (argy[i] < min) min = argy[i];
		}
		return min;
	}
	else if (operacja == 'M') {
		int max = argy[0];
		for (int i = 0;i < iloscArg;i++) {
			if (argy[i] > max) max = argy[i];
		}
		return max;
	}
	else if (operacja == 'I') {
		//cout << endl << " ! " << argy[0] << " " << argy[1] << " " << argy[2] << " ! " << endl;
		if (argy[2] > 0) return argy[1];
		return argy[0];
	}
	else {
		*errCallPointer = true;
		return 0;
	}
	return 0;
}