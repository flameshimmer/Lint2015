#include "stdafx.h"

//Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
//Return the sum of the three integers.
//
//Example
//For example, given array S = { -1 2 1 - 4 }, and target = 1. The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//Note
//You may assume that each input would have exactly one solution.
//
//Challenge
//O(n ^ 2) time, O(1) extra space

namespace LintSolution1
{
    namespace ThreeSumClosest_Medium
    {
     
		/**
		* @param numbers: Give an array numbers of n integer
		* @param target: An integer
		* @return: return the sum of the three integers, the sum closest target.
		*/
		int threeSumClosest(vector<int> nums, int target) {
			int len = nums.size();

			sort(nums.begin(), nums.end());

			int minDiff = INT_MAX;
			int result = 0;
			for (int i = 0; i < len; i++)
			{
				int target2 = target - nums[i];
				int start = i + 1;
				int end = len - 1;
				while (start < end)
				{
					int sum = nums[start] + nums[end];
					if (sum == target2) { return target; }
					else if (sum < target2) 
					{
						if (target2 - sum < minDiff) { minDiff = target2 - sum; result = nums[i] + sum; }
						start++;
					}
					else
					{
						if (sum - target2 < minDiff) { minDiff = sum - target2; result = nums[i] + sum; }
						end--;
					}
				}
			}
			return result;
		}
     
        void Main()
        {
			print(threeSumClosest(createVector({ 2, 7, 11, 15 }), 3));
        }
    }
}
   
    