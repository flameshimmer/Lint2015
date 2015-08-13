#include "stdafx.h"

//Given 2 * n + 1 numbers, every numbers occurs twice except one, find it.
//
//Example
//Given[1, 2, 2, 1, 3, 4, 3], return 4
//
//Challenge
//One - pass, constant extra space.

namespace LintSolution1
{
    namespace SingleNumber_Easy
    {
     
		int singleNumber(vector<int> &A) {
			int result = 0;
			for (int v : A)
			{
				result ^= v;
			}
			return result;
		}
     
     
        void Main()
        {
         
        }
    }
}
   
    