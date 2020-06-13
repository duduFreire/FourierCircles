#include "myComplex.h"

namespace complex {
	myComplex exp(float imag) {
		return { cos(imag), sin(imag) };
	}

	float abs(myComplex& num) {
		return sqrtf(num.real*num.real + num.imag*num.imag);
	}
}