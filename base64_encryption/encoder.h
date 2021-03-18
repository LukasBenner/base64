#pragma once
#include <vector>
#include "helperFunctions.h"
#include <sstream>




void encode_3_byte(char* in, std::vector<char>* out)
{
	out->push_back(lookup_table[(in[0] & 0xFC) >> 2]);
	out->push_back(lookup_table[((in[0] & 0x3) << 4) | ((in[1] & 0xF0) >> 4)]);
	out->push_back(in[1] ? lookup_table[((in[1] & 0xF) << 2) | ((in[2] & 0xC0) >> 6)] : '=');
	out->push_back(in[2] ? lookup_table[in[2] & 0x3F] : '=');
}


std::string encode(char* in)
{
	std::vector<char> out;
	float size = getSize(in);
	int len = 0;
	while (len < size)
	{
		encode_3_byte(in, &out);
		in += 3;
		len += 3;
	}
	std::stringstream ss;
	for(auto letter : out)
	{
		ss << letter;
	}
	return ss.str();
}

