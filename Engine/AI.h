#pragma once
#include "MainTypes.h"
#include "Map.h"

class AI {
protected:
	/* Pola */
	Map& myMap;

public:
	/* Konstruktory */
	AI(Map&);
	
	/* Metody wirtualne */
	virtual moveData move() = 0;
};