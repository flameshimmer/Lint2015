#include "stdafx.h"

//Numbers keep coming, return the median of numbers at every time a new number added.
//
//Example
//For numbers coming list : [1, 2, 3, 4, 5], return[1, 1, 2, 2, 3].
//
//For numbers coming list : [4, 5, 1, 3, 2, 6, 0], return[4, 4, 4, 3, 3, 3, 3].
//
//For numbers coming list : [2, 20, 100], return[2, 2, 20].
//
//Challenge
//Total run time in O(nlogn).
//
//Clarification
//What's the definition of Median? - Median is the number that in the middle of a sorted array. 
//If there are n numbers in a sorted array A, the median is A[(n - 1) / 2].For example, if A = [1, 2, 3], median is 2. If A = [1, 19], median is 1.

namespace LintSolution1
{
    namespace DataStreamMedian_Hard
    {     
		/**
		* @param nums: A list of integers.
		* @return: The median of numbers
		*/
		vector<int> medianII(vector<int> &nums) {
			vector<int> result;
			
			priority_queue<int, vector<int>, greater<int>> minHeap;
			priority_queue<int, vector<int>, less<int>> maxHeap;

			for (int v : nums)
			{				
				if (maxHeap.empty() || v <= maxHeap.top()) { maxHeap.push(v); }
				else { minHeap.push(v); }
				int biggerHalfCount = minHeap.size();
				int smallerHalfCount = maxHeap.size();
				if (biggerHalfCount - smallerHalfCount >= 2) { maxHeap.push(minHeap.top()); minHeap.pop(); smallerHalfCount++; biggerHalfCount--; }
				if (smallerHalfCount - biggerHalfCount >= 2) { minHeap.push(maxHeap.top()); maxHeap.pop(); smallerHalfCount--; biggerHalfCount++; }
				if (smallerHalfCount > biggerHalfCount) { result.push_back(maxHeap.top()); }
				else if (smallerHalfCount < biggerHalfCount) { result.push_back(minHeap.top()); }
				else { result.push_back(maxHeap.top()); }
			}
			return result;
		}
     
        void Main()
        {
			print(medianII(createVector({ 2, 20, 13, 18, 15, 8, 3, 5, 4, 25 })));
			print(medianII(createVector({ 4, 5, 1, 3, 2, 6, 0 })));
			print(medianII(createVector({ 1, 2, 3, 4, 5 })));			
			print(medianII(createVector({ 2, 20, 100 })));
        }
    }
}
   
    