#include "stdafx.h"

//Given a permutation which may contain repeated numbers, find its index in all the permutations of these numbers, 
//which are ordered in lexicographical order.The index begins at 1.
//
//Example
//Given the permutation[1, 4, 2, 2], return 3.


namespace LintSolution1
{
	namespace PermutationIndexII_Medium
	{

		/**
		* @param A an integer array
		* @return a long integer
		*/
		long long permutationIndex(vector<int>& A) {
			int len = A.size();
			long long result = 1;
			int factor = 1;
			int position = 2;

			unordered_map<int, int> numToCount;
			numToCount[A.back()]++;
			for (int i = len - 2; i >= 0; i--)
			{
				unordered_map<int, int> successorToCount;
				for (int j = i + 1; j < len; j++)
				{
					if (A[j] < A[i]) { successorToCount[A[j]]++; }
				}

				for (auto kvp : successorToCount)
				{
					result += factor * kvp.second / numToCount[A[i]];
				}
				
				factor = factor * position / numToCount[A[i]];
				position++;
			}
			return result;
		}

		void Main()
		{
			print(permutationIndex(createVector({ 1, 4, 2, 2 })));
		}
	}
}

