#include "Easing.h"
#include "Define.h"
#include <math.h>

float EaseOutElastic(float x) {
	 const float c4 = (2.f * kPi) / 3.f;
	 if (x == 0.f) {
		 return 0;
	 } else if (x == 1.f) {
		 return 1;
	 } else {
		 return powf(2.f, -10.f * x) * sinf((x * 10.f - 0.75f) * c4) + 1.f;
	 }
}