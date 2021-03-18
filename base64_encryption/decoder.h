#pragma once
#include <vector>
#include <sstream>

#include "helperFunctions.h"




void decode_4_byte(char* in, std::vector<char>* out)
{
	out->push_back(lookup_table.find(in[0]) << 2 | (lookup_table.find(in[1]) & 0b00110000) >> 4);
	out->push_back((lookup_table.find(in[1]) & 0b00001111) << 4 | (in[2] == '=' ? 0x00 : (lookup_table.find(in[2]) & 0b00111100) >> 2));
	out->push_back(in[2] == '=' ? 0x00 : ((lookup_table.find(in[2]) & 0b00000011) << 6 | (in[3] == '=' ? 0x00 : lookup_table.find(in[3]) & 0b00111111)));
}


std::string decode(char* in)
{
	std::vector<char>out;
	float size = getSize(in);
	int len = 0;
	while (len < size)
	{
		decode_4_byte(in, &out);
		in += 4;
		len += 4;
	}
	std::stringstream ss;
	for (auto letter : out)
	{
		ss << letter;
	}
	return ss.str();
}
