#include "stdafx.h"

//Given a permutation which contains no repeated number, find its index in all the permutations of these numbers, 
//which are ordered in lexicographical order.The index begins at 1.
//
//Example
//Given[1, 2, 4], return 1.

namespace LintSolution1
{
    namespace PermutationIndex_Easy
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
			for (int i = len - 2; i >= 0; i--)
			{
				int smallerDigitCount = 0;
				for (int j = i + 1; j < len; j++) { if (A[j] < A[i]){ smallerDigitCount++; } }
				result += smallerDigitCount * factor;
				factor *= position;
				position++;
			}
			return result;
		}
     
        void Main()
        {
			print(permutationIndex(createVector({ 2, 4, 1 })));
			print(permutationIndex(createVector({ 2, 1, 4 })));
			print(permutationIndex(createVector({ 1, 2, 4 })));
        }
    }
}
   
    