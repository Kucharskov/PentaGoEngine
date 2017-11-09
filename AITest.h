#pragma once
#include "Engine/AI.h"

class AITest : public AI
{
public:
	AITest::AITest(Map&);
	moveData move();
};

