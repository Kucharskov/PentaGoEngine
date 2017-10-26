#include "Game.h"

//Konstruktor silnika gry
//Awesome job by M. Kucharskov (https://kucharskov.pl)
Game::Game() : m(2, 3), lastState(states::clear) {
	clear();
}

//Funkcja czyszczaca mape i resetujaca gre
void Game::clear() {
	m.clear();
	lastState = states::clear;
}

//Funkcja wykonywania ruchu
bool Game::move(Player & p, int x, int y) {
	//Zabezpieczenie przed blednym Playerem
	if (p.getState() == states::clear) return false;

	//Obliczanie czyj ruch ma nastapic (zaczynaja zawsze biale)
	if (lastState == states::clear) lastState = states::white;

	//Zabezpieczenie przed wykonaniem podwojnego ruchu przez tego samego gracza
	if (p.getState() != lastState) return false;

	//Przestawienie ruchu na nastepnego gracza
	lastState = (lastState == states::white) ? states::black : states::white;

	//Wykonywanie ruchu i zwracanie powodzenia
	return m.move(x, y, p.getState());
}

//Funkcja obracajaca w lewo segment na mapie
bool Game::rotate(int x, int y, rotates dir) {
	return m.rotate(x, y, dir);
}

//Funkcja zwracajaca wartosc danego pola
states Game::getState(int x, int y) {
	return m.getState(x, y);
}

//Funkcja sprawdzajaca czy nastapila wygrana
results Game::checkWin() {
	return m.checkWin();
}