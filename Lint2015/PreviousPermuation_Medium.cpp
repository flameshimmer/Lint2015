#include "stdafx.h"

//Given a list of integers, which denote a permutation.
//
//Find the previous permutation in ascending order.
//
//Example
//For[1, 3, 2, 3], the previous permutation is[1, 2, 3, 3]
//
//For[1, 2, 3, 4], the previous permutation is[4, 3, 2, 1]

namespace LintSolution1
{
    namespace PreviousPermuation_Medium
    {
     
		/**
		* @param nums: An array of integers
		* @return: An array of integers that's previous permuation
		*/
		vector<int> previousPermuation(vector<int> &nums) {
			int len = nums.size();
			if (len < 2) { return nums; }

			int i = len - 2;
			while (i>=0)
			{
				if (nums[i] > nums[i + 1]) { break; }
				i--;
			}
			if (i < 0) { reverse(nums.begin(), nums.end()); return nums; }

			int j = len - 1;
			while (j > i)
			{
				if (nums[j] < nums[i]) { break; }
				j--;
			}
			swap(nums[i], nums[j]);
			reverse(nums.begin() + i + 1, nums.end());
			return nums;
		}
     
        void Main()
        {
         
        }
    }
}
   
    