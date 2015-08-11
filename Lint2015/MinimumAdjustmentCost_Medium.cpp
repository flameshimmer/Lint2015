#include "stdafx.h"

//Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.
//
//If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of | A[i] - B[i] |
//
//Example
//Given[1, 4, 2, 3] and target = 1, one of the solutions is[2, 3, 2, 3], the adjustment cost is 2 and it's minimal.
//
//Return 2.
//
//Note
//You can assume each number in the array is a positive integer and not greater than 100.

namespace LintSolution1
{
    namespace MinimumAdjustmentCost_Medium
    {
		namespace naiveLoop
		{
			void getMin(vector<int>& A, vector<int>&B, int len, int target, int level, int& minVal, int cost)
			{
				if (level >= len) {
					minVal = min(minVal, cost);
					return;
				}

				for (int i = 0; i <= 100; i++)
				{
					if (level != 0 && abs(i - B[level - 1]) > target) { continue; }
					B[level] = i;
					getMin(A, B, len, target, level + 1, minVal, cost + abs(i - A[level]));
					B[level] = A[level];
				}
			}


			/**
			* @param A: An integer array.
			* @param target: An integer.
			*/
			int MinAdjustmentCost(vector<int> A, int target) {
				int len = A.size();
				if (len < 2) { return 0; }

				int minVal = INT_MAX;
				vector<int> B(len);
				copy(A.begin(), A.end(), B.begin());
				getMin(A, B, len, target, 0, minVal, 0);
				return minVal;
			}
		}

		namespace problematic{
			void getMin(vector<int>& A, vector<int>& B, int target, int level, int cost, int& minVal, vector<vector<int>>& cache)
			{
				if (level >= A.size())
				{
					minVal = min(minVal, cost);
					return;
				}

				for (int i = 1; i <= 10; i++)
				{
					if (level != 0 && abs(i - B[level - 1]) > target) { continue; }

					if (cache[level][i] != INT_MAX)
					{
						minVal = min(minVal, cache[level][i]);
						continue;
					}

					B[level] = i;
					getMin(A, B, target, level + 1, cost + abs(i - A[level]), minVal, cache);
					cache[level][i] = minVal;
					B[level] = A[level];
				}
			}


			/**
			* @param A: An integer array.
			* @param target: An integer.
			*/
			int MinAdjustmentCost(vector<int> A, int target) {
				int len = A.size();
				if (len < 2) { return 0; }

				int minVal = INT_MAX;
				vector<int> B(len);
				copy(A.begin(), A.end(), B.begin());

				vector<vector<int>> cache(len, vector<int>(11, INT_MAX));
				getMin(A, B, target, 0, 0, minVal, cache);
				print(cache);
				return minVal;
			}
		}


		int MinAdjustmentCost(vector<int> A, int target) {
			int len = A.size();
			if (len < 2) { return 0; }

			vector<vector<int>> M(2, vector<int>(101, INT_MAX));

			for (int i = 0; i < len; i++)
			{
				for (int j = 1; j <= 100; j++)
				{
					int upper = min(100, j + target);
					int lower = max(1, j - target);
					for (int k = lower; k <= upper; k++)
					{
						M[i % 2][j] = min(M[i % 2][j], M[(i - 1) % 2][k]);
					}
					M[i % 2][j] += abs(A[i - 1] - j);
				}
			}
			return *min_element(next(M[len % 2].cbegin()), M[len % 2].cend());
		}


        void Main()
        {
			print(MinAdjustmentCost(createVector({ 1, 4, 2}), 1));
			//print(MinAdjustmentCost(createVector({ 12, 3, 7, 4, 5, 13, 2, 8, 4, 7, 6, 5, 7 }), 2));
			
        }
    }
}
   
    