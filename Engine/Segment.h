#pragma once
#include "MainTypes.h"

//Forward declaration
class Map;

class Segment {
protected:
	/* Pola */
	Map& myMap;
	int xOffset;
	int yOffset;

public:
	/* Konstruktory */
	Segment(Map&, int, int);

	/* Metody */
	void clear();
	void setState(int, int, states);
	void rotate(rotates);
	states getState(int, int);
};

