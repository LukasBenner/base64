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