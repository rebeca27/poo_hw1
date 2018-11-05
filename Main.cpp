#include <iostream>
#include "BigInteger.h"

int main() {
	BigInteger b = BigInteger(12345, 10);
	std::cout << b;
	return 0;
}