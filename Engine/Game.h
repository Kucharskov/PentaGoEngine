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
	modes mode;
	AI* ai1;
	AI* ai2;

public:
	/* Konstruktory */
	Game();

	/* Dekonstruktory */
	~Game();

	/* Metody */
	void clear();
	bool move(moveData, bool = false);
	void clearAI();
	void setAI(AI* = nullptr, AI* = nullptr);
	void runAI();
	states getState(int, int);
	results checkWin();

	/* Metody uprzywilejowane */
	int getSize() const { return m.getSize(); };
	int getMapSize() const { return m.getMapSize(); };
	int getSegmentSize() const { return m.getSegmentSize(); };
    states getNextState() const;
	Map& getMap() { return m; }

	/* Klasy zaprzyjaznione */
	friend class MainWindow;
};

