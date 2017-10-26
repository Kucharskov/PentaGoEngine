#include "Segment.h"
#include "Map.h"

//Konstruktor segmentu (logicznego wycinka mapy)
Segment::Segment(Map& m, int x, int y) : myMap(m), xOffset(x), yOffset(y) {
}

//Funkcja czyszczaca caly segment
void Segment::clear() {
	int size = myMap.getSegmentSize();
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			move(i, j, states::clear);
}

//Funkcja ustawiajaca stan slotu w segmentze
void Segment::move(int x, int y, states slot) {
	myMap.move(x + xOffset, y + yOffset, slot);
}

//Funkcja obracajaca caly segment
void Segment::rotate(rotates dir) {
	//Deklarowanie tablicy tymczasowej
	std::vector<std::vector<states>> tempTab;

	int size = myMap.getSegmentSize();
	//Kopiowanie fragmentu mapy do segmentu
	tempTab.resize(size);
	for (int i = 0; i < size; ++i) {
		tempTab[i].resize(size);
		for (int j = 0; j < size; ++j)
			tempTab[i][j] = getState(i, j);
	}

	//Obrot segmentu juz na mapie
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (dir == rotates::left)
				move(i, j, tempTab[size - 1 - j][i]);
			else if (dir == rotates::right)
				move(i, j, tempTab[j][size - 1 - i]);
}

//Funkcja zwracajaca stan slotu z segmentu
states Segment::getState(int x, int y) {
	return myMap.getState(x + xOffset, y + yOffset);
}
