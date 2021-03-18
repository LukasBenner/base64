#pragma once

const std::string lookup_table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";





std::vector<std::string> convert_to_byte_wise(std::string in, uint8_t length)
{
	std::vector<std::string> three_byte_wise;
	uint8_t counter = 0;
	std::string three_byte;
	for (auto letter : in)
	{
		three_byte.push_back(letter);
		counter++;
		if (counter % length == 0)
		{
			three_byte_wise.push_back(three_byte);
			three_byte = "";
			counter = 0;
		}
	}
	if (counter != 0)
	{
		//left for loop without adding the uncompleted string
		three_byte_wise.push_back(three_byte);
	}
	while (three_byte_wise.back().length() < length)
	{
		three_byte_wise.back().push_back('\0');
	}
	return three_byte_wise;
}
