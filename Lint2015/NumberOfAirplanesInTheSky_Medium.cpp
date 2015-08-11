#include "stdafx.h"


//Given an interval list which are flying and landing time of the flight.How many airplanes are on the sky at most ?
//
//Example
//For interval list[[1, 10], [2, 3], [5, 8], [4, 7]], return 3
//
//Note
//If landing and flying happens at the same time, we consider landing should happen at first.

namespace LintSolution1
{
    namespace NumberOfAirplanesInTheSky_Medium
    {
		int partition(vector<pair<int, bool>>& nums, int start, int end)
		{
			int pivot = start + (end - start) / 2;
			int pivotVal = nums[pivot].first;
			int pivotBool = nums[pivot].second;
			swap(nums[pivot], nums[end]);
			int slow = start;
			int fast = start;
			while (fast < end)
			{
				if (nums[fast].first < pivotVal || (nums[fast].first == pivotVal && pivotBool && !nums[fast].second))
				{
					swap(nums[slow], nums[fast]);
					slow++;
				}
				fast++;
			}
			swap(nums[slow], nums[end]);
			return slow;
		}

		void quickSort(vector<pair<int, bool>>& nums, int start, int end)
		{
			if (start >= end) { return; }
			int index = partition(nums, start, end);
			quickSort(nums, start, index - 1);
			quickSort(nums, index + 1, end);
		}

		/**
		* @param intervals: An interval array
		* @return: Count of airplanes are in the sky.
		*/
		int countOfAirplanes(vector<Interval> &airplanes) {
			int len = airplanes.size();
			if (len < 2) { return len; }

			vector<pair<int, bool>> points; // val, isStart
			for (Interval v : airplanes)
			{
				points.push_back(make_pair(v.start, true));
				points.push_back(make_pair(v.end, false));
			}
			quickSort(points, 0, points.size() - 1);

			int result = 0;
			int maxResult = 0;
			for (pair<int, int> p : points)
			{
				if (p.second) { result++; }
				else { result--; }
				maxResult = max(maxResult, result);
			}
			return maxResult;
		}
     
        void Main()
        {
			vector<Interval> input = { { 1, 10 }, { 2, 3 }, { 5, 8 }, { 4, 7 } };
			print(countOfAirplanes(input));
        }
    }
}
   
    