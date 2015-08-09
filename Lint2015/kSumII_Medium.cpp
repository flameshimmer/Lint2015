#include "stdafx.h"

//
//Given n unique integers, number k(1 <= k <= n)  and target.Find all possible k integers where their sum is target.
//
//Have you met this question in a real interview ? Yes
//Example
//
//Given[1, 2, 3, 4], k = 2, target = 5, [1, 4] and[2, 3] are possible solutions.

namespace LintSolution1
{
    namespace kSumII_Medium
    {

		void kSum2Impl(vector<int>& A, int level, int start, int target, int len, vector<int>& result, vector<vector<int>>& results)
		{
			if (level == 2)
			{
				int end = len - 1;
				while (start < end)
				{
					int sum = A[start] + A[end];
					if (sum == target)
					{
						result.push_back(A[start]);
						result.push_back(A[end]);
						results.push_back(result);
						result.pop_back();
						result.pop_back();
						start++;
					}
					else if (sum < target) { start++; }
					else { end--; }
				}
				return;
			}

			for (int i = start; i < len; i++)
			{
				result.push_back(A[i]);
				kSum2Impl(A, level - 1, i + 1, target - A[i], len, result, results);
				result.pop_back();
			}
		}
     
		/**
		* @param A: an integer array.
		* @param k: a positive integer (k <= length(A))
		* @param target: a integer
		* @return a list of lists of integer
		*/
		vector<vector<int> > kSumII(vector<int> A, int k, int target) {
			vector<vector<int>> results;
			int len = A.size();
			if (len == 0 || k <= 0) { return results; }
			if (k == 1)
			{
				for (int v : A) { if (v == target) { results.push_back(vector<int>(1, v)); } }
				return results;
			}

			vector<int> result;
			kSum2Impl(A, k, 0, target, len, result, results);
			return results;
		}
     
     
        void Main()
        {
			print(kSumII(createVector({ 1, 4, 7, 10, 12, 15, 16, 18, 21, 23, 24, 25, 26, 29 }), 5, 113));
			print(kSumII(createVector({ 1, 4, 5, 6, 8 }), 1, 4));
			print(kSumII(createVector({ 1, 2, 3, 4 }), 2, 5));
        }
    }
}
   
    