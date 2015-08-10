#include "stdafx.h"

//Given an array of integers and a number k, find k non - overlapping subarrays which have the largest sum.
//
//The number in each subarray should be contiguous.
//
//Return the largest sum.
//
//Example
//Given[-1, 4, -2, 3, -2, 3], k = 2, return 8
//
//Note
//The subarray should contain at least one number


namespace LintSolution1
{
    namespace MaximumSubarrayIII_Hard
    {
     
		/**
		* @param nums: A list of integers
		* @param k: An integer denote to find k non-overlapping subarrays
		* @return: An integer denote the sum of max k non-overlapping subarrays
		*/
		int maxSubArray(vector<int> nums, int k) {
			int len = nums.size();
			if (len == 0) { return 0; }
			
			vector<vector<int>> sums(len + 1, vector<int>(k + 1, INT_MIN));

			for (int i = 0; i < len + 1; i++)
			{
				sums[i][0] = 0;
			}


			for (int i = 0; i <= len; i++)
			{
				for (int j = 1; j <= min(i, k); j++)
				{
					sums[i][j] = sums[i - 1][j];
					int maxSumFromP = 0;
					for (int p = i; p > j - 1; p--)
					{
						maxSumFromP = max(0, maxSumFromP) + nums[p - 1];
						sums[i][j] = max(sums[i][j], maxSumFromP + sums[p - 1][j - 1]);
					}
				}
			}
			return sums[len][k];
		}
     
        void Main()
        {
			print(maxSubArray(createVector({ 1, 2, 3 }), 1));
        }
    }
}
   
    