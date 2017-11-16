#include "RandomAI.h"

RandomAI::RandomAI(Map& m) : AI(m) {
}

void RandomAI::clearMoves() {
	availableMoves.clear();
}

void RandomAI::collectMoves() {
	for (int j = 0; j < myMap.getSize(); j++)
		for (int i = 0; i < myMap.getSize(); i++)
			if (myMap.getState(i, j) == states::clear)
				availableMoves.push_back(std::pair<int, int>(i, j));
}

moveData RandomAI::move() {
	moveData md;

	clearMoves();
	collectMoves();

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> randomMove(0, availableMoves.size()-1);
	std::uniform_int_distribution<int> randomSegment(0, myMap.getMapSize()-1);

	int random = randomMove(gen);
	md.x = availableMoves[random].first;
	md.y = availableMoves[random].second;
	md.rotX = randomSegment(gen);
	md.rotY = randomSegment(gen);
	md.dir = ((md.x * md.rotX) % 2 == 0) ? rotates::left : rotates::right;

	return md;
}