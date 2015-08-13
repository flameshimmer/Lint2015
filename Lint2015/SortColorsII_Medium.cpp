#include "stdafx.h"

//Given an array of n objects with k different colors(numbered from 1 to k), sort them so that objects of 
//the same color are adjacent, with the colors in the order 1, 2, ... k.
//
//Example
//Given colors = [3, 2, 2, 1, 4], k = 4, your code should sort colors in - place to[1, 2, 2, 3, 4].
//
//Note
//You are not suppose to use the library's sort function for this problem.
//
//Challenge
//A rather straight forward solution is a two - pass algorithm using counting sort.
//That will cost O(k) extra memory.Can you do it without using extra memory ?

namespace LintSolution1
{
    namespace SortColorsII_Medium
    {
     
		int partition(vector<int>& colors, int start, int end, int pivotVal)
		{
			int slow = start;
			int fast = start;
			int store = end+1; // store index is only ready right before swap. Before that it is one more index than swap

			while (fast < store)
			{
				if (colors[fast] < pivotVal)
				{
					swap(colors[slow], colors[fast]);
					slow++;
				}
				else if (colors[fast] == pivotVal)
				{
					store--;
					swap(colors[fast], colors[store]);
					fast--;
				}
				fast++;
			}
			for (int i = store; i <= end; i++)
			{
				swap(colors[slow], colors[i]);
				slow++;
			}
			return slow;
		}

		/**
		* @param colors: A list of integer
		* @param k: An integer
		* @return: nothing
		*/
		void sortColors2(vector<int> &colors, int k) {
			int len = colors.size();			
			if (len < 2 || k <= 1) { return; }

			int start = 0;
			int end = len - 1;
			int pivotVal = 2;
			while (start < end)
			{
				start = partition(colors, start, end, pivotVal);
				pivotVal++;
			}
		}
     
     
        void Main()
        {
			vector<int> input;

			input = { 1, 3, 2, 4, 1, 2, 1, 2, 1, 4, 1, 3, 1, 3, 3, 4, 1, 1, 1, 1 };
			sortColors2(input, 4);

			input = { 3, 2, 3, 3, 4, 3, 3, 2, 4, 4, 1, 2, 1, 1, 1, 3, 4, 3, 4, 2 };
			sortColors2(input, 4);
			print(input);
        }
    }
}
   
    