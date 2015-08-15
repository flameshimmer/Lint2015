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
		/**
		* @param matrix an integer matrix
		* @return the coordinate of the left-up and right-down number
		*/
		vector<vector<int>> submatrixSum(vector<vector<int>>& matrix) {
			vector<vector<int>> res;
			int rowCount = matrix.size();
			if (0 == rowCount) return res;
			int colCount = matrix[0].size();

			for (int i = 0; i < colCount; i++) 
			{  
				// for every column
				vector<int> sum(rowCount, 0);
				for (int j = i; j < colCount; j++) 
				{ 
					// for every subsequent column  
					for (int k = 0; k < rowCount; k++)
					{
						sum[k] += matrix[k][j];  // sum up k row's col i~j's value
					}

					int lastSum = 0;
					unordered_map<int, int> map;  // sum, index
					map[0] = -1;
					for (int v = 0; v < rowCount; v++) // for every row 
					{  
						lastSum += sum[v];  // calc the sub matrix sum
						if (map.count(lastSum)) 
						{  // if see this sum before, then return the index zone
							res.push_back(vector<int>({ map[lastSum] + 1, i }));
							res.push_back(vector<int>({ v, j }));
							return res;
						}
						map[lastSum] = v;  // remember sum, index pair
					}
				}
			}
			return res;
		}
	}

	void Main()
	{

	}
}
}

