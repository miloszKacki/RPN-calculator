#include "funkcjePrzetwarzania.h"

void przetworzWersONP(StakONP* stakONP) {
	StakChar* stak = new StakChar;
	StakInt* ilosciArg = new StakInt;


	int kierunek = 1, tmpI;
	char tmpC;

	int* Operand = &tmpI;
	char* Operacja = &tmpC;

	//cout << endl;

	while (kierunek != WCZYTAJ_TOKEN_KONIEC) {
		kierunek = wczytajToken(Operand, Operacja);

		//cout <<"| "<< kierunek << " " << *Operand << " " << *Operacja << " |"<<endl;

		if (kierunek == WCZYTAJ_TOKEN_INT) {
			//cout << *Operand << " ";
			stakONP->dodaj(*Operand);

		}
		else if (kierunek == WCZYTAJ_TOKEN_NAWIAS_OTW) {
			stak->dodaj('(');
		}
		else if (kierunek == WCZYTAJ_TOKEN_NAWIAS_ZAM) {
			while (!(stak->czyPusty()))
			{
				char op = stak->zdejmijOperacje();
				if (op == '(') break;
				else stakONP->nalozOperacje(op, ilosciArg);
			}
		}
		else if (kierunek == WCZYTAJ_TOKEN_PRZECINEK) {
			while (!(stak->czyPusty()))
			{
				char op = stak->zdejmijOperacje();
				if (op == '(') {
					stak->dodaj('(');
					break;
				}
				else stakONP->nalozOperacje(op, ilosciArg);
			}
			ilosciArg->zwieksz();
		}
		else if (kierunek == WCZYTAJ_TOKEN_KONIEC) break;
		else {
			if (kierunek == WCZYTAJ_TOKEN_OPERACJA_ARGUMENTOWA) ilosciArg->dodaj(1);
			if (*Operacja == 'I' && !(ilosciArg->czyPusty())) ilosciArg->zmniejsz(2);
			int p = priorytet(*Operacja);
			while (!(stak->czyPusty())) {
				char top = stak->zdejmijOperacje();
				if (top == '(' || p > priorytet(top)) {
					stak->dodaj(top);
					break;
				}
				stakONP->nalozOperacje(top, ilosciArg);
				/*if (top == 'm' || top == 'M') stakONP->dodaj(top, ilosciArg->zdejmij());
				else stakONP->dodaj(top, 2);*/
				//cout << top<<" ";
			}
			stak->dodaj(*Operacja);
		}
	}

	while (!(stak->czyPusty())) {
		char op = stak->zdejmijOperacje();
		stakONP->nalozOperacje(op, ilosciArg);
		/*if (op == 'm' || op == 'M') stakONP->dodaj(op, ilosciArg->zdejmij());
		else stakONP->dodaj(op, 2);*/
		//cout << stak->zdejmijOperacje() << " ";
	}

	delete stak;
	delete ilosciArg;
}

int priorytet(char dzialanie) {
	if (dzialanie == '-' || dzialanie == '+') return 1;
	else if (dzialanie == '*' || dzialanie == '/') return 2;
	else if (dzialanie == 'N') return 3;
	else return 4;
}
