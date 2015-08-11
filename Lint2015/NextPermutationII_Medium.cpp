#include "stdafx.h"

//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order(ie, sorted in ascending order).
//
//Example
//Here are some examples.Inputs are in the left - hand column and its corresponding outputs are in the right - hand column.
//
//1, 2, 3 → 1, 3, 2
//
//3, 2, 1 → 1, 2, 3
//
//1, 1, 5 → 1, 5, 1
//
//Challenge
//The replacement must be in - place, do not allocate extra memory.

namespace LintSolution1
{
    namespace NextPermutationII_Medium
    {     
		/**
		* @param nums: a vector of integers
		* @return: return nothing (void), do not return anything, modify nums in-place instead
		*/
		void nextPermutation(vector<int> &nums) {
			int len = nums.size();
			if (len == 0) { return; }

			int i = len - 2;
			while (i >= 0 && nums[i] >= nums[i + 1]) { i--; }
			if (i < 0) { reverse(nums.begin(), nums.end()); return; }

			int j = len - 1;
			while (j >= 0 && nums[j] <= nums[i]) { j--; }
			swap(nums[i], nums[j]);
			reverse(nums.begin() + i + 1, nums.end());
		}
     
        void Main()
        {
         
        }
    }
}
   
    