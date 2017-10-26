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

//Funkcja zwracajaca wartosc danego pola
states Game::getState(int x, int y) {
	return m.getState(x, y);
}

//Funkcja wykonywania ruchu
void Game::move(int x, int y) {
	//Obliczanie czyj ruch ma nastapic (zaczynaja zawsze biale)
	if (lastState == states::clear) lastState = states::white;

	//Sprawdzanie czy slot jest dostepny
	if (m.getState(x, y) == states::clear)
	{
		//Wykonanie ruchu
		m.move(x, y, lastState);
		//Przestawienie ruchu na nastepnego gracza
		lastState = (lastState == states::white) ? states::black : states::white;
	}
}

//Funkcja obracajaca w lewo segment na mapie
void Game::rotateLeft(int x, int y) {
	m.rotate(x, y, rotates::left);
}

//Funkcja obracajaca w prawo segment na mapie
void Game::rotateRight(int x, int y) {
	m.rotate(x, y, rotates::right);
}

//Funkcja sprawdzajaca czy nastapila wygrana
results Game::checkWin() {
	return m.checkWin();
}