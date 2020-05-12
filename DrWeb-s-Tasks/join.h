#pragma once
/**
	@file
	@brief Join two vectors
	@author Selivanov Anatoliy
	@date 21 апреля 2020	
*/

#include <vector>

using std::vector;

/**
	@brief Join two sorted vectors
	@param from is the first original vector that should not be amended
	@param to is the second oroginal vector, the vector should comprise all elements of the both vectors

	The function receives two sorted vectors of int values.Function does not amend vector "from".
	The vector "to" will comprise all elements of the two original vectors.
	The elements of the resulting vector "to" are sorted.
*/
void join(vector<int>& from, vector<int>& to);

/**
	@brief This is an accessory function for join()
	@param v1, v2 are the original vectors
	@param to is resulting vector

	This is an accessory function for join(), it receives two sorted vectors v1 and v2 and puts all theirs elements into the vector "to" in sorted order.
*/
void joinVectors(vector<int>& v1, vector<int>& v2, vector<int>& to);

void TestJoin();