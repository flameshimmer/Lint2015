#include "stdafx.h"

//Given n distinct positive integers, integer k(k <= n) and a number target.
//
//Find k numbers where sum is target.Calculate how many solutions there are ?
//
//Example
//Given[1, 2, 3, 4], k = 2, target = 5.
//
//There are 2 solutions : [1, 4] and[2, 3].
//
//Return 2.

namespace LintSolution1
{
    namespace kSum_Hard
    {   
		/**
		* @param A: an integer array.
		* @param k: a positive integer (k <= length(A))
		* @param target: a integer
		* @return an integer
		*/
		int kSum(vector<int> A, int k, int target) {
			int len = A.size();

			// since i can only be calculated from i-1, we only store 2 rows (0 and 1), and use i%2 and (i-1)%2 do the calculation
			vector<vector<vector<int>>> M(2, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));

			for (int i = 0; i < len + 1; i++)
			{
				for (int j = 0; j < k + 1; j++)
				{
					for (int t = 0; t < target + 1; t++)
					{
						if (j == 0 && t == 0) { M[i%2][j][t] = 1; }
						else if (i != 0 && j != 0 && t != 0)
						{
							M[i%2][j][t] = M[(i - 1)%2][j][t];
							if (t - A[i - 1] >= 0)
							{
								M[i%2][j][t] += M[(i - 1)%2][j - 1][t - A[i - 1]];
							}
						}
					}
				}
			}
			return M[len%2][k][target];
		}


		namespace ThreeDimentionalDP{
			int kSum(vector<int> A, int k, int target) {
				int len = A.size();

				vector<vector<vector<int>>> M(len + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));

				for (int i = 0; i < len + 1; i++)
				{
					for (int j = 0; j < k + 1; j++)
					{
						for (int t = 0; t < target + 1; t++)
						{
							if (j == 0 && t == 0) { M[i][j][t] = 1; }
							else if (i != 0 && j != 0 && t != 0)
							{
								M[i][j][t] = M[i - 1][j][t];
								if (t - A[i - 1] >= 0)
								{
									M[i][j][t] += M[i - 1][j - 1][t - A[i - 1]];
								}
							}
						}
					}
				}
				return M[len][k][target];
			}
		}
		namespace TimeLimitExceeded
		{
			void kSumImpl(vector<int>& A, int level, int start, int len, int target, int& count)
			{
				if (level == 2)
				{
					int end = len - 1;
					while (start < end)
					{
						int sum = A[start] + A[end];
						if (sum == target) { count++; start++; }
						else if (sum < target) { start++; }
						else { end--; }
					}
					return;
				}

				for (int i = start; i < len - (level - 1); i++)
				{
					kSumImpl(A, level - 1, i + 1, len, target - A[i], count);
				}
			}
			/**
			* @param A: an integer array.
			* @param k: a positive integer (k <= length(A))
			* @param target: a integer
			* @return an integer
			*/
			int kSum(vector<int> A, int k, int target) {
				sort(A.begin(), A.end());
				int count = 0;
				int len = A.size();

				if (k == 0) { return 0; }
				if (k == 1)
				{
					for (int v : A) { if (v == target) { count++; } }
					return count;
				}

				kSumImpl(A, k, 0, len, target, count);
				return count;
			}
		}
        void Main()
        {
			print(kSum(createVector({ 1, 3, 4, 5, 8, 10, 11, 12, 14, 17, 20, 22, 24, 25, 28, 30, 31, 34, 35, 37, 38, 40, 42, 44, 45, 48, 51, 54, 56, 59, 60, 61, 63, 66 }), 24, 842));
			print(kSum(createVector({ 1, 4, 7, 10, 12, 15, 16, 18, 21, 23, 24, 25, 26, 29 }), 5, 113));
			print(kSum(createVector({ 1, 4, 5, 6, 8 }), 1, 4));
			print(kSum(createVector({ 1, 2, 3, 4 }), 2, 5));
        }
    }
}
   
    