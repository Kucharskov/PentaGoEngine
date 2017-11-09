#include "AITest.h"

AITest::AITest(Map& m) : AI(m) {
}

moveData AITest::move() {
	moveData md;

	for (int j = 0; j < myMap.getSize(); j++)
		for (int i = 0; i < myMap.getSize(); i++)
			if (myMap.getState(i, j) == states::clear) {
				md.x = i;
				md.y = j;

				md.rotX = 1;
				md.rotY = 1;

				md.dir = rotates::left;
				return md;
			}
}