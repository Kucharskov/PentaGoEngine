#include "AITest.h"

//Konstruktor AI
AITest::AITest(Map * m, states s = states::clear) : Player(m, s) {
}

//Implementacja trywialnego ruchu
void AITest::move() {
	int size = myMap->getMapSize() * myMap->getSegmentSize();
	for (int i = 0; i < size; i++) {
		if (myMap->getState(i, 0) == states::clear) {
			myMap->move(i, 0, myState);
			break;
		}
	}
	myMap->rotate(1, 1, rotates::left);
}