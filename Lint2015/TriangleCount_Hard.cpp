#include "stdafx.h"

//Given an array of integers, how many three numbers can be found in the array, 
//so that we can build an triangle whose three edges length is the three numbers that we find ?
//
//Example
//Given array S = [3, 4, 6, 7], return 3. They are :
//
//[3, 4, 6]
//[3, 6, 7]
//[4, 6, 7]
//Given array S = [4, 4, 4, 4], return 4. They are :
//
//[4(1), 4(2), 4(3)]
//[4(1), 4(2), 4(4)]
//[4(1), 4(3), 4(4)]
//[4(2), 4(3), 4(4)]


namespace LintSolution1
{
    namespace TriangleCount_Hard
    {     
		/**
		* @param S: A list of integers
		* @return: An integer
		*/
		int triangleCount(vector<int> &S) {
			int len = S.size();
			sort(S.begin(), S.end());
			int count = 0;

			for (int i = len - 1; i >= 2; i--)
			{
				int start = 0;
				int end = i - 1;
				while (start < end)
				{
					if (S[start] + S[end] <= S[i])
					{
						start++;
					}
					else
					{
						count += end - start; // end - start + 1 - 1;
						end--;
					}
				}
			}
			return count;
		}
     
        void Main()
        {
         
        }
    }
}
   
    