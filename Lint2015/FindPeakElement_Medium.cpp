#include "stdafx.h"

//There is an integer array which has the following features :
//
//The numbers in adjacent positions are different.
//A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
//We define a position P is a peek if :
//
//A[P] > A[P - 1] && A[P] > A[P + 1]
//Find a peak element in this array.Return the index of the peak.
//
//Example
//Given[1, 2, 1, 3, 4, 5, 7, 6]
//
//Return index 1 (which is number 2) or 6 (which is number 7)
//
//Note
//The array may contains multiple peeks, find any of them.
//
//Challenge
//Time complexity O(logN)

namespace LintSolution1
{
    namespace FindPeakElement_Medium
    {     
		/**
		* @param A: An integers array.
		* @return: return any of peek positions.
		*/
		int findPeak(vector<int> A) {
			int len = A.size();
			int start = 0;
			int end = len - 1;

			while (start < end)
			{
				int mid = start + (end - start) / 2;
				int midVal = A[mid];
				int preVal = mid - 1 >= 0 ? A[mid - 1] : INT_MIN;
				int nextVal = mid + 1 < len ? A[mid + 1] : INT_MIN;
				
				if (preVal < midVal && midVal > nextVal) { return mid; }
				else if (midVal < nextVal)
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
			return -1;
		}
     
        void Main()
        {
			vector<int> input = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
			print(findPeak(input));
        }
    }
}
   
    