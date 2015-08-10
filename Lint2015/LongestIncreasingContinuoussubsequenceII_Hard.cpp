#include "stdafx.h"

//Give you an integer matrix(with row size n, column size m)，find the longest increasing continuous subsequence in this matrix. 
//(The definition of the longest increasing continuous subsequence here can start at any row or column and go up / down / right / left any direction).
//
//Example
//Given a matrix :
//
//[
//	[1,  2,  3,  4,  5],
//	[16, 17, 24, 23, 6],
//	[15, 18, 25, 22, 7],
//	[14, 19, 20, 21, 8],
//	[13, 12, 11, 10, 9]
//]
//return 25
//
//Challenge
//O(nm) time and memory.

namespace LintSolution1
{
    namespace LongestIncreasingContinuoussubsequenceII_Hard
    {     
		int dfs(vector<vector<int>>& A, int row, int col, int rowCount, int colCount, vector<vector<int>>& cache)
		{
			if (cache[row][col] > 0) { return cache[row][col]; }

			vector<pair<int, int>> dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

			for (int i = 0; i < 4; i++)
			{	
				int nextRow = row + dir[i].first;
				int nextCol = col + dir[i].second;
				if (nextRow >= 0 && nextRow < rowCount && nextCol >= 0 && nextCol < colCount && A[nextRow][nextCol] > A[row][col])
				{
					cache[row][col] = max(cache[row][col], dfs(A, nextRow, nextCol, rowCount, colCount, cache));
				}				
			}
			cache[row][col]++;
			return cache[row][col];
		}

		/**
		* @param A an integer matrix
		* @return  an integer
		*/
		int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
			int rowCount = A.size();
			if (rowCount == 0) { return 0; }
			int colCount = A[0].size();
			if (colCount == 0) { return 0; }

			int result = 0;
			vector<vector<int>> cache(rowCount, vector<int>(colCount, 0));
			for (int i = 0; i < rowCount; i++)
			{
				for (int j = 0; j < colCount; j++)
				{
					result = max(result, dfs(A, i, j, rowCount, colCount, cache));
				}
			}
			print(cache);
			return result;
		}
     
        void Main()
        {
			vector<vector<int>> input = { { 1, 2, 3, 4, 5 }, { 16, 17, 24, 23, 6 }, { 15, 18, 25, 22, 7 }, { 14, 19, 20, 21, 8 }, { 13, 12, 11, 10, 9 } };
			print(longestIncreasingContinuousSubsequenceII(input));		
        }
    }
}
   
    