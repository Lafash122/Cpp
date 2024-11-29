#include <iostream>
#include "bitarray.h"

int main() {
	int bits;
	unsigned long long value3 = 255, value2;
	std::cin >> bits >> value2 /*>> value3*/;

	BitArray array1;
	BitArray array2(bits, value2);
	BitArray array3(bits, value3);

	std::cout << "1: " << array1.empty() << "\t2: " << array2.empty() << "\t3: " << array3.empty() << std::endl;
	std::cout << "1: " << array1.size() << "\t2: " << array2.size() << "\t3: " << array3.size() << std::endl << std::endl;

	std::cout << "array2: " << array2.bit_seq() << std::endl;

	for (int i = 0; i < array2.size(); i++) {
		array2[i] = true;
	}

	std::cout << "array2: " << array2.bit_seq() << std::endl;


	return 0;
}