#include "stdafx.h"

//Given two sorted integer arrays A and B, merge B into A as one sorted array.
//
//Have you met this question in a real interview ? Yes
//Example
//A = [1, 2, 3, empty, empty], B = [4, 5]
//
//After merge, A will be filled as[1, 2, 3, 4, 5]
//
//Note
//
//You may assume that A has enough space(size that is greater or equal to m + n) to hold additional elements from B.
//The number of elements initialized in A and B are m and n respectively.

namespace LintSolution1
{
    namespace MergeSortedArray_Easy
    {
		void mergeSortedArray(int A[], int m, int B[], int n) {
			int i = m + n - 1;
			int ia = m - 1;
			int ib = n - 1;
			while (ib >= 0)
			{
				if (ia >= 0 && A[ia] >= B[ib])
				{
					A[i] = A[ia];
					ia--;
				}
				else
				{
					A[i] = B[ib];
					ib--;
				}
				i--;
			}
		}
     
        void Main()
        {
         
        }
    }
}
   
    