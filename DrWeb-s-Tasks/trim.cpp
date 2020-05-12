#include "trim.h"
#include "test_runner.h"
#include <iostream>
#include <iomanip>

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
							"aaaaa",	//1
							" ",		//2
							"   ",		//3
							"  aaa",	//4
							"aa  aa",	//5
							"aaa   ",	//6
							""			//7
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
			ostringstream os;
			os << "Pair of strings #" << i+1
				<< " result: \""<<strings[i]<<"\""
				<< " expected: \""<<expected[i] << "\"";
			Assert(AreStringsEqual(strings[i], expected[i]), os.str());
		}		
	}
}

bool AreStringsEqual(const char* str1, const char* str2)
{
	bool result = true;
	while (*str1 != 0 && *str2 != 0)
	{
		if (*str1 != *str2)
		{
			result = false;
			break;
		}
		str1++;
		str2++;
	}
	if (*str1 !=0 || *str2 != 0)
	{
		result = false;
	}
	return result;
}
