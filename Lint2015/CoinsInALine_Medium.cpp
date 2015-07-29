#include "stdafx.h"

//There are n coins in a line.Two players take turns to take one or two coins from right side
//until there are no more coins left.The player who take the last coin wins.
//
//Could you please decide the first play will win or lose ?
//
//Example
//n = 1, return true.
//
//n = 2, return true.
//
//n = 3, return false.
//
//n = 4, return true.
//
//n = 5, return true.
//
//Challenge
//O(n) time and O(1) memory

namespace LintSolution1
{
    namespace CoinsInALine_Medium
    {
     
		/**
		* @param n: an integer
		* @return: a boolean which equals to true if the first player will win
		*/
		bool firstWillWin(int n) {
			bool M[4];
			M[0] = false;
			M[1] = true;
			M[2] = true;
			M[3] = false;
			for (int i = 4; i < n + 1; i++)
			{
				M[i % 4] = (M[(i - 2) % 4] || M[(i - 1) % 4]) && M[(i - 3) % 4];
			}
			return M[n % 4];
		}
     
     
        void Main()
        {
			// Error: the winning criteria is no matter whether the opponent pick 1 or 2 coins, the first player have to win (not just have the possibility to wiin)
			for (int i = 1; i < 6; i++)
			{
				print(firstWillWin(i));
			}
			print(firstWillWin(9999));
        }
    }
}
   
    