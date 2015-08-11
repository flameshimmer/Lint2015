#include "stdafx.h"
#include <numeric>

//Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s.If there isn't one, return -1 instead.
//
//Example
//Given the array[2, 3, 1, 2, 4, 3] and s = 7, the subarray[4, 3] has the minimal length under the problem constraint.
//
//Challenge
//If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

namespace LintSolution1
{
    namespace MinimumSizeSubarraySum_Medium
    {
		/**
		* @param nums: a vector of integers
		* @param s: an integer
		* @return: an integer representing the minimum size of subarray
		*/
		int minimumSize(vector<int> &nums, int s) {
			int len = nums.size();
			if (len == 0) { return -1; }

			int start = 0;
			int end = 0;
			int sum = 0;
			int minLen = INT_MAX;
			while (end < len)
			{
				while (end < len && sum < s)
				{
					sum += nums[end];
					end++;
				}
				if (sum < s) { break; }
				while (start < len && sum >= s)
				{
					sum -= nums[start];
					start++;
				}
				minLen = min(minLen, end - start + 1);
			}
			return minLen == INT_MAX ? -1 : minLen;
		}

		namespace nLogn
		{		
			int binarySearch(vector<int>& A, int start, int end, int target)
			{
				while (start <= end)
				{
					int mid = start + (end - start) / 2;
					if (A[mid] <= target)
					{
						start = mid + 1;
					}
					else
					{
						end = mid - 1;
					}
				}
				return end;
			}


			int minimumSize(vector<int> &nums, int s) {
				int len = nums.size();
				if (len == 0) { return -1; }

				vector<int> sum(len);
				partial_sum(nums.begin(), nums.end(), sum.begin());
				int minLen = INT_MAX;
				for (int i = 0; i < len; i++)
				{
					if (sum[i] >= s)
					{
						int target = sum[i] - s;
						int rightMostIndex = binarySearch(sum, 0, i, target);
						minLen = min(minLen, i - rightMostIndex);
					}
				}
				return minLen == INT_MAX ? -1 : minLen;
			}
		}
     
        void Main()
        {
			
			print(nLogn::minimumSize(createVector({ 2, 3, 1, 2, 4, 3 }), 7));
			print(nLogn::minimumSize(createVector({ 100, 50, 99, 50, 100, 50, 99, 50, 100, 50 }), 250));
			print(nLogn::minimumSize(createVector({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2113, 1, 1 }), 12345));
			

			print(minimumSize(createVector({ 100, 50, 99, 50, 100, 50, 99, 50, 100, 50 }), 250));
			print(minimumSize(createVector({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2113, 1, 1 }), 12345));
			print(minimumSize(createVector({ 2, 3, 1, 2, 4, 3 }), 7));
        }
    }
}
   
    