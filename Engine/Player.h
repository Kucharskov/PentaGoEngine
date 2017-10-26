#pragma once
#include "MainTypes.h"
#include "Map.h"

class Player {
protected:
	/* Pola */
	states myState;
	Map* myMap;

public:
	/* Konstruktory */
	Player(Map *, states);

	/* Metody */
	void setState(states);

	/* Metody wirtualne */
	virtual void move() = 0;
};
