#include "stdafx.h"

//Find K-th largest element in an array.
//
//Example
//In array[9, 3, 2, 4, 8], the 3rd largest element is 4.
//
//In array[1, 2, 3, 4, 5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.
//
//Note
//You can swap elements in the array
//
//Challenge
//O(n) time, O(1) extra memory.

namespace LintSolution1
{
    namespace KthLargestElement_Medium
    {     
		
		int partition(vector<int>& nums, int start, int end, int pivot)
		{
			int pivotVal = nums[pivot];
			swap(nums[pivot], nums[end]);

			int slow = start;
			int fast = start;
			while (fast < end)
			{
				if (nums[fast] > pivotVal)
				{
					swap(nums[fast], nums[slow]);
					slow++;
				}
				fast++;
			}
			swap(nums[end], nums[slow]);
			return slow;
		}

		/*
		* param k : description of k
		* param nums : description of array and index 0 ~ n-1
		* return: description of return
		*/
		int kthLargestElement(int k, vector<int> nums) 
		{
			int len = nums.size();
			int start = 0;
			int end = len - 1;
			k--;

			while (start <= end)
			{
				int index = partition(nums, start, end, k);
				if (index == k) { return nums[index]; }
				else if (index < k) { start = index + 1; }
				else { end = index - 1; }
			}
			return -1;
		}
     
        void Main()
        {
			print(kthLargestElement(10, createVector({ 1, 2, 3, 4, 5, 6, 8, 9, 10, 7 })));
			print(kthLargestElement(3, createVector({9,3,2,4,8})));
        }
    }
}
   
    