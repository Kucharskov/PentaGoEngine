#include "AITest.h"

AITest::AITest(Map& m) : AI(m) {
}

moveData AITest::move() {
	moveData md;
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> randomState(0, myMap.getSize()-1);
	std::uniform_int_distribution<int> randomSegment(0, myMap.getMapSize()-1);

	do {
		md.x = randomState(gen);
		md.y = randomState(gen);
		md.rotX = randomSegment(gen);
		md.rotY = randomSegment(gen);
		md.dir = ((md.x * md.rotX) % 2 == 0) ? rotates::left : rotates::right;
	} while (myMap.getState(md.x, md.y) != states::clear);

	return md;
}