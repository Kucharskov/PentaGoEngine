#include "Map.h"
#include "Segment.h"

//Konstruktor mapy
Map::Map(int mSize, int sSize) : mapSize(mSize), segmentSize(sSize) {
	//Deklarowanie tablicy pol
	mainTab.resize(mapSize*segmentSize);
	for (auto& row : mainTab)
		row.resize(mapSize*segmentSize);

	//Deklarowanie tablicy segmentow
	segments.resize(mapSize);
	for (int i = 0; i < mapSize; i++) {
		segments[i].resize(mapSize);
		for (int j = 0; j < mapSize; j++)
			segments[i][j] = new Segment(this, j * segmentSize, i * segmentSize);
	}
}

//Funkcja czyszczaca cala mape
void Map::clear() {
	for (auto& row : segments)
		for (auto& item : row)
			item->clear();
}

//Funkcja ustawiajaca stan slotu na mapie
void Map::move(int x, int y, states slot) {
	mainTab[x][y] = slot;
}

//Funkcja obracajaca segment na mapie
void Map::rotate(int x, int y, rotates dir)
{
	if (x < mapSize && y < mapSize)
		segments[y][x]->rotate(dir);
}

//Funkcja sprawdzajaca czy nastapila wygrana
results Map::checkWin()
{
	//Deklarowanie pomocniczych zmiennych do zliczania wygranych
	int black = 0;
	int white = 0;

	int size = segmentSize*mapSize;
	//Szukanie wygranego w poziomie
	for (int i = 0; i < size; i++)
		for (int j = 2; j < size - 2; j++)
		{
			if (mainTab[i][j] == states::clear) continue;
			if (mainTab[i][j - 2] == mainTab[i][j - 1] &&
				mainTab[i][j - 1] == mainTab[i][j] &&
				mainTab[i][j] == mainTab[i][j + 1] &&
				mainTab[i][j + 1] == mainTab[i][j + 2])
				if (mainTab[i][j] == states::black) black++;
				else white++;
		}

	//Szukanie wygranego w pionie
	for (int i = 2; i < size - 2; i++)
		for (int j = 0; j < size; j++)
		{
			if (mainTab[i][j] == states::clear) continue;
			if (mainTab[i - 2][j] == mainTab[i - 1][j] &&
				mainTab[i - 1][j] == mainTab[i][j] &&
				mainTab[i][j] == mainTab[i + 1][j] &&
				mainTab[i + 1][j] == mainTab[i + 2][j])
				if (mainTab[i][j] == states::black) black++;
				else white++;
		}

	//Szukanie wygranego po skosie dla obu przekatnych
	for (int i = 2; i < size - 2; i++)
		for (int j = 2; j < size - 2; j++)
		{
			if (mainTab[i][j] == states::clear) continue;
			if (mainTab[i - 2][j - 2] == mainTab[i - 1][j - 1] &&
				mainTab[i - 1][j - 1] == mainTab[i][j] &&
				mainTab[i][j] == mainTab[i + 1][j + 1] &&
				mainTab[i + 1][j + 1] == mainTab[i + 2][j + 2])
				if (mainTab[i][j] == states::black) black++;
				else white++;;

			if (mainTab[i][j] != states::clear &&
				mainTab[i - 2][j + 2] == mainTab[i - 1][j + 1] &&
				mainTab[i - 1][j + 1] == mainTab[i][j] &&
				mainTab[i][j] == mainTab[i + 1][j - 1] &&
				mainTab[i + 1][j - 1] == mainTab[i + 2][j - 2])
				if (mainTab[i][j] == states::black) black++;
				else white++;
		}

	//Zwracanie wyniku
	if (black > 0 || white > 0)
		if (black > 0 && white == 0)
			return results::black;
		else if (black == 0 && white > 0)
			return results::white;
		else
			return results::draw;
	else
		return results::nowin;
}