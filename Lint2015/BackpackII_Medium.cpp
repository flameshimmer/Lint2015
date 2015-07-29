#include "stdafx.h"

//Given n items with size Ai and value Vi, and a backpack with size m.What's the maximum value can you put into the backpack?
//
//Example
//Given 4 items with size[2, 3, 5, 7] and value[1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.
//
//Note
//You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.
//
//Challenge
//O(n x m) memory is acceptable, can you do it in O(m) memory ?


namespace LintSolution1
{
    namespace BackpackII_Medium
    {

		/**
		* @param m: An integer m denotes the size of a backpack
		* @param A & V: Given n items with size A[i] and value V[i]
		* @return: The maximum value
		*/
		int backPackII(int C, vector<int> A, vector<int> V) {
			int len = A.size();
			if (len == 0) { return 0; }

			vector<int>M(C + 1, 0);

			for (int i = 1; i < len + 1; i++)
			{
				for (int c = C; c >= 0; c--)
				{
					if (c - A[i - 1] >= 0)
					{
						M[c] = max(M[c], M[c - A[i - 1]] + V[i - 1]);
					}
				}
			}
			return M[C];
		}
     
        void Main()
        {
         
        }
    }
}
   
    