#include "stdafx.h"

//There is an integer array which has the following features :
//
//The numbers in adjacent positions are different.
//A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
//We define a position P is a peek if :
//
//A[P] > A[P - 1] && A[P] > A[P + 1]
//Find a peak element in this array.Return the index of the peak.
//
//Example
//Given[1, 2, 1, 3, 4, 5, 7, 6]
//
//Return index 1 (which is number 2) or 6 (which is number 7)
//
//Note
//The array may contains multiple peeks, find any of them.
//
//Challenge
//Time complexity O(logN)There is an integer matrix which has the following features :
//
//The numbers in adjacent positions are different.
//The matrix has n rows and m columns.
//For all i < m, A[0][i] < A[1][i] && A[n - 2][i] > A[n - 1][i].
//For all j < n, A[j][0] < A[j][1] && A[j][m - 2] > A[j][m - 1].
//We define a position P is a peek if:
//
//A[j][i] > A[j + 1][i] && A[j][i] > A[j - 1][i] && A[j][i] > A[j][i + 1] && A[j][i] > A[j][i - 1]
//Find a peak element in this matrix.Return the index of the peak.
//
//Example
//Given a matrix :
//
//[
//	[1, 2, 3, 6, 5],
//	[16, 41, 23, 22, 6],
//	[15, 17, 24, 21, 7],
//	[14, 18, 19, 20, 10],
//	[13, 14, 11, 10, 9]
//]
//return index of 41 (which is[1, 1]) or index of 24 (which is[2, 2])
//
//Note
//The matrix may contains multiple peeks, find any of them.
//
//Challenge
//Solve it in O(n + m) time.
//
//If you come up with an algorithm that you thought it is O(n log m) or O(m log n), can you prove it is actually O(n + m) or propose a similar but O(n + m) algorithm ?

namespace LintSolution1
{
    namespace FindPeakElementII_Hard
    {     

		int getColMax(vector<vector<int>>& A, int rowCount, int col)
		{			
			int row = -1;
			int maxVal = INT_MIN;
			for (int i = 0; i < rowCount; i++)
			{
				if (A[i][col] > maxVal)
				{
					maxVal = A[i][col];
					row = i;
				}
			}
			return row;
		}

		/**
		* @param A: An integer matrix
		* @return: The index of the peak
		*/
		vector<int> findPeakII(vector<vector<int> > A) {
			vector<int> result(2, -1);
			int rowCount = A.size();
			if (rowCount == 0) { return result; }
			int colCount = A[0].size();
			if (colCount == 0) { return result; }

			int start = 0;
			int end = colCount - 1;
			while (start < end)
			{
				int midCol = start + (end - start) / 2;
				int midRow = getColMax(A, rowCount, midCol);

				int midVal = A[midRow][midCol];
				int leftVal = midCol - 1 >= 0 ? A[midRow][midCol - 1] : INT_MIN;
				int rightVal = midCol + 1 < colCount ? A[midRow][midCol + 1] : INT_MIN;

				if (midVal > leftVal && midVal > rightVal) 
				{
					result[0] = midRow;
					result[1] = midCol;
					return result;
				}
				else if (midVal < rightVal)
				{
					start = midCol + 1;
				}
				else
				{
					end = midCol - 1;
				}
			}
			return result;
		}
     
        void Main()
        {
			vector<vector<int>> input = { { 1, 2, 3, 4, 5, 6 }, { 14, 15, 16, 17, 18, 8 }, { 12, 13, 11, 10, 9, 7 } };
			print(findPeakII(input));
        }
    }
}
   
    