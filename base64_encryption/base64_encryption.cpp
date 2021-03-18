#include <iostream>
#include <string>
#include "decoder.h"
#include "encoder.h"
#include <fstream>
#include <iostream>

int main()
{
	
	
	std::string input;
	//std::getline(std::cin, input);

	std::ifstream readfile("F:\\Projekte\\base64_encryption\\base64_encryption\\planetext.txt");
	std::string line;
	
	std::cout << "Press e for encoding, press d for decoding\n";
	while (std::getline(readfile, line)) {
		// Output the text from the file
		input.append(line);
		input.push_back('\n');
	}
	char decision;
	std::cin >> decision;

	if (decision == 'e' || decision == 'd')
	{
		auto out = decision == 'e' ? encode(input) : decode(input);
		std::cout << out;
	}
	return 0;
}

