#include "Game.h"

//Konstruktor silnika gry
//Awesome job by M. Kucharskov (https://kucharskov.pl)
Game::Game() : m(2, 3), lastState(states::clear), ai(nullptr) {
	clear();
}

//Dekonstruktor silnika gry
Game::~Game() {
	//Czyszczenie referencji
	if (ai != nullptr) delete ai;
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
	
	//Wykonywanie ruchu
	if (!(m.move(md.x, md.y, lastState) || m.rotate(md.rotX, md.rotY, md.dir))) return false;
	else 
	//Dla gracza AI
	if (ai != nullptr) {
		//Przestawienie ruchu na nastepnego gracza
		lastState = (lastState == states::white) ? states::black : states::white;

		//Wykonanie ruchu AI
		if (doAIMove) move(ai->move(), !doAIMove);
	}

	//Przestawienie ruchu na nastepnego gracza
	lastState = (lastState == states::white) ? states::black : states::white;
	
	//Zwracanie true tymczasowo
	return true;
}

//Funkcja zwracajaca wartosc danego pola
states Game::getState(int x, int y) {
	return m.getState(x, y);
}

//Funkcja sprawdzajaca czy nastapila wygrana
results Game::checkWin() {
	return m.checkWin();
}