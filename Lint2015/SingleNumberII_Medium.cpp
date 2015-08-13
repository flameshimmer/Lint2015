#include "stdafx.h"

//Given 3 * n + 1 numbers, every numbers occurs triple times except one, find it.
//
//Example
//Given[1, 1, 2, 3, 3, 3, 2, 2, 4, 1] return 4
//
//Challenge
//One - pass, constant extra space.

namespace LintSolution1
{

    namespace SingleNumberII_Medium
    {
		/**
		* @param A : An integer array
		* @return : An integer
		*/
		int singleNumberII(vector<int> &A) {
			int ones = 0;
			int twos = 0;
			int threes = 0;

			for (int v : A)
			{
				twos |= ones & v;
				ones ^= v;
				threes = ones & twos;
				ones &= ~threes;
				twos &= ~threes;
			}
			return ones;
		}
    
        void Main()
        {
			print(singleNumberII(createVector({ 1, 1, 2, 3, 3, 3, 2, 2, 4, 1 })));
        }
    }
}
   
    