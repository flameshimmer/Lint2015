#include "stdafx.h"

//Given an array of integers, find a contiguous subarray which has the largest sum.
//
//Example
//Given the array[-2, 2, -3, 4, -1, 2, 1, -5, 3], the contiguous subarray[4, -1, 2, 1] has the largest sum = 6.
//
//Note
//The subarray should contain at least one number.
//
//Challenge
//Can you do it in time complexity O(n) ?

namespace LintSolution1
{
    namespace MaximumSubarray_Easy
    {
		/**
		* @param nums: A list of integers
		* @return: A integer indicate the sum of max subarray
		*/
		int maxSubArray(vector<int> nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			int sum = nums[0];
			int maxSum = sum;

			for (int i = 1; i < len; i++)
			{
				if (sum < 0) { sum = 0; }
				sum += nums[i];
				maxSum = max(maxSum, sum);
			}
			return maxSum;
		}
     
        void Main()
        {
         
        }
    }
}
   
    