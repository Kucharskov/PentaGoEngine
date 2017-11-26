#include "Game.h"

/*
Konstruktor silnika gry
Awesome job by M. Kucharskov (https://kucharskov.pl)
*/
Game::Game() : m(2, 3), lastState(states::clear), mode(modes::HuH), ai1(nullptr), ai2(nullptr) {
	clear();
}

//Dekonstruktor silnika gry 
Game::~Game() {
	//Czyszczenie referencji
	clearAI();
}

//Funkcja czyszczaca mape i resetujaca gre 
void Game::clear() {
	m.clear();
	lastState = states::clear;
}

//Funkcja wykonywania ruchu 
bool Game::move(moveData md, bool AImove) {
    //Obliczanie czyj ruch ma nastapic (zaczynaja zawsze biale)
    lastState = getNextState();

	//Wykonywanie ruchu z zabezpieczeniem
	if (!m.move(md.x, md.y, lastState)) return false;
	if (!m.rotate(md.rotX, md.rotY, md.dir)) {
		//Cofniecie ruchu przy bledzie obrotu
		m.move(md.x, md.y, states::clear, true);
		return false;
    }

	//Sprawdzianie wyniku po ruchu
	if (checkWin() != results::nowin) return true;

	//Dla gracza AI
	if (mode == modes::HuA && AImove == false)
		runAI();

	//Zwracanie true
	return true;
}

//Funkcja czyszczaca referencje do AI 
void Game::clearAI() {
	if (ai1 != nullptr) delete ai1;
	if (ai2 != nullptr) delete ai2;
}

//Funkcja ustawiajaca sztuczne inteligencje 
void Game::setAI(AI* a1, AI* a2) {
	//Tryb HuH
	if (a1 == nullptr && a2 == nullptr) mode = modes::HuH;
	//Tryb HuA
	else if (a1 != nullptr && a2 == nullptr) {
		mode = modes::HuA;
		ai1 = a1;
	}
	//Tryb AuA
	else if (a1 != nullptr && a2 != nullptr) {
		mode = modes::AuA;
		ai1 = a1;
		ai2 = a2;
	}
}

//Funkcja wykonujaca ruch AI 
void Game::runAI() {
	//Ruch AI dla trybu HuA
	if (mode == modes::HuA) {
		move(ai1->move(), true);
	}
	//Rozegranie meczu dla trybu AuA
	else if(mode == modes::AuA) {
		//Zmienna do przelaczania miedzy AI
		bool ticker = true;
		do {
			//Wykonanie ruchu AI1
			if(ticker) move(ai1->move(), true);
			//Wykonanie ruchu AI2
			else move(ai2->move(), true);
			//Przelaczenie miedzy AI
			ticker = !ticker;
		} while (checkWin() == results::nowin);
	}
}

//Funkcja zwracajaca ruch nastepnej osoby
states Game::getNextState() const {
    return (lastState == states::white) ? states::black : states::white;
}

//Funkcja zwracajaca wartosc danego pola 
states Game::getState(int x, int y) {
	return m.getState(x, y);
}

//Funkcja sprawdzajaca czy nastapila wygrana 
results Game::checkWin() {
	return m.checkWin();
}
