#include "stdafx.h"

//Given 2 * n + 2 numbers, every numbers occurs twice except two, find them.
//
//Example
//Given[1, 2, 2, 3, 4, 4, 5, 3] return 1 and 5
//
//Challenge
//O(n) time, O(1) extra space.


namespace LintSolution1
{
    namespace SingleNumberIII_Medium
    {
     
		/**
		* @param A : An integer array
		* @return : Two integers
		*/
		vector<int> singleNumberIII(vector<int> &A) {
			int diff = 0;
			for (int v : A) { diff ^= v; }

			// mask will have the right most bit of the diff
			int mask = diff & ~(diff - 1);

			int x = 0;
			for (int v : A)
			{
				if (mask & v)
				{
					x ^= v;
				}
			}
			vector<int> result(2);
			result[0] = x;
			result[1] = x ^ diff;

			return result;
		}
     
        void Main()
        {
			print(singleNumberIII(createVector({ 1, 2, 2, 3, 4, 4, 5, 3 })));
        }
    }
}
   
    