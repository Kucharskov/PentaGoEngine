#pragma once
#include "MainTypes.h"
#include "Map.h"
#include "Player.h"

class Game
{
protected:
	/* Pola */
	Map m;
	states lastState;

public:
	/* Konstruktory */
	Game();

	/* Metody */
	void clear();
	bool move(Player&, int, int);
	bool rotate(int, int, rotates);
	states getState(int, int);
	results checkWin();

	/* Metody uprzywilejowane */
	int getSize() const { return m.getMapSize() * m.getSegmentSize(); };
	int getMapSize() const { return m.getMapSize(); };
	int getSegmentSize() const { return m.getSegmentSize(); };
	Map& getMap() { return m; }

	/* Klasy zaprzyjaznione */
	friend class MainWindow;

};

