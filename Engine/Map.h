#pragma once
#include <vector>
#include "MainTypes.h"

/* Forward declaration */
class Segment;

class Map {
protected:
	/* Pola */
	int mapSize;
	int segmentSize;
	int moveCounter;
	std::vector<std::vector<states>> mainTab;
	std::vector<std::vector<Segment*>> segments;

public:
	/* Konstruktory */
	Map(int, int);

	/* Metody */
	void clear();
	bool move(int, int, states, bool = false);
	bool rotate(int, int, rotates);
	results checkWin();

	/* Metody uprzywilejowane */
	int getSize() const { return mapSize * segmentSize; };
	int getMapSize() const { return mapSize; };
	int getSegmentSize() const { return segmentSize; };
	states getState(int x, int y) const { return mainTab[x][y]; };
};
