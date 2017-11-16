#include <iostream>
#include "Engine/Game.h"
#include "Engine/AI.h"
#include "AITest.h"

//Z pozdrowieniami dla nastoletnich, zeby nie pisac ciagle std::
using std::cin;
using std::cout;
using std::endl;

//Funkcja rysujaca mape
void showMap(Map &m) {
	//Rysowanie planszy dla podgladu
	for (int i = 0; i < m.getSize(); i++) {
		for (int j = 0; j < m.getSize(); j++) {
			switch ((int)m.getState(j, i)) {
			case 0:
				cout << "   ";
				break;
			case 1:
				cout << " @ ";
				break;
			case 2:
				cout << " O ";
				break;
			}
			if (j < m.getSize() - 1) cout << "|";
			else cout << endl;
		}
		if (i < m.getSize() - 1) for (int k = 0; k < m.getSize(); k++) cout << "--- ";
		cout << endl;
	}
}

//Funkcja wykonujaca ruch gracza
void userMove(Game &g) {
	char dir;
	moveData md;

	cout << "Podaj pole do zajecia [X, Y]: ";
	cin >> md.x >> md.y;

	cout << "Podaj segment do obrotu [X, Y]: ";
	cin >> md.rotX >> md.rotY;

	cout << "Podaj kierunek obrotu " << md.rotX << ", " << md.rotY << " [L, R]: ";
	cin >> dir;
	md.dir = (dir == 'L' || dir == 'l') ? rotates::left : rotates::right;
	md.dir = rotates::left;

	g.move(md);
}

//Testowy main
int main() {

	//Wybor trybu gry
	int gameMode;
	cout << "UWAGA: Pamietaj ze pola sa indeksowane od ZERA!\n";
	cout << "Wybierz tryb gry:\n [1] Human vs Human\n [2] AI vs Human\n [3] AI vs AI\nWybor: ";
	cin >> gameMode;

	//Inicjalizacja silnika gry
	Game g;
	if (gameMode == 2) g.setAI(new AITest(g.getMap()));
	else if (gameMode == 3) g.setAI(new AITest(g.getMap()), new AITest(g.getMap()));
	
	//Glowna petla gry
	if (gameMode != 3) {
		do {
			system("CLS");
			showMap(g.getMap());
			userMove(g);
		} while (g.checkWin() == results::nowin);
	}
	else g.runAI();

	//Podawanie wyniku
	system("CLS");
	showMap(g.getMap());
	if (g.checkWin() == results::draw) cout << "Remis!" << endl;
	else if (g.checkWin() == results::black) cout << "Wygraly czarne!" << endl;
	else if (g.checkWin() == results::white) cout << "Wygraly biale!" << endl;
	
	system("PAUSE");
	return 0;
}