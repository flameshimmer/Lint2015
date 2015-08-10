#include "stdafx.h"

//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//Example
//Given[100, 4, 200, 1, 3, 2],
//The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.
//
//Clarification
//Your algorithm should run in O(n) complexity.
//

namespace LintSolution1
{
    namespace LongestConsecutiveSequence_Medium
    {     
		/**
		* @param nums: A list of integers
		* @return an integer
		*/
		int longestConsecutive(vector<int> &nums) {
			int len = nums.size();
			if (len < 2) { return len; }

			unordered_set<int> set;
			for (int v : nums) { set.insert(v); }

			int maxCount = 0;			
			while (!set.empty())
			{
				int v = *set.begin();
				int count = 1;
				set.erase(v);

				int cur = v - 1;
				while (set.find(cur) != set.end()) { set.erase(cur); cur--; count++; }

				cur = v + 1;
				while (set.find(cur) != set.end()) { set.erase(cur); cur++; count++; }

				maxCount = max(maxCount, count);
			}

			return maxCount;
		}
     
        void Main()
        {
			print(longestConsecutive(createVector({ 100, 4, 200, 1, 3, 2 })));
        }
    }
}
   
    