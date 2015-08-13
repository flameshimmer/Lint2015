#include "stdafx.h"

//Partition an integers array into odd number first and even number second.
//
//Example
//Given[1, 2, 3, 4], return[1, 3, 2, 4]
//
//Challenge
//Do it in - place.

namespace LintSolution1
{
    namespace PartitionArraybyOddAndEven_Easy
    {
		/**
		* @param nums: a vector of integers
		* @return: nothing
		*/
		void partitionArray(vector<int> &nums) {
			int len = nums.size();
			if (len < 2) { return; }

			int start = 0;
			int end = len - 1;
			int slow = start;
			int fast = start;
			while (fast <= end) //----> not that since there is no pivot, we need to traverse to the end index
			{
				if (nums[fast] % 2 == 1)
				{
					swap(nums[fast], nums[slow]);
					slow++;
				}
				fast++;
			}
		}
     
        void Main()
        {
			vector<int> input;
			input = { 2147483644, 2147483645, 2147483646, 2147483647 };
			partitionArray(input);
			print(input);         
        }
    }
}
   
    