#include "Game.h"

//Konstruktor silnika gry
//Awesome job by M. Kucharskov (https://kucharskov.pl)
Game::Game() : m(2, 3), lastState(states::clear), ai1(nullptr), ai2(nullptr) {
	clear();
}

//Dekonstruktor silnika gry
Game::~Game() {
	//Czyszczenie referencji
	if (ai1 != nullptr) delete ai1;
	if (ai2 != nullptr) delete ai2;
}

//Funkcja czyszczaca mape i resetujaca gre
void Game::clear() {
	m.clear();
	lastState = states::clear;
}

//Funkcja wykonywania ruchu
bool Game::move(moveData md, bool doAIMove) {
	//Obliczanie czyj ruch ma nastapic (zaczynaja zawsze biale)
	if (lastState == states::clear) lastState = states::white;
	else lastState = (lastState == states::white) ? states::black : states::white;

	//Wykonywanie ruchu
	if (m.move(md.x, md.y, lastState) == false) {
		lastState = (lastState == states::white) ? states::black : states::white;
		return false;
	}
	m.rotate(md.rotX, md.rotY, md.dir);

	//Sprawdzianie wyniku po ruchu
	if (checkWin() != results::nowin) return true;

	//Dla gracza AI
	if(!doAIMove) runAI();
	
	//Zwracanie true tymczasowo
	return true;
}

//Funkcja ustawiajaca sztuczne inteligencje
void Game::setAI(AI* a1, AI* a2) {
	if (a1 != nullptr) ai1 = a1;
	if (a2 != nullptr) ai2 = a2;
}

//Funkcja wykonujaca ruch AI
void Game::runAI() {
	if (ai1 != nullptr && ai2 == nullptr) move(ai1->move(), true);
	else {
		bool counter = true;
		do {
			if(true) move(ai1->move(), true);
			else move(ai2->move(), true);
			counter = !counter;
		} while (checkWin() == results::nowin);
	}
}

//Funkcja zwracajaca wartosc danego pola
states Game::getState(int x, int y) {
	return m.getState(x, y);
}

//Funkcja sprawdzajaca czy nastapila wygrana
results Game::checkWin() {
	return m.checkWin();
}