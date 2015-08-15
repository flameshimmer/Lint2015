#include "stdafx.h"

//Given an integer array, find a subarray with sum closest to zero.Return the indexes of the first number and last number.
//
//Example
//Given[-3, 1, 1, -3, 5], return[0, 2], [1, 3], [1, 1], [2, 2] or[0, 4]
//
//Challenge
//O(nlogn) time

namespace LintSolution1
{
	namespace SubarraySumClosest_Medium
	{

		/**
		* @param nums: A list of integers
		* @return: A list of integers includes the index of the first number
		*          and the index of the last number
		*/
		vector<int> subarraySumClosest(vector<int> nums){
			int len = nums.size();
			if (len == 0) return{ -1, -1 };
			if (len == 1) return{ 0, 0 };

			vector<pair<int, int>> sums(len + 1);
			sums[0] = make_pair(0, -1);

			int sum = 0;
			for (int i = 0; i < len; i++)
			{
				sum += nums[i];
				sums[i + 1] = make_pair(sum, i);
			}

			sort(sums.begin(), sums.end());
			int minDiff = INT_MAX;
			int start = -1;
			int end = -1;
			for (int i = 1; i < sums.size(); i++)
			{
				int diff = abs(sums[i].first - sums[i - 1].first);
				if (diff < minDiff)
				{
					minDiff = diff;
					start = min(sums[i].second, sums[i - 1].second) + 1;
					end = max(sums[i].second, sums[i - 1].second);
				}
			}
			return { start, end };
		}


		void Main()
		{
			print(subarraySumClosest(createVector({ -3, 1, 1, -3, 5 })));
			print(subarraySumClosest(createVector({ INT_MAX })));
			print(subarraySumClosest(createVector({ 6, -4, -8, 3, 1, 7 })));
		}
	}
}

