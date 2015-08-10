#include "stdafx.h"


//Given two strings, find the longest common substring.
//
//Return the length of it.
//
//Example
//Given A = "ABCD", B = "CBCE", return 2.
//
//Note
//The characters in substring should occur continuously in original string.This is different with subsequence.
//
//Challenge
//O(n x m) time and memory.

namespace LintSolution1
{
    namespace LongestCommonSubstring_Medium
    {     
		/**
		* @param A, B: Two string.
		* @return: the length of the longest common substring.
		*/
		int longestCommonSubstring(string &A, string &B) {
			int lena = A.length();
			int lenb = B.length();
			if (lena == 0 || lenb == 0) { return 0; }
			
			vector<int>M(lenb + 1, 0);
			int maxVal = 0;
			for (int i = 1; i <= lena; i++)
			{
				int lastPrev = 0;
				for (int j = 1; j <= lenb; j++)
				{
					int temp = M[j];
					if (A[i - 1] == B[j - 1]) { M[j] = lastPrev + 1; }
					else { M[j] = 0; }
					lastPrev = temp;
					maxVal = max(maxVal, M[j]);
				}
			}
			return maxVal;
		}
     
        void Main()
        {
			string A, B;
			A = "www.lintcode.com code";
			B = "www.ninechapter.com code";
			//print(longestCommonSubstring(A, B));

			A = "asblasdbladjbadjab";
			B = "asb";
			print(longestCommonSubstring(A, B));
        }
    }
}
   
    