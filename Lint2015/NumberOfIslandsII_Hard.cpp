#include "stdafx.h"

//Given a n, m which means the row and column of the 2D matrix and an array of pair A(size k).Originally, 
//the 2D matrix is all 0 which means there is only sea in the matrix.The list pair has k operator and each 
//operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea
//to island.Return how many island are there in the matrix after each operator.

namespace LintSolution1
{
    namespace NumberOfIslandsII_Hard
    {
     
		void propagate(vector<vector<int>>& board, int row, int col, int color, int n, int m, unordered_set<int>& colors)
		{
			board[row][col] = color;
			colors.insert(color);

			// check four sides
			pair<int, int> offset[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };

			for (int i = 0; i < 4; i++)
			{
				int nextRow = row + offset[i].first;
				int nextCol = col + offset[i].second;
				if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m) { continue; }
				if (board[nextRow][nextCol] != 0 && board[nextRow][nextCol] != board[row][col])
				{
					colors.erase(board[nextRow][nextCol]);
					propagate(board, nextRow, nextCol, color, n, m, colors);
				}
			}
		}

		/**
		* @param n an integer
		* @param m an integer
		* @param operators an array of point
		* @return an integer array
		*/
		vector<int> numIslands2(int n, int m, vector<Point>& op) {
			vector<int> result;
			int len = op.size();
			if (len == 0){ return result; }
			vector<vector<int>> board(n, vector<int>(m, 0));
			unordered_set<int> colors;

			int color = 1;
			for (Point p : op)
			{
				int row = p.x;
				int col = p.y;
				propagate(board, row, col, color, n, m, colors);
				result.push_back(colors.size());
				color++;
			}
			return result;
		}
     
        void Main()
        {
			vector<Point> input = { { 1, 1 }, { 0, 1 }, { 3, 3 }, { 3, 4 } };
			print(numIslands2(4, 5, input));         
        }
    }
}
   
    