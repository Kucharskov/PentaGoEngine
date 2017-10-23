#pragma once

//Enumerator opisujacy dozwolone stany:
//clear - brak stanu
//black - stan czarny
//white - stan bialy
//err - pole nieistniejace
enum class states {
	clear,
	black,
	white,
	err
};

//Enumerator opisujacy dozwolone wyniki:
//nowin - brak wyniku
//black - stan czarny
//white - stan bialy
//draw - remis
enum class results {
	nowin,
	black,
	white,
	draw
};

//Enumerator opisuj¹cy dozwolone obroty:
enum class rotates {
	left,
	right
};