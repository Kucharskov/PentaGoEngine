#pragma once
#include <random>
#include <unordered_map>
#include "Engine/AI.h"

class RandomAI : public AI
{
private:
	std::vector<std::pair<int, int>> availableMoves;

public:
	RandomAI::RandomAI(Map&);
	void clearMoves();
	void collectMoves();
	moveData move();
};

