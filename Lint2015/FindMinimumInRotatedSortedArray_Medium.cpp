#include "stdafx.h"

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//Example
//Given[4, 5, 6, 7, 0, 1, 2] return 0
//
//Note
//You may assume no duplicate exists in the array.

namespace LintSolution1
{
    namespace FindMinimumInRotatedSortedArray_Medium
    {     
		/**
		* @param num: a rotated sorted array
		* @return: the minimum number in the array
		*/
		int findMin(vector<int> &nums) {
			int len = nums.size();
			if (len == 0) { return -1; }
			if (nums[0] < nums[len - 1]) { return nums[0]; }

			int start = 0;
			int end = len - 1;
			while (start < end)
			{
				int mid = start + (end - start) / 2;

				if (nums[start] < nums[mid])
				{
					start = mid;
				}
				else if (nums[mid] < nums[end])
				{
					end = mid;
				}
				else
				{
					return nums[end];
				}
			}
		}
     
        void Main()
        {
			print(findMin(createVector({ 4, 5, 6, 7, 0, 1, 2 })));
        }
    }
}
   
    