#include "stdafx.h"

//Given a list of integers, which denote a permutation.
//
//Find the next permutation in ascending order.
//
//Example
//For[1, 3, 2, 3], the next permutation is[1, 3, 3, 2]
//
//For[4, 3, 2, 1], the next permutation is[1, 2, 3, 4]
//
//Note
//The list may contains duplicate integers.


namespace LintSolution1
{
    namespace NextPermutation_Medium
    {     
		/**
		* @param nums: An array of integers
		* @return: An array of integers that's next permuation
		*/
		vector<int> nextPermutation(vector<int> &nums) {
			int len = nums.size();			
			if (len == 0) { return nums; }

			int i = len - 2;
			while (i >= 0 && nums[i] >= nums[i + 1]) { i--; }
			if (i < 0) { reverse(nums.begin(), nums.end()); return nums; }
			int j = len - 1;
			while (j >= 0 && nums[j] <= nums[i]) { j--; }
			swap(nums[i], nums[j]);
			reverse(nums.begin() + i + 1, nums.end());
			return nums;
		}
     
        void Main()
        {
			print(nextPermutation(createVector({ 1, 2, 1 })));
			print(nextPermutation(createVector({ 1, 1 })));
			print(nextPermutation(createVector({ 1, 3, 2, 3 })));
			print(nextPermutation(createVector({ 4, 3, 2, 1 })));
        }
    }
}
   
    