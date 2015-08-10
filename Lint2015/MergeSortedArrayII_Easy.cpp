#include "stdafx.h"

//Merge two given sorted integer array A and B into a new sorted integer array.
//
//Example
//A = [1, 2, 3, 4]
//
//B = [2, 4, 5, 6]
//
//return[1, 2, 2, 3, 4, 4, 5, 6]
//
//Challenge
//How can you optimize your algorithm if one array is very large and the other is very small ?

namespace LintSolution1
{
    namespace MergeSortedArrayII_Easy
    {
		/**
		* @param A and B: sorted integer array A and B.
		* @return: A new sorted integer array
		*/
		vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
			int lena = A.size();
			int lenb = B.size();

			vector<int> result(lena + lenb, 0);
			copy(A.begin(), A.end(), result.begin());

			int i = lena + lenb - 1;
			int ia = lena - 1;
			int ib = lenb - 1;

			while (ib >= 0)
			{
				if (ia >= 0 && A[ia] >= B[ib])
				{
					result[i] = result[ia];
					ia--;
				}
				else
				{
					result[i] = B[ib];
					ib--;
				}
				i--;
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
   
    