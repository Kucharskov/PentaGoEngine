#pragma once
#include "MainTypes.h"
#include "Player.h"
#include "Map.h"

class AITest : public Player {
public:
	/* Konstruktory */
	AITest(Map *, states);
	
	/* Metody wirtualne */
	void move();
};
