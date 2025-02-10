#include "Random.h"
#include <stdlib.h>

float GetRand(float ang) {
	return (-ang + ang * 2.f * static_cast<int>(rand() % 10000) / 10000.f);
}
