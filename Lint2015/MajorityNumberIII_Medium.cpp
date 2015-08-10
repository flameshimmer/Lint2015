#include "stdafx.h"

//Given an array of integers and a number k, the majority number is the number that occurs more than 1 / k of the size of the array.
//
//Find it.
//
//Example
//Given[3, 1, 2, 3, 2, 3, 3, 4, 4, 4] and k = 3, return 3.
//
//Note
//There is only one majority number in the array.
//
//Challenge
//O(n) time and O(k) extra space


namespace LintSolution1
{
    namespace MajorityNumberIII_Medium
    {
     
		/**
		* @param nums: A list of integers
		* @param k: As described
		* @return: The majority number
		*/
		int majorityNumber(vector<int> nums, int k) {
			int len = nums.size();
			if (len == 0) { return -1; }

			unordered_map<int, int> map; // val, count
			for (int v : nums)
			{
				map[v]++;
				if (map.size() == k) // there should only be k-1 majority number
				{
					auto it = map.begin();
					while (it != map.end())
					{
						it->second--;
						if (it->second == 0) { it = map.erase(it); }
						else { it++; }
					}
				}
			}

			for (auto p : map)
			{
				map[p.first] = 0;
			}
			for (int v : nums)
			{
				map[v]++;
			}
			for (auto p : map)
			{
				if (p.second > len / k) { return p.first; }
			}
			return -1;
		}
     
     
        void Main()
        {
			print(majorityNumber(createVector({ 3, 1, 2, 3, 2, 3, 3, 4, 4, 4 }), 3));
        }
    }
}
   
    