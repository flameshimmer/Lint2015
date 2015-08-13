#include "stdafx.h"

//On one line there are n houses.Give you an array of integer means the the position of each house.
//Now you need to pick k position to build k post office, so that the sum distance of each house to 
//the nearest post office is the smallest.Return the least possible sum of all distances between 
//each village and its nearest post office.
//
//Example
//Given array a = [1, 2, 3, 4, 5], k = 2. return 3.
//
//Challenge
//Could you solve this problem in O(n ^ 2) time ?

namespace LintSolution1
{
	namespace PostOfficeProblem_Hard
	{
		int calcCost(vector<int>& A, int start, int end, vector<vector<int>>&C)
		{
			if (C[start][end] != INT_MAX) { return C[start][end]; }

			int midIndex = start + (end - start) / 2;
			int cost = 0;
			for (int i = start; i <= end; i++)
			{
				cost += abs(A[i] - A[midIndex]);
			}

			C[start][end] = cost;
			return cost;
		}

		int postOffice(vector<int>& A, int k) {
			int len = A.size();
			if (len == 0 || len <= k) { return 0; }
			sort(A.begin(), A.end());

			vector<vector<int>> cost(len, vector<int>(len, INT_MAX));
			vector<vector<int>> M(len + 1, vector<int>(len + 1, INT_MAX));
			M[0][0] = 0;
			for (int i = 0; i <= len; i++)
			{
				for (int t = 1; t <= k; t++)
				{
					for (int j = 0; j < i; j++)
					{
						if (M[j][t - 1] == INT_MAX) { continue; }
						M[i][t] = min(M[i][t], M[j][t - 1] + calcCost(A, j, i - 1, cost));
					}
				}
			}
			return M[len][k];
		}

		void Main()
		{
			print(postOffice(createVector({ 112, 122, 360, 311, 85, 225, 405, 53, 405, 43, 342, 13, 588, 424, 299, 37, 104, 289, 404, 414 }), 3));
			print(postOffice(createVector({ 1, 3, 5, 7, 10, 11, 20, 45, 99, 102, 105 }), 2));
			print(postOffice(createVector({ 1, 2, 3, 4, 5 }), 2));
		}
	}
}

