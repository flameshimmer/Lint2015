#include "stdafx.h"

//Given an integer array, find a continuous rotate subarray where the sum of numbers is the biggest.
//Your code should return the index of the first number and the index of the last number. 
//(If their are duplicate answer, return anyone.The answer can be rorate array or non - rorate array)
//
//Example
//Give[3, 1, -100, -3, 4], return[4, 1].

namespace LintSolution1
{
    namespace ContinuousSubarraySumII_Medium
    {
		vector<int> continuousSubarraySum(vector<int>& A, int& maxSum)
		{
			vector<int> result(2, -1);
			int len = A.size();
			if (len == 0) { return result; }

			int sum = 0;
			maxSum = INT_MIN;
			for (int i = 0, j = 0; j < len; j++)
			{
				if (sum < 0)
				{
					sum = 0;
					i = j;
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


		vector<int> continuousSubarraySumII(vector<int>& A) {			
			int len = A.size();
			if (len == 0) { return vector<int>(2, -1); }

			int maxSum1;
			vector<int> result1 = continuousSubarraySum(A, maxSum1);
			if (maxSum1 < 0) { return result1; }

			int sum = 0;
			for (int i = 0; i < len; i++)
			{
				sum += A[i];
				A[i] = -A[i];
			}

			int maxSum2;
			vector<int> result2 = continuousSubarraySum(A, maxSum2);
			maxSum2 += sum;

			if (maxSum1 > maxSum2) { return result1; }
			else
			{
				result2[0] = (result2[0] - 1) % len;
				result2[1] = (result2[1] + 1) % len;
				swap(result2[0], result2[1]);

				return result2;
			}
		}
     
        void Main()
        {
			
			print(continuousSubarraySumII(createVector({ 1, -1 })));
			print(continuousSubarraySumII(createVector({ 3, 1, -100, -3, 4 })));			
			print(continuousSubarraySumII(createVector({ 2, -1, -2, -3, -100, 1, 2, 3, 100 })));
        }
    }
}
   
    