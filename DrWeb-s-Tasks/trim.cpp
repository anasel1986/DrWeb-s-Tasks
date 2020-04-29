#include "trim.h"
#include <cassert>
#include <iostream>

/**
	@brief The function trims spaces in the end or received string
	@param s string to be trimmed
*/
void TrimRight(char * s)
{
	if (s == nullptr || s[0] == 0)	//the string is empty
	{
		return;
	}

	char* curSpace = nullptr; //pointer to first space in last concequence of spaces
	bool isPrevSpace = false; //is the previous character a space

	while (*s != 0)
	{
		if (*s == ' ')
		{
			if (!isPrevSpace) 
			{
				curSpace = s;
				isPrevSpace = true;
			}
			
		}
		else
		{
			if (isPrevSpace)
			{
				curSpace = nullptr;
				isPrevSpace = false;
			}
		}
		s++;
	}
	if (curSpace != nullptr)
	{
		*curSpace = 0;
	}
}


void TestTrimRight()
{
	{
		char strings[][10] = {
							"aaaaa",
							" ",
							"   ",
							"  aaa",
							"aa  aa",
							"aaa   ",
							""
							};
		const char expected[][10] = {
							"aaaaa",
							"",
							"",
							"  aaa",
							"aa  aa",
							"aaa",
							""
							};
		for (int i=0; i<7 ;i++)
		{
			TrimRight(strings[i]);
			std::cerr << "Test #" << i+1 << " OK\n";
		}		
	}
}