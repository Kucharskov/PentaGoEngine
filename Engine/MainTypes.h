#pragma once

/*
Enumerator opisujacy dozwolone stany:
 clear - brak stanu
 black - stan czarny
 white - stan bialy
 err - pole nieistniejace
*/
enum class states {
	clear,
	black,
	white,
	err
};

/*
Enumerator opisujacy dozwolone wyniki:
 nowin - brak wyniku
 black - stan czarny
 white - stan bialy
 draw - remis
*/
enum class results {
	nowin,
	black,
	white,
	draw
};

/*
Enumerator opisujacy dozwolone obroty:
 none - brak obrotu
 left - lewo
 right - prawo
*/
enum class rotates {
	none,
	left,
	right
};

/*
Enumerator opisujacy tryby pracy silnika:
 HuH - Human vs Human
 HuA - Human vs AI
 AuA - AI vs AI
*/
enum class modes {
	HuH,
	HuA,
	AuA
};

//Paczka danych odpowiadajacych za ruch
struct moveData {
	int x = -1;
	int y = -1;
	int rotX = -1;
	int rotY = -1;
	rotates dir = rotates::none;

	moveData() : x(-1), y(-1), rotX(-1), rotY(-1), dir(rotates::none) {};
	moveData(int _x, int _y, int _rotX, int _rotY, rotates _dir) : x(_x), y(_y), rotX(_rotX), rotY(_rotY), dir(_dir) {};
};