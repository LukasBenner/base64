#pragma once
#include <vector>
#include <sstream>

#include "helperFunctions.h"




void decode_4_byte(std::string in, std::string* out)
{
	out->push_back(lookup_table.find(in[0]) << 2 | (lookup_table.find(in[1]) & 0b00110000) >> 4);
	out->push_back((lookup_table.find(in[1]) & 0b00001111) << 4 | (in[2] == '=' ? 0x00 : (lookup_table.find(in[2]) & 0b00111100) >> 2));
	out->push_back(in[2] == '=' ? 0x00 : ((lookup_table.find(in[2]) & 0b00000011) << 6 | (in[3] == '=' ? 0x00 : lookup_table.find(in[3]) & 0b00111111)));
}


std::string decode(std::string in)
{
	std::string out;
	auto four_byte_wise = convert_to_byte_wise(in, 4);
	for (auto input_string : four_byte_wise)
	{
		decode_4_byte(input_string, &out);
	}
	return out;
}
