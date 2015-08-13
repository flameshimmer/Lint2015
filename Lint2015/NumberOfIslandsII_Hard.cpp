#include "stdafx.h"

//Given a n, colCount which means the row and column of the 2D matrix and an array of pair A(size k).Originally, 
//the 2D matrix is all 0 which means there is only sea in the matrix.The list pair has k opator and each 
//opator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea
//to island.Return how many island are there in the matrix after each opator.
//
//Example
//Given n = 3, m = 3, array of pair A = [(0, 0), (0, 1), (2, 2), (2, 1)].
//
//return[1, 1, 2, 2].
//
//Note
//0 is represented as the sea, 1 is represented as the island.If two 1 is adjacent, we consider them in 
//the same island.We only consider up / down / left / right adjacent.

namespace LintSolution1
{
	namespace NumberOfIslandsII_Hard
	{
		int getId(Point& p, int colCount)
		{
			return p.x * colCount + p.y;
		}

		int findParent(unordered_map<int, int>&parent, int x)
		{
			if (parent.find(x) == parent.end()) { parent[x] = x; }
			while (x != parent[x]) { x = parent[x]; }
			return x;
		}

		vector<int> numIslands2(int rowCount, int colCount, vector<Point>& points)
		{
			vector<int> result;
			unordered_map<int, int> parent;
			vector<pair<int, int>> offsets = { make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1) };
			int count = 0;
			for (Point point : points)
			{
				int pointId = getId(point, colCount);
				int pA = findParent(parent, pointId);
				count++;
				for (auto offset : offsets)
				{
					Point nextPoint = { point.x + offset.first, point.y + offset.second };
					int nextPointId = getId(nextPoint, colCount);
					// if index out of bound or havn't seen this point before, do not process this point
					if (nextPoint.x < 0 || nextPoint.x >= rowCount || nextPoint.y < 0 || nextPoint.y >= colCount || parent.find(nextPointId) == parent.end()) { continue; }
					pA = findParent(parent, pointId);
					int pB = findParent(parent, nextPointId);
					if (pA != pB)
					{
						count--;
						parent[max(pA, pB)] = min(pA, pB);
					}
				}
				result.push_back(count);
			}
			return result;
		}


		namespace flippingTooSlow
		{
			void propagate(vector<vector<int>>& board, int row, int col, int color, int n, int colCount, unordered_set<int>& colors)
			{
				board[row][col] = color;
				colors.insert(color);

				// check four sides
				pair<int, int> offparentMap[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };

				for (int i = 0; i < 4; i++)
				{
					int nextRow = row + offparentMap[i].first;
					int nextCol = col + offparentMap[i].second;
					if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= colCount) { continue; }
					if (board[nextRow][nextCol] != 0 && board[nextRow][nextCol] != board[row][col])
					{
						colors.erase(board[nextRow][nextCol]);
						propagate(board, nextRow, nextCol, color, n, colCount, colors);
					}
				}
			}


			/**
			* @param n an integer
			* @param colCount an integer
			* @param opators an array of point
			* @return an integer array
			*/
			vector<int> numIslands2(int n, int colCount, vector<Point>& op) {
				vector<int> result;
				int len = op.size();
				if (len == 0){ return result; }
				vector<vector<int>> board(n, vector<int>(colCount, 0));
				unordered_set<int> colors;

				int color = 1;
				for (Point p : op)
				{
					int row = p.x;
					int col = p.y;
					propagate(board, row, col, color, n, colCount, colors);
					result.push_back(colors.size());
					color++;
				}
				return result;
			}
		}

		void Main()
		{
			vector<Point> input;
			input = { { 0, 0 }, { 0, 2 }, { 0, 1 } };
			print(numIslands2(1, 3, input));

			input = { { 0, 0 }, { 0, 1 }, { 2, 2 }, { 2, 1 } };
			print(numIslands2(3, 3, input));

			//input = { { 1, 1 }, { 0, 1 }, { 3, 3 }, { 3, 4 } };
			//print(numIslands2(4, 5, input));
		}
	}
}

