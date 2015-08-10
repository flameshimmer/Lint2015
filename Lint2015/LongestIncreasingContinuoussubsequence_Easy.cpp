#include "stdafx.h"


//Give you an integer array(index from 0 to n - 1, where n is the size of this array)，
//find the longest increasing continuous subsequence in this array.
//(The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)
//
//
//Example
//For[5, 4, 2, 1, 3], the LICS is[5, 4, 2, 1], return 4.
//
//For[5, 1, 2, 3, 4], the LICS is[1, 2, 3, 4], return 4.
//
//Note
//O(n) time and O(1) extra space.

namespace LintSolution1
{
    namespace LongestIncreasingContinuoussubsequence_Easy
    {
		/**
		* @param A an array of Integer
		* @return  an integer
		*/
		int longestIncreasingContinuousSubsequence(vector<int>& A) {
			int len = A.size();
			if (len < 2) { return len; }

			int maxIncCount = 0;
			int maxDecCount = 0;
			int incCount = 0;
			int decCount = 0;
			for (int i = 1; i < len; i++)
			{
				if (A[i] > A[i - 1]) { incCount++; decCount = 0; }
				else if (A[i] < A[i - 1]) { decCount++; incCount = 0; }

				maxIncCount = max(maxIncCount, incCount);
				maxDecCount = max(maxDecCount, decCount);
			}
			return max(maxIncCount, maxDecCount) + 1;
		}
     
        void Main()
        {
         
        }
    }
}
   
    