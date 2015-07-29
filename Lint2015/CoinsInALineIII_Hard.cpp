#include "stdafx.h"

//There are n coins in a line.Two players take turns to take a coin from one of the ends of the line until 
//there are no more coins left.The player with the larger amount of money wins.
//
//Could you please decide the first player will win or lose ?
//
//Example
//Given array A = [3, 2, 2], return true.
//
//Given array A = [1, 2, 4], return true.
//
//Given array A = [1, 20, 4], return false.
//
//Challenge
//Follow Up Question :
//
//If n is even.Is there any hacky algorithm that can decide whether first player will win or lose in O(1) memory and O(n) time ?

namespace LintSolution1
{
    namespace CoinsInALineIII_Hard
    {
     
		bool firstWillWin(vector<int> &values) {
			int len = values.size();
			if (len == 0) { return false; }
			if (len == 1) { return true; }

			vector<vector<int>>M(len, vector<int>(len, 0));
			int total = 0;
			for (int i = len - 1; i >= 0; i--)
			{
				total += values[i];
				for (int j = i; j < len; j++)
				{
					int val1 = min((i+2 < len ? M[i+2][j] : 0), ((i+1 < len && j-1 >=0) ? M[i+1][j-1] : 0)) + values[i];
					int val2 = min((i+1 < len && j-1 >= 0) ? M[i+1][j-1] : 0, (j-2 >= 0 ? M[i][j-2] : 0)) + values[j];
					M[i][j] = max(val1, val2);
				}
			}
			return M[0][len - 1] > total / 2;
		}
     
     
        void Main()
        {
         
        }
    }
}
   
    