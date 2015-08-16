#include "stdafx.h"

//Given n pieces of wood with length L[i](integer array).Cut them into small pieces to guarantee you could 
//have equal or more than k pieces with the same length.What is the longest length you can get from the n 
//pieces of wood ? Given L & k, return the maximum length of the small pieces.
//
//Example
//For L = [232, 124, 456], k = 7, return 114.
//
//Note
//You couldn't cut wood into float length.
//
//Challenge
//O(n log Len), where Len is the longest length of the wood.

namespace LintSolution1
{
    namespace WoodCut_Medium
    {

		int pieceCount(vector<int>& L, int x)
		{
			int count = 0;
			for (int v : L)
			{
				count += v / x;
			}
			return count;
		}
		/**
		*@param L: Given n pieces of wood with length L[i]
		*@param k: An integer
		*return: The maximum length of the small pieces.
		*/
		int woodCut(vector<int> L, int k) {
			int len = L.size();
			if (len == 0) { return 0; }

			
			int maxLen = *max_element(L.begin(), L.end());
			int start = 1; 
			int end = maxLen;
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				if (pieceCount(L, mid) >= k)
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
			return start-1;
		}
     
        void Main()
        {
         
        }
    }
}
   
    