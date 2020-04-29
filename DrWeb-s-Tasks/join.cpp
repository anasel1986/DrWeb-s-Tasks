/**
	@file
	@brief Join two vectors
	@author Selivanov Anatoliy
	@date 21 апреля 2020
*/

#include "join.h"


/**
	@brief Join two sorted vectors
	@param from is the first original vector that should not be amended
	@param to is the second oroginal vector, the vector should comprise all elements of the both vectors

	The function receives two sorted vectors of int values. Function does not amend vector "from".
	The vector "to" will comprise all elements of the two original vectors.
	The elements of the resulting vector "to" are sorted. 
*/
void join(vector<int>& from, vector<int>& to)
{
	/*	
		if the vector "to" hasn't enough space, 
		a new vector with size equal to sum of the two vector's sizes is created, 
		all elements of the vectors are put into the new vector, than the vector "to" is swaped to the new vector  
	*/
	if (to.capacity() < from.size() + to.size())  
	{
		vector <int> tmp(from.size() + to.size());
		joinVectors(from, to, tmp);
		to.swap(tmp);		
	}
	/*
		the vector "to" has enough space and we can just put all elements of the second vector into it in appropriate order
	*/
	else
	{
		joinVectors(from, to, to);
	}
}



/**
	@brief This is an accessory function for join()
	@param v1, v2 are the original vectors
	@param to is resulting vector

	This is an accessory function for join(), it receives two sorted vectors v1 and v2 and puts all theirs elements into the vector "to" in sorted order.
*/
void joinVectors(vector<int>& v1, vector<int>& v2, vector<int>& to)
{
	int s1 = v1.size();
	int s2 = v2.size();
	int sTo = s1 + s2;
	to.resize(sTo);	//vector "to" wittingly has enough space
	s1--;
	s2--;
	sTo--;
	for (; sTo >= 0; sTo--)	//vectors are reviewed in reverse order and the largest element is placed at the end of vector "to"
	{
		if (s1 < 0)	//if there is no elements in vector v1
		{
			to[sTo] = v2[s2--];
			continue;
		}
		if (s2 < 0)	//if there is no elements in vector v2
		{
			to[sTo] = v1[s1--];
			continue;
		}
		to[sTo] = (v1[s1] > v2[s2]) ? v1[s1--] : v2[s2--];	
	}
}