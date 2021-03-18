#pragma once

const std::string lookup_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

float getSize(char* text)
{
	float size = 0;
	while (*(text++) != '\0')
	{
		size++;
	}
	return size;
}


std::vector<std::string> convert_to_three_byte_wise(std::string in)
{
	std::vector<std::string> three_byte_wise;
	uint8_t counter = 0;
	std::string three_byte = "";
	for (auto letter : in)
	{
		three_byte.push_back(letter);
		counter++;
		if (counter % 3 == 0)
		{
			three_byte_wise.push_back(three_byte);
			three_byte = "";
			counter = 0;
		}
	}
	while (three_byte_wise.back().length() < 3)
	{
		three_byte_wise.back().push_back('\0');
	}
	return three_byte_wise;
}
