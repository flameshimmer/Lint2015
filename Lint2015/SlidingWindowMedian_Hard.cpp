#include "stdafx.h"

//Given an array of n integer, and a moving window(size k), move the window at each iteration 
//from the start of the array, find the median of the element inside the window at each moving.
//(If there are even numbers in the array, return the N / 2 - th number after sorting the element in the window.)
//
//
//Example
//For array[1, 2, 7, 8, 5], moving window size k = 3. return[2, 7, 7]
//
//At first the window is at the start of the array like this
//
//[| 1, 2, 7 | , 8, 5], return the median 2;
//
//then the window move one step forward.
//
//[1, | 2, 7, 8 | , 5], return the median 7;
//
//then the window move one step forward again.
//
//[1, 2, | 7, 8, 5 | ], return the median 7;
//
//Challenge
//O(nlog(n)) time

namespace LintSolution1
{
    namespace SlidingWindowMedian_Hard
    {
		/**
		* @param nums: A list of integers.
		* @return: The median of the element inside the window at each moving
		*/
		vector<int> medianSlidingWindow(vector<int> &nums, int k) {
			vector<int> result;
			int len = nums.size();
			if (len < k) { return result; }

			multiset<int, less<int>> bigger;
			multiset<int, greater<int>> smaller;

			for (int i = 0; i < len; i++)			
			{
				if (i >= k)
				{
					int removeTarget = nums[i - k];
					if (bigger.find(removeTarget) != bigger.end()) { bigger.erase(bigger.find(removeTarget)); }
					else{ smaller.erase(smaller.find(removeTarget)); } // erase iterator, not value. since removing value will remove all slots of this value
				}

				if (smaller.empty() || nums[i]> *smaller.cbegin() )
				{
					bigger.insert(nums[i]);
					if (bigger.size() - smaller.size() > 1)
					{
						smaller.insert(*bigger.cbegin()); // insert value
						bigger.erase(bigger.cbegin()); // remove iterator
					}
				}
				else
				{
					smaller.insert(nums[i]);
					if (smaller.size() > bigger.size()) // keep smaller size not larger than bigger
					{
						bigger.insert(*smaller.cbegin()); // insert value
						smaller.erase(smaller.cbegin()); // remove iterator
					}
				}

				if (i >= k - 1)
				{
					result.push_back(bigger.size() > smaller.size() ? *bigger.cbegin() : *smaller.cbegin());
				}

			}
			return result;
		}
     
        void Main()
        {
			print(medianSlidingWindow(createVector({ 76, 132, 106, 88, 187, 22, 76, 121, 187, 84, 53, 176, 9, 192, 22, 126, 127, 178, 26, 195, 142, 141, 4, 33, 112, 154, 127, 58, 90, 194, 80, 152, 178, 144, 110, 166, 169, 104, 120, 187, 89, 134, 118, 69, 5 }), 36));
			print(medianSlidingWindow(createVector({ 1, 2, 7, 7, 2 }), 5));
			print(medianSlidingWindow(createVector({ 1, 2, 7, 8, 5 }), 3));
        }
    }
}
   
    