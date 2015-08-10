#include "stdafx.h"

//Given two strings, find the longest common subsequence (LCS).
//
//Your code should return the length of LCS.
//
//
//Example
//For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.
//
//For "ABCD" and "EACB", the LCS is "AC", return 2.
//
//Clarification
//What's the definition of Longest Common Subsequence?
//
//https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
//http://baike.baidu.com/view/2020307.htm

namespace LintSolution1
{
    namespace LongestCommonSubsequence_Medium
    {
     
		/**
		* @param A, B: Two strings.
		* @return: The length of longest common subsequence of A and B.
		*/
		namespace TwoDimensionalDP
		{
			int longestCommonSubsequence(string A, string B) {
				int lena = A.size();
				int lenb = B.size();
				if (lena == 0 || lenb == 0) { return 0; }

				vector<vector<int>> M(lena + 1, vector<int>(lenb + 1, 0));
				for (int i = 1; i <= lena; i++)
				{
					for (int j = 1; j <= lenb; j++)
					{
						if (A[i - 1] == B[j - 1]) { M[i][j] = M[i - 1][j - 1] + 1; }
						else
						{
							M[i][j] = max(M[i - 1][j], M[i][j - 1]);
						}
					}
				}
				return M[lena][lenb];
			}
		}
     

		int longestCommonSubsequence(string A, string B) {
			int lena = A.size();
			int lenb = B.size();
			if (lena == 0 || lenb == 0) { return 0; }

			vector<int>M(lenb + 1, 0);
			
			for (int i = 1; i <= lena; i++)
			{
				int lastPrev = 0;
				for (int j = 1; j <= lenb; j++)
				{
					int temp = M[j];
					if (A[i - 1] == B[j - 1]) { M[j] = lastPrev + 1; }
					else
					{
						M[j] = max(M[j], M[j - 1]);
					}
					lastPrev = temp;
				}
			}
			return M[lenb];
		}

        void Main()
        {
			print(longestCommonSubsequence("ABCD", "EDCA"));
			print(longestCommonSubsequence("ABCD", "EACB"));
        }
    }
}
   
    