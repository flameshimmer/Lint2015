#include "stdafx.h"
//Given an integer array, find a subarray where the sum of numbers is between two given interval.
//Your code should return the number of possible answer.
//
//Example
//Given[1, 2, 3, 4] and interval = [1, 3], return 4. The possible answers are :
//
//[0, 0]
//[0, 1]
//[1, 1]
//[2, 2]
namespace LintSolution1
{
    namespace SubarraySumII_Hard
    {
		int subarraySumII(vector<int>& A, int start, int end) {
			int len = A.size();
			vector<int> sums(len + 1);
			partial_sum(A.begin(), A.end(), sums.begin() + 1);

			int count = 0;
			for (int i = 0; i < sums.size(); i++)
			{
				auto left = lower_bound(sums.begin(), sums.begin() + i, sums[i] - end);
				auto right = upper_bound(sums.begin(), sums.begin() + i, sums[i] - start);
				count += right - left;
			}
			return count;
		}


		namespace N2
		{
			int subarraySumII(vector<int>& A, int start, int end) {
				int len = A.size();
				if (len == 0) { return 0; }

				vector<int> sums(len + 1);
				partial_sum(A.begin(), A.end(), sums.begin() + 1);

				int count = 0;
				for (int i = 0; i < sums.size()-1; i++)
				{
					for (int j = i+1; j < sums.size(); j++)
					{
						int rangeSum = sums[j] - sums[i];
						if (rangeSum >= start && rangeSum <= end)
						{
							count++;
						}
					}
				}
				return count;
			}
		}
		void Main()
		{
			print(subarraySumII(createVector({ 1, 2, 3, 4 }), 1, 3));
			print(N2::subarraySumII(createVector({ 1, 2, 3, 4 }), 1, 3));
		}
    }
}
   
    