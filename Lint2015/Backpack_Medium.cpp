#include "stdafx.h"

//Given n items with size Ai, an integer m denotes the size of a backpack.How full you can fill this backpack ?
//
//Example
//If we have 4 items with size[2, 3, 5, 7], the backpack size is 11, we can select[2, 3, 5], so that the max 
//size we can fill this backpack is 10. If the backpack size is 12. we can select[2, 3, 7] so that we can fulfill the backpack.
//
//You function should return the max size we can fill in the given backpack.
//
//Note
//You can not divide any item into small pieces.
//
//Challenge
//O(n x m) time and O(m) memory.
//
//O(n x m) memory is also acceptable if you do not know how to optimize memory.

namespace LintSolution1
{
    namespace Backpack_Medium
    {     
		/**
		* @param m: An integer m denotes the size of a backpack
		* @param A: Given n items with size A[i]
		* @return: The maximum size
		*/
		int backPack(int C, vector<int> A) {
			int len = A.size();
			if (len == 0) { return 0; }

			vector<int>M(C+1, 0);

			for (int i = 1; i < len + 1; i++)
			{
				for (int c = C; c >= 0; c--)
				{
					if (c - A[i - 1] >= 0)
					{
						M[c] = max(M[c], M[c - A[i - 1]] + A[i - 1]);
					}
				}
			}
			return M[C];
		}
     
        void Main()
        {
			// Error: notice the bag has i elements, then the last element's index is i-1
			// Error: when compacting the 2D array into 1D, note that the scan has to happen from right to left in order to not run over the previous value
			print(backPack(10, createVector({ 3, 4, 5, 8 })));
			print(backPack(11, createVector({ 2, 3, 5, 7 })));
			print(backPack(12, createVector({ 2, 3, 5, 7 })));
			print(backPack(90, createVector({ 12, 3, 7, 4, 5, 13, 2, 8, 4, 7, 6, 5, 7 })));
        }
    }
}
   
    