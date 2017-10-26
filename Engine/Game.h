#pragma once
#include "MainTypes.h"
#include "Map.h"

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
	void move(int, int);
	void rotate(int, int, rotates);
	states getState(int, int);
	results checkWin();

	/* Metody uprzywilejowane */
	int getSize() const { return m.getMapSize() * m.getSegmentSize(); };
	int getMapSize() const { return m.getMapSize(); };
	int getSegmentSize() const { return m.getSegmentSize(); };

	/* Klasy zaprzyjaznione */
	friend class MainWindow;
};

