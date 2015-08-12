#include "stdafx.h"

//Given a n, m which means the row and column of the 2D matrix and an array of pair A(size k).Originally, 
//the 2D matrix is all 0 which means there is only sea in the matrix.The list pair has k operator and each 
//operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea
//to island.Return how many island are there in the matrix after each operator.

namespace LintSolution1
{
	namespace NumberOfIslandsII_Hard
	{

		int node_id(const pair<int, int>& node, const int m) {
			return node.first * m + node.second;
		}

		int find_set(int x, unordered_map<int, int> *set) {
			if ((*set)[x] != x) {
				(*set)[x] = find_set((*set)[x], set);  // path compression.
			}
			return (*set)[x];
		}

		void union_set(unordered_map<int, int> *set, const int x, const int y) {
			int x_root = find_set(x, set), y_root = find_set(y, set);
			(*set)[min(x_root, y_root)] = max(x_root, y_root);
		}

		vector<int> numIslands2(int n, int m, vector<Point>& operators) {
			vector<int> numbers;
			int number = 0;
			const vector<pair<int, int>> directions{ { 0, -1 }, { 0, 1 },
			{ -1, 0 }, { 1, 0 } };
			unordered_map<int, int> set;
			for (const auto& oper : operators) {
				const auto& node = make_pair(oper.x, oper.y);
				set[node_id(node, m)] = node_id(node, m);

				// For each direction, count distinct islands.
				unordered_set<int> neighbors;
				for (const auto& d : directions) {
					const auto& neighbor = make_pair(oper.x + d.first,
						oper.y + d.second);
					if (neighbor.first >= 0 && neighbor.first < n &&
						neighbor.second >= 0 && neighbor.second < m &&
						set.find(node_id(neighbor, m)) != set.end()) {
						neighbors.emplace(find_set(node_id(neighbor, m), &set));
					}
				}

				// For each direction, find and union.
				for (const auto& d : directions) {
					const auto& neighbor = make_pair(oper.x + d.first,
						oper.y + d.second);
					if (neighbor.first >= 0 && neighbor.first < n &&
						neighbor.second >= 0 && neighbor.second < m &&
						set.find(node_id(neighbor, m)) != set.end()) {
						union_set(&set, node_id(node, m), node_id(neighbor, m));
					}
				}

				number += 1 - neighbors.size();
				numbers.emplace_back(number);
			}
			return numbers;
		}



		namespace tooSlow
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
		}

		void Main()
		{
			vector<Point> input = { { 1, 1 }, { 0, 1 }, { 3, 3 }, { 3, 4 } };
			print(numIslands2(4, 5, input));
		}
	}
}

