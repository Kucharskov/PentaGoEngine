#include <iostream>
#include "Engine/Game.h"

void main()
//Testowy main
{
	//Instancja silnika gry
	Game g;

	//Wykonanie ruchow dajacych wygrana dla bialych
	g.move(0, 1);
	g.move(1, 1);
	g.move(0, 2);
	g.move(1, 2);
	g.move(0, 3);
	g.move(1, 3);
	g.move(0, 4);
	g.move(1, 4);
	g.move(0, 5);
	g.move(1, 5);

	//Sprawdzanie wyniku (3 to states::white)
	std::cout << "Oczekiwany wynik to 3\n";
	std::cout << "Wynik: " << (int)g.checkWin() << std::endl;

	system("PAUSE");
}