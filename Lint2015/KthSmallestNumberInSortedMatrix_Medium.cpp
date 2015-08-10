#include "stdafx.h"

//Find the kth smallest number in at row and column sorted matrix.
//
//Example
//Given k = 4 and a matrix :
//
//[
//	[1, 5, 7],
//	[3, 7, 8],
//	[4, 8, 9],
//]
//return 5
//
//Challenge
//O(k log n), n is the maximal number in width and height.

namespace LintSolution1
{
	namespace KthSmallestNumberInSortedMatrix_Medium
	{

		namespace kLogkWithExtraSpace
		{
			struct Compare
			{
				bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
				{
					return a.first > b.first;
				}
			};


			/**
			* @param matrix: a matrix of integers
			* @param k: an integer
			* @return: the kth smallest number in the matrix
			*/
			int kthSmallest(vector<vector<int> > &matrix, int k) {
				int rowCount = matrix.size();
				if (rowCount == 0) { return -1; }
				int colCount = matrix[0].size();
				if (colCount == 0) { return -1; }

				priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> heap;
				heap.push(make_pair(matrix[0][0], make_pair(0, 0)));

				int result = -1;
				vector<bool>used(rowCount * colCount, false);
				while (!heap.empty() && k > 0)
				{
					auto p = heap.top();
					heap.pop();
					k--;

					int row = p.second.first;
					int col = p.second.second;
					if (col + 1 < colCount && !used[row*colCount + col + 1]){
						heap.push(make_pair(matrix[row][col + 1], make_pair(row, col + 1)));
						used[row*colCount + col + 1] = true;
					}
					if (row + 1 < rowCount &&  !used[(row + 1)*colCount + col]){
						heap.push(make_pair(matrix[row + 1][col], make_pair(row + 1, col)));
						used[(row + 1)*colCount + col] = true;
					}
					result = p.first;
				}
				return result;
			}
		}
		
		struct Compare
		{
			bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b)
			{
				return a.first > b.first;
			}
		};

		int kthSmallest(vector<vector<int> > &matrix, int k) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return -1; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return -1; }

			priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> heap;

			for (int i = 0; i < rowCount; i++)
			{
				heap.push(make_pair(matrix[i][0], make_pair(i, 0)));
			}

			int result = -1;
			while (!heap.empty() && k > 0)
			{
				auto p = heap.top();
				heap.pop();
				k--;
				result = p.first;

				int row = p.second.first;
				int col = p.second.second;
				if (col + 1 < colCount) { heap.push(make_pair(matrix[row][col + 1], make_pair(row, col + 1))); }
			}
			return result;		
		}
		
		void Main()
		{
			vector<vector<int>> input;

			input = {
					{ 1, 2, 3, 4, 5 },
					{ 2, 3, 4, 5, 6 },
					{ 3, 4, 5, 6, 7 },
					{ 4, 5, 6, 7, 8 }
			};
			print(kthSmallest(input, 19));

			input = {
					{ 1 },
					{ 2 },
					{ 3 },
					{ 100 },
					{ 101 },
					{ 1000 },
					{ 9999 },
			};

			print(kthSmallest(input, 5));


			input = {
					{ 1, 5, 7 },
					{ 3, 7, 8 },
					{ 4, 8, 9 },
			};

			print(kthSmallest(input, 4));

			input =
			{
				{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
				{ 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 },
				{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 },
				{ 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7 },
				{ 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 },
				{ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 }
			};
			print(kthSmallest(input, 77));
		}
	}
}

