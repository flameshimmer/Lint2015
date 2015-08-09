#include "stdafx.h"

//Given an integer array, heapify it into a min - heap array.
//
//For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].
//
//Example
//Given[3, 2, 1, 4, 5], return[1, 2, 3, 4, 5] or any legal heap array.
//
//Challenge
//O(n) time complexity
//
//Clarification
//What is heap ?
//
//Heap is a data structure, which usually have three methods : push, pop and top.where "push" add a new element the heap, "pop" delete the minimum / maximum element in the heap, "top" return the minimum / maximum element.
//
//What is heapify ?
//Convert an unordered integer array into a heap array.If it is min - heap, for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].
//
//What if there is a lot of solutions ?
//Return any of them.

namespace LintSolution1
{
    namespace Heapify_Medium
    {
     
		void siffDown(vector<int>& A, int i, int len)
		{
			if (2 * i + 1 >= len) { return; }
			int targetChild = 0;
			if (2*i + 2 >= len) { targetChild = 2*i + 1; }
			else {
				targetChild = A[2*i + 1] > A[2*i + 2] ? 2*i + 2 : 2*i + 1;
			}

			if (A[targetChild] < A[i]) 
			{
				swap(A[i], A[targetChild]);
				siffDown(A, targetChild, len);
			}
		}

		/**
		* @param A: Given an integer array
		* @return: void
		*/
		void heapify(vector<int> &A) {
			int len = A.size();
			for (int i = len/2-1; i >= 0; i--)
			{
				siffDown(A, i, len);
			}
		}
     
        void Main()
        {
			vector<int> input = { 3, 2, 1, 4, 5 };
			heapify(input);
			print(input);
        }
    }
}
   
    