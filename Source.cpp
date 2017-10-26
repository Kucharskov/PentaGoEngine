#include <iostream>
#include "Engine/Game.h"

//Testowy main
int main()
{
	//Instancja silnika gry
	Game g;
	
	//Wykonanie ruchow dajacych remis
	g.move(0, 0);
	g.move(1, 0);
	g.move(0, 1);
	g.move(1, 1);
	g.move(0, 2);
	g.move(1, 2);
	g.move(0, 3);
	g.move(1, 3);
	g.move(0, 4);
	g.move(1, 4);

	//Rysowanie planszy dla podgladu
	for (int i = 0; i < g.getSize(); i++) {
		for (int j = 0; j < g.getSize(); j++) {
			switch ((int)g.getState(j, i)) {
			case 0:
				std::cout << "   ";
				break;
			case 1:
				std::cout << " B ";
				break;
			case 2:
				std::cout << " W ";
				break;
			}
			if (j < g.getSize()-1) std::cout << "|";
			else std::cout << std::endl;
		}
		if (i < g.getSize() - 1) for (int k = 0; k < g.getSize(); k++) std::cout << "--- ";
		std::cout << std::endl;
	}
	

	//Sprawdzanie wyniku (3 to states::draw)
	std::cout << "Oczekiwany wynik to 3\n";
	std::cout << "Wynik: " << (int)g.checkWin() << std::endl;

	system("PAUSE");
	return 0;
}