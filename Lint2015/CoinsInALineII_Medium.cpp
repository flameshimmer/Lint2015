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
			if (len < 3) { return true; }

			vector<int> M(len, 0);
			M[len - 1] = values[len - 1];
			M[len - 2] = values[len - 1] + values[len - 2];
			int total = M[len - 2];
			for (int i = len - 3; i >= 0; i--)
			{
				total += values[i];
				int val1 = values[i] + min((i + 2 < len ? M[i + 2] : 0), (i + 3 < len ? M[i + 3] : 0));
				int val2 = values[i] + values[i + 1] + min((i + 3 < len ? M[i + 3] : 0), (i + 4 < len ? M[i + 4] : 0));
				M[i] = max(val1, val2);
			}
			return M[0] > total / 2;
		}


		void Main()
		{
			vector<int> input;
			input = createVector({ 1, 2, 2 });
			print(firstWillWin(input));

			input = createVector({ 1, 2, 4 });
			print(firstWillWin(input));

			input = createVector({ 100, 200, 400, 300, 400, 800, 500, 600, 1200 });
			print(firstWillWin(input));
		}
	}
}

