#include "stdafx.h"

//There are n coins with different value in a line.Two players take turns to take one or two coins 
//from left side until there are no more coins left.The player who take the coins with the most value wins.
//
//Could you please decide the first player will win or lose ?
//
//
//Example
//Given values array A = [1, 2, 2], return true.
//
//Given A = [1, 2, 4], return false.

namespace LintSolution1
{
    namespace CoinsInALineII_Medium
    {
		/**
		* @param values: a vector of integers
		* @return: a boolean which equals to true if the first player will win
		*/
		bool firstWillWin(vector<int> &values) {
			int len = values.size();
			if (len == 0) { return false; }
			reverse(values.begin(), values.end());

			int M[4];
			M[0] = 0;
			M[1] = values[0];
			M[2] = values[0] + values[1];
			M[3] = M[2];

			int total = 0;
			for (int i = 1; i < len+1; i++)
			{
				total += values[i-1];
				if (i >= 4)
				{
					int maxV1 = max(M[(i - 2) % 4], M[(i - 3) % 4]) + values[i - 1];
					int maxV2 = max(M[(i - 3) % 4], M[(i - 4) % 4]) + values[i - 1] + values[i-2];
					M[i % 4] = max(maxV1, maxV2);
				}
			}
			return M[len % 4] > total / 2;
		}
     
        void Main()
        {
			vector<int> input = createVector({1, 2, 4});
			print(firstWillWin(input));
        }
    }
}
   
    