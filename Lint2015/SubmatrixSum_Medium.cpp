#include "stdafx.h"

//Given an integer matrix, find a submatrix where the sum of numbers is zero.
//Your code should return the coordinate of the left - up and right - down number.
//
//Example
//Given matrix
//
//[
//	[1, 5, 7],
//	[3, 7, -8],
//	[4, -8, 9],
//]
//return[(1, 1), (2, 2)]
//
//Challenge
//O(n3) time.

namespace LintSolution1
{
	namespace SubmatrixSum_Medium
	{

		vector<vector<int>> verticalScan(vector<vector<int>>& matrix, int rowCount, int colCount)
		{
			for (int i = 0; i < colCount; i++)
			{
				vector<int> tempCol(rowCount, 0);
				for (int j = i; j < colCount; j++)
				{
					for (int k = 0; k < rowCount; k++)
					{
						tempCol[k] += matrix[k][j];
					}

					int sum = 0;
					unordered_map<int, int> map; // sum, index
					map[0] = -1;
					for (int k = 0; k < rowCount; k++)
					{
						sum += tempCol[k];
						if (!map.emplace(sum, k).second)
						{
							return { { map[sum] + 1, i }, { k, j } };
						}
					}
				}
			}
			return{ { -1, -1 }, { -1, -1 } };
		}



		vector<vector<int>> horizontalScan(vector<vector<int>>& matrix, int rowCount, int colCount)
		{
			for (int i = 0; i < rowCount; i++)
			{
				vector<int> tempRow(colCount, 0);
				for (int j = i; j < rowCount; j++)
				{
					for (int k = 0; k < colCount; k++)
					{
						tempRow[k] += matrix[j][k];
					}

					unordered_map<int, int> map; // sum, index
					map[0] = -1;
					int sum = 0;
					for (int k = 0; k < colCount; k++)
					{
						sum += tempRow[k];
						if (!map.emplace(sum, k).second)
						{
							return{ {i, map[sum] +1}, {j, k} };
						}
					}
				}
			}
			return{ {-1, -1}, {-1, -1} };
		}

		/**
		* @param matrix an integer matrix
		* @return the coordinate of the left-up and right-down number
		*/
		vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
			vector<vector<int>> result = { { -1, -1 }, { 1, -1 } };
			int rowCount = matrix.size();
			if (rowCount == 0) { return result; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return result; }

			if (colCount < rowCount) { return verticalScan(matrix, rowCount, colCount); }
			else { return horizontalScan(matrix, rowCount, colCount); }
			return result;
		}

		void Main()
		{
			vector<vector<int>> matrix = { { 1, 5, 7 }, { 3, 7, -8 }, { 4, -8, 9 } };
			print(submatrixSum(matrix));
		}
	}
}

