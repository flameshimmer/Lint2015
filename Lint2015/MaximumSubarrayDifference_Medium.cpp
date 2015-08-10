#include "stdafx.h"

//Given an array with integers.
//
//Find two non - overlapping subarrays A and B, which | SUM(A) - SUM(B) | is the largest.
//
//Return the largest difference.
//
//Example
//For[1, 2, -3, 1], return 6
//
//Note
//The subarray should contain at least one number
//
//Challenge
//O(n) time and O(n) space.

namespace LintSolution1
{
    namespace MaximumSubarrayDifference_Medium
    {     
		/**
		* @param nums: A list of integers
		* @return: An integer indicate the value of maximum difference between two
		*          Subarrays
		*/
		int maxDiffSubArrays(vector<int> nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			vector<int> LTR(len, INT_MIN);
			vector<int> LTR2(len, INT_MAX);
			vector<int> RTL(len, INT_MIN);
			vector<int> RTL2(len, INT_MAX);
			
			int sumL = 0;
			int sumR = 0;
			int sumL2 = 0;
			int sumR2 = 0;
			int maxLTR = INT_MIN;
			int minLTR = INT_MAX;
			int maxRTL = INT_MIN;
			int minRTL = INT_MAX;
			
			for (int i = 0; i < len; i++)			
			{
				sumL = max(0, sumL);
				sumL += nums[i];
				maxLTR = max(maxLTR, sumL);
				LTR[i] = maxLTR;

				sumL2 = min(0, sumL2);
				sumL2 += nums[i];
				minLTR = min(minLTR, sumL2);
				LTR2[i] = minLTR;

				sumR = max(0, sumR);
				sumR += nums[len - 1 - i];
				maxRTL = max(maxRTL, sumR);
				RTL[len - 1 - i] = maxRTL;

				sumR2 = min(0, sumR2);
				sumR2 += nums[len - 1 - i];
				minRTL = min(minRTL, sumR2);
				RTL2[len - 1 - i] = minRTL;
			}

			int result = INT_MIN;
			for (int i = 0; i < len-1; i++)
			{
				result = max(result, abs(LTR[i] - RTL2[i + 1]));
				result = max(result, abs(LTR2[i] - RTL[i + 1]));
			}
			return result;
		}
     
        void Main()
        {
			print(maxDiffSubArrays(createVector({ -5, 3, -4, 0, 0, 0, -1, 20, 1, 1, -1, -1, -1, -1, -1 })));
			print(maxDiffSubArrays(createVector({ 1, 2, -3, 1 })));
        }
    }
}
   
    