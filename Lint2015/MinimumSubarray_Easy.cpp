#include "stdafx.h"

//Given an array of integers, find the subarray with smallest sum.
//
//Return the sum of the subarray.
//
//Example
//For[1, -1, -2, 1], return -3
//
//Note
//The subarray should contain at least one integer.

namespace LintSolution1
{
    namespace MinimumSubarray_Easy
    {     
		/**
		* @param nums: a list of integers
		* @return: A integer denote the sum of minimum subarray
		*/
		int minSubArray(vector<int> nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int minSum = INT_MAX;
			int sum = 0;
			for (int v : nums)
			{
				sum = min(0, sum);
				sum += v;
				minSum = min(minSum, sum);
			}
			return minSum;
		}
     
        void Main()
        {
         
        }
    }
}
   
    