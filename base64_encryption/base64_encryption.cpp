#include <iostream>
#include <string>
#include "decoder.h"
#include "encoder.h"


int main()
{
	std::string input;
	std::getline(std::cin, input);
	char* in = &input[0];

	std::cout << "Press e for encoding, press d for decoding\n";
	char decision;
	std::cin >> decision;

	if (decision == 'e' || decision == 'd')
	{
		auto out = decision == 'e' ? encode(in) : decode(in);
		std::cout << out;
	}
	return 0;
}

