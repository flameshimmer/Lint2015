#include "stdafx.h"

//Given an array of integers, find two non - overlapping subarrays which have the largest sum.
//
//The number in each subarray should be contiguous.
//
//Return the largest sum.
//
//Example
//For given[1, 3, -1, 2, -1, 2], the two subarrays are[1, 3] and[2, -1, 2] or[1, 3, -1, 2] and[2], they both have the largest sum 7.
//
//Note
//The subarray should contain at least one number
//
//Challenge
//Can you do it in time complexity O(n) ?

namespace LintSolution1
{
    namespace MaximumSubarrayII_Medium
    {
     
		/**
		* @param nums: A list of integers
		* @return: An integer denotes the sum of max two non-overlapping subarrays
		*/
		int maxTwoSubArrays(vector<int> nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			vector<int>LTR(len, 0);
			vector<int>RTL(len, 0);

			int sumL = 0;
			int sumR = 0;
			int maxSumL = INT_MIN;
			int maxSumR = INT_MIN;
			for (int i = 0; i < len; i++)
			{
				if (sumL < 0) { sumL = 0; }
				sumL += nums[i];
				maxSumL = max(maxSumL, sumL);
				LTR[i] = maxSumL;


				if (sumR < 0) { sumR = 0; }
				sumR += nums[len - 1 -i];
				maxSumR = max(maxSumR, sumR);
				RTL[len - 1 - i] = maxSumR;
			}

			int result = INT_MIN;
			for (int i = 0; i < len-1; i++)
			{
				result = max(result, LTR[i] + RTL[i + 1]);
			}
			return result;
		}
     
        void Main()
        {
			print(maxTwoSubArrays(createVector({ -1, -1 })));
			print(maxTwoSubArrays(createVector({ 1, 3, -1, 2, -1, 2 })));
        }
    }
}
   
    