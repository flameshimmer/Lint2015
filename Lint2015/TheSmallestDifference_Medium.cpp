#include "stdafx.h"

//Given two array of integers(the first array is array A, the second array is array B), 
//now we are going to find a element in array A which is A[i], and another element in array B which is B[j], 
//so that the difference between A[i] and B[j](| A[i] - B[j] | ) is as small as possible, return their smallest difference.
//
//Example
//For example, given array A = [3, 6, 7, 4], B = [2, 8, 9, 3], return 0
//
//Challenge
//O(n log n) time

namespace LintSolution1
{
    namespace TheSmallestDifference_Medium
    {   

		int smallestDifference(vector<int> &A, vector<int> &B) {
			sort(A.begin(), A.end());
			sort(B.begin(), B.end());

			int ia = 0;
			int ib = 0;
			int minDiff = INT_MAX;
			while (ia < A.size() && ib < B.size())
			{
				minDiff = min(minDiff, abs(A[ia] - B[ib]));
				if (A[ia] < B[ib]) { ia++; }
				else { ib++; }
			}
			return minDiff;
		}


		namespace mergeWithOrigin
		{
			/**
			* @param A, B: Two integer arrays.
			* @return: Their smallest difference.
			*/
			int smallestDifference(vector<int> &A, vector<int> &B) {
				int lena = A.size();
				int lenb = B.size();

				vector<pair<int, int>> M;

				for (int v : A)
				{
					M.push_back(make_pair(v, 0));
				}
				for (int v : B)
				{
					M.push_back(make_pair(v, 1));
				}
				sort(M.begin(), M.end());

				int minDiff = INT_MAX;
				for (int i = 1; i < M.size(); i++)
				{
					if (M[i].second != M[i - 1].second)
					{
						minDiff = min(minDiff, abs(M[i].first - M[i - 1].first));
					}
				}
				return minDiff;
			}
		}
     
        void Main()
        {
         
        }
    }
}
   
    