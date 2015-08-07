#include "stdafx.h"

//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.
//
//Example
//Given[4, 4, 5, 6, 7, 0, 1, 2] return 0

namespace LintSolution1
{
    namespace FindMinimumInRotatedSortedArrayII_Medium
    {
     
		/**
		* @param num: the rotated sorted array
		* @return: the minimum number in the array
		*/
		int findMin(vector<int> &num) {
			int len = num.size();
			if (len == 0) { return -1; }

			int start = 0;
			int end = len - 1;
			while (start < end)
			{
				while (start + 1 < len && num[start] == num[start + 1]) { start++; }
				while (end - 1 >= 0 && num[end] == num[end - 1]) { end--; }
				int mid = start + (end - start) / 2;
				if (num[start] < num[mid])
				{
					start = mid;
				}
				else if (num[mid] < num[end])
				{
					end = mid;
				}
				else
				{
					break;
				}
			}
			return num[end];
		}
     
        void Main()
        {
			print(findMin(createVector({ 1, 1, -1, 1 })));
        }
    }
}
   
    