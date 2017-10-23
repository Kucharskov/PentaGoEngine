#pragma once
#include "MainTypes.h"

//Forward declaration
class Map;

class Segment {
protected:
	/* Pola */
	Map* myMap;
	int xOffset;
	int yOffset;

public:
	Segment(Map*, int, int);

	/* Metody */
	void clear();
	states getState(int, int);
	void setState(int, int, states);
	void rotate(rotates);
};

