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
		/**
		* @param A an integer array
		* @return  A list of integers includes the index of
		*          the first number and the index of the last number
		*/
		vector<int> continuousSubarraySumII(vector<int>& A) {
			vector<int> result(2, -1);
			int len = A.size();
			if (len == 0) { return result; }

			int sum = 0;
			int maxSum = INT_MIN;			
			for (int i = 0, j = 0; i < len; j++)
			{
				if (sum <= 0)
				{
					sum = 0;
					i = j;
				}
				int j2 = j%len;
				sum += A[j2];
				if (sum > maxSum)
				{
					maxSum = sum;
					result[0] = i;
					result[1] = j2;
				}
				if ((j + 1) % len == i) { break; }
			}
			return result;
		}
     
        void Main()
        {
			print(continuousSubarraySumII(createVector({ 2, -1, -2, -3, -100, 1, 2, 3, 100 })));
			print(continuousSubarraySumII(createVector({ 3, 1, -100, -3, 4 })));
			print(continuousSubarraySumII(createVector({ 1, -1 })));
        }
    }
}
   
    