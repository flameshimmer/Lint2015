#include "stdafx.h"

//Ugly number is a number that only have factors 3, 5 and 7.
//
//Design an algorithm to find the Kth ugly number.The first 5 ugly numbers are 3, 5, 7, 9, 15 ...
//
//Have you met this question in a real interview ? Yes
//Example
//If K = 4, return 9.
//
//Challenge
//O(K log K) or O(K) time.
//
namespace LintSolution1
{
    namespace UglyNumber_Medium
    {     
     	/*
		* @param k: The number k.
		* @return: The kth prime number as description.
		*/
		long long kthPrimeNumber(int k) {
			vector<long long> result(k + 1);
			result[0] = 1;

			int k3 = 0, k5 = 0, k7 = 0;
			for (int i = 1; i <= k; i++)
			{
				result[i] = min(min(result[k3] * 3, result[k5] * 5), result[k7] * 7);
				if (result[i] / result[k3] == 3) { k3++; }
				if (result[i] / result[k5] == 5) { k5++; }
				if (result[i] / result[k7] == 7) { k7++; }
			}
			return result[k];
		}

		namespace nLogN
		{
			long long kthPrimeNumber(int k) 
			{
				priority_queue<long long, vector<long long>, greater<long long>> heap;

				heap.push(3);
				heap.push(5);
				heap.push(7);

				int result = -1;
				for (int i = 1; i <= k; i++)
				{
					int top = heap.top();
					result = top;
					heap.pop();
					if (top % 3 == 0)
					{
						heap.push(top * 3);
					}
					else if (top % 5 == 0)
					{
						heap.push(top * 3);
						heap.push(top * 5);
					}
					else
					{
						heap.push(top * 3);
						heap.push(top * 5);
						heap.push(top * 7);
					}
				}
				return result;
			}
		}
     
        void Main()
        {
         
        }
    }
}
   
    