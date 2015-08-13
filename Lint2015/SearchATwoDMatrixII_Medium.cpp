#include "stdafx.h"

//Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
//
//This matrix has the following properties :
//
//*Integers in each row are sorted from left to right.
//
//* Integers in each column are sorted from up to bottom.
//
//* No duplicate integers in each row or column.
//
//Example
//Consider the following matrix :
//
//[
//
//	[1, 3, 5, 7],
//
//	[2, 4, 7, 8],
//
//	[3, 5, 9, 10]
//
//]
//
//Given target = 3, return 2.
//
//Challenge
//O(m + n) time and O(1) extra space

namespace LintSolution1
{
    namespace SearchATwoDMatrixII_Medium
    {
     
		/**
		* @param matrix: A list of lists of integers
		* @param target: An integer you want to search in matrix
		* @return: An integer indicate the total occurrence of target in the given matrix
		*/
		int searchMatrix(vector<vector<int> > &matrix, int target) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return 0; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return 0; }

			int count = 0;
			int row = 0;
			int col = colCount - 1;
			// start from right top corner, note that col can only decrease, row can only increase
			while (row < rowCount && col >= 0)
			{
				int curVal = matrix[row][col];
				if (curVal == target)
				{
					row++;
					col--;
					count++;
				}
				else if (curVal > target)
				{
					col--;
				}
				else
				{
					row++;
				}
			}
			return count;
		}
     
        void Main()
        {
			vector<vector<int> > matrix = { { 3, 4 } };
			print(searchMatrix(matrix, 3));
        }
    }
}
   
    