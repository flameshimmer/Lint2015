#include "stdafx.h"

//Given an integer array, find a continuous subarray where the sum of numbers is the biggest.
//Your code should return the index of the first number and the index of the last number. 
//(If their are duplicate answer, return anyone)
//
//
//Example
//Give[-3, 1, 3, -3, 4], return[1, 4].

namespace LintSolution1
{
    namespace ContinuousSubarraySum_Medium
    {
     
		vector<int> continuousSubarraySum(vector<int>& A) {
			vector<int> result(2, -1);
			int len = A.size();
			if (len == 0) { return result; }

			int i = 0;
			int sum = 0;
			int maxSum = INT_MIN;
			for (int j = 0; j < len; j++)
			{
				if (sum < 0)
				{
					i = j;
					sum = 0;
				}

				sum += A[j];
				if (sum > maxSum)
				{
					maxSum = sum;
					result[0] = i;
					result[1] = j;
				}
			}
			return result;
		}
     
        void Main()
        {
			vector<int> input = {-101, -33, -44, -55, -67, -78, -101, -33, -44, -55, -67, -78, -100, -200, -1000, -22, -100, -200, -1000, -22 };
			vector<int> result = continuousSubarraySum(input);
			print(result);         
        }
    }
}
   
    