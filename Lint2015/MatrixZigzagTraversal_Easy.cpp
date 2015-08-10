#include "stdafx.h"

//Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in ZigZag - order.
//
//Example
//Given a matrix :
//
//[
//	[1, 2,  3,  4 ],
//	[5, 6,  7,  8 ],
//	[9, 10, 11, 12]
//]
//return[1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]

namespace LintSolution1
{
    namespace MatrixZigzagTraversal_Easy
    {     
		/**
		* @param matrix: a matrix of integers
		* @return: a vector of integers
		*/
		vector<int> printZMatrix(vector<vector<int> > &matrix) {
			vector<int> result;
			int rowCount = matrix.size();
			if (rowCount == 0) { return result; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return result; }

			int row = 0;
			int col = 0;
			int count = rowCount * colCount;
			result.push_back(matrix[0][0]);
			count--;
			while (count > 0)
			{
				while (count > 0 && row - 1 >= 0 && col + 1 < colCount)
				{
					row--;
					col++;
					result.push_back(matrix[row][col]);
					count--;
				}

				if (count > 0)
				{
					if (col + 1 < colCount){ col++; }
					else { row++; }
					result.push_back(matrix[row][col]);
					count--;
				}


				while (count > 0 && row + 1 < rowCount && col - 1 >= 0)
				{
					row++;
					col--;
					result.push_back(matrix[row][col]);
					count--;
				}

				if (count > 0)
				{
					if (row + 1 < rowCount) { row++; }
					else { col++; }
					result.push_back(matrix[row][col]);
					count--;
				}
			}
			return result;
		}
     
        void Main()
        {
			vector<vector<int>> input = {
					{ 1, 2, 3, 4 },
					{ 5, 6, 7, 8 },
					{ 9, 10, 11, 12 }
			};

			print(printZMatrix(input));
        }
    }
}
   
    