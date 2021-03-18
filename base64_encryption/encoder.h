#pragma once
#include <vector>
#include "helperFunctions.h"
#include <sstream>



void encode_3_byte(std::string in, std::string* out)
{
	out->push_back(lookup_table[(in[0] & 0xFC) >> 2]);
	out->push_back(lookup_table[((in[0] & 0x3) << 4) | ((in[1] & 0xF0) >> 4)]);
	out->push_back(in[1] ? lookup_table[((in[1] & 0xF) << 2) | ((in[2] & 0xC0) >> 6)] : '=');
	out->push_back(in[2] ? lookup_table[in[2] & 0x3F] : '=');
}

std::string encode(std::string in)
{
	std::string out;
	auto three_byte_wise = convert_to_byte_wise(in, 3);
	for (auto input_string : three_byte_wise)
	{
		encode_3_byte(input_string, &out);
	}
	return out;
}

