#include <iostream>
#include "Engine/Game.h"
#include "Engine/AI.h"
#include "RandomAI.h"

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
	
	//Tryb gry 1 i 2
	if (gameMode == 1 || gameMode == 2) {
		if (gameMode == 2) g.setAI(new RandomAI(g.getMap()));
		do {
			system("CLS");
			showMap(g.getMap());
			userMove(g);
		} while (g.checkWin() == results::nowin);

		//Podawanie wyniku
		system("CLS");
		showMap(g.getMap());
		if (g.checkWin() == results::draw) cout << "Remis!" << endl;
		else if (g.checkWin() == results::black) cout << "Wygraly czarne!" << endl;
		else if (g.checkWin() == results::white) cout << "Wygraly biale!" << endl;
	}

	//Tryb gry 3
	else if (gameMode == 3) {
		g.setAI(new RandomAI(g.getMap()), new RandomAI(g.getMap()));
		int black = 0;
		int white = 0;
		int draw = 0;

		unsigned int games = 0;
		cout << "Podaj ilosc gier do rozegrania przez AI: ";
		cin >> games;

		for (int i = 0; i < games; i++) {
			g.runAI();

			system("CLS");
			showMap(g.getMap());
			if (g.checkWin() == results::draw) draw++;
			else if (g.checkWin() == results::black) black++;
			else if (g.checkWin() == results::white) white++;

			g.clear();
		}

		cout << "Wyniki dla rozegranych " << games << " gier:" << endl;
		cout << "Biale: " << white << endl;
		cout << "Czarne: " << black << endl;
		cout << "Remis: " << draw << endl;
	}
	
	system("PAUSE");
	return 0;
}