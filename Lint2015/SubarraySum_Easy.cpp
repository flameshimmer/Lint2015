#include "stdafx.h"


//Given an integer array, find a subarray where the sum of numbers is zero.
//Your code should return the index of the first number and the index of the last number.
//
//Example
//Given[-3, 1, 2, -3, 4], return[0, 2] or[1, 3].
//
//Note
//There is at least one subarray that it's sum equals to zero.

namespace LintSolution1
{
    namespace SubarraySum_Easy
    {
     
		/**
		* @param nums: A list of integers
		* @return: A list of integers includes the index of the first number
		*          and the index of the last number
		*/
		vector<int> subarraySum(vector<int> nums){
			vector<int> result(2, -1);
			int len = nums.size();
			if (len == 0) { return result; }

			unordered_map<int, int> sumTable; // sum, index
			sumTable[0] = -1;
			int sum = 0;
			for (int i = 0; i < len; i++)
			{
				sum += nums[i];
				if (!sumTable.emplace(sum, i).second)
				{
					result[0] = sumTable[sum] + 1;
					result[1] = i;
					return result;
				}
			}
			return result;
		}
     
        void Main()
        {
			print(subarraySum(createVector({ 1, -1 })));
			print(subarraySum(createVector({ -3, 1, 2, -3, 4 })));
        }
    }
}
   
    