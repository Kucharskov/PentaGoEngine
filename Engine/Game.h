#pragma once
#include "MainTypes.h"
#include "Map.h"
#include "AI.h"

class Game
{
protected:
	/* Pola */
	Map m;
	states lastState;
	AI* ai;

public:
	/* Konstruktory */
	Game();

	/* Dekonstruktory */
	~Game();

	/* Metody */
	void clear();
	bool move(moveData, bool = false);
	states getState(int, int);
	results checkWin();
	void setAI(AI* a) { ai = a; };

	/* Metody uprzywilejowane */
	int getSize() const { return m.getSize(); };
	int getMapSize() const { return m.getMapSize(); };
	int getSegmentSize() const { return m.getSegmentSize(); };
	Map& getMap() { return m; }

	/* Klasy zaprzyjaznione */
	friend class MainWindow;
};

