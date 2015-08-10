#include "stdafx.h"

//Given a sequence of integers, find the longest increasing subsequence(LIS).
//
//You code should return the length of the LIS.
//
//Have you met this question in a real interview ? Yes
//Example
//For[5, 4, 1, 2, 3], the LIS  is[1, 2, 3], return 3
//
//For[4, 2, 4, 5, 3, 7], the LIS is[4, 4, 5, 7], return 4
//
//Challenge
//Time complexity O(n ^ 2) or O(nlogn)
//
//Clarification
//What's the definition of longest increasing subsequence?
//
//* The longest increasing subsequence problem is to find a subsequence of a given sequence
//in which the subsequence's elements are in sorted order, lowest to highest, and in which 
//the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.  
//
//* https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

namespace LintSolution1
{
	namespace LongestIncreasingSubsequence_Medium
	{
		void insert(vector<int>& LIS, int target)
		{
			int start = 0;
			int end = LIS.size() - 1;
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				if (LIS[mid] <= target)
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
			
			if (start == LIS.size())
			{
				LIS.push_back(target);
			}
			else
			{
				LIS[start] = target;
			}
		}


		/**
		* @param nums: The integer array
		* @return: The length of LIS (longest increasing subsequence)
		*/
		int longestIncreasingSubsequence(vector<int> nums) {
			vector<int> LIS;
			for (int v : nums)
			{
				insert(LIS, v);
			}
			return LIS.size();
		}
		namespace DP
		{
			int longestIncreasingSubsequence(vector<int> nums) {
				int len = nums.size();
				if (len < 2) { return len; }

				vector<int>M(len, 1);
				int result = 0;
				for (int i = 1; i < len; i++)
				{
					for (int j = 0; j < i; j++)
					{
						if (nums[j] <= nums[i])
						{
							M[i] = max(M[i], M[j] + 1);
							result = max(result, M[i]);
						}
					}
				}
				return result;
			}
		}

		void Main()
		{
			print(longestIncreasingSubsequence(createVector({ 1, 10, 2 })));
			print(longestIncreasingSubsequence(createVector({ 5, 4, 1, 2, 3 })));
			print(longestIncreasingSubsequence(createVector({ 4, 2, 4, 5, 3, 7 })));
		}
	}
}

