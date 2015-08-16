#include "stdafx.h"

//Given n x m non - negative integers representing an elevation map 2d where the area of each cell is 1 x 1, compute how much water it is able to trap after raining.

//Example
//Given 5 * 4 matrix
//
//[12, 13, 0, 12]
//[13, 4, 13, 12]
//[13, 8, 10, 12]
//[12, 13, 12, 12]
//[13, 13, 13, 13]
//return 14.

namespace LintSolution1
{
    namespace TrappingRainWaterII_Hard
    {     

		struct Cell
		{
			int row;
			int col;
			int height;
		};

		struct Compare{
			bool operator() (const Cell& a, const Cell& b)
			{
				return a.height > b.height;
			}
		};

			
		int trapRainWater(vector<vector<int> > &heights) {
			int rowCount = heights.size();
			if (rowCount == 0) { return 0; }
			int colCount = heights[0].size();
			if (colCount == 0) { return 0; }
			vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
			priority_queue<Cell, vector<Cell>, Compare> heap;

			for (int i = 0; i < rowCount; i++)
			{
				heap.push(Cell{ i, 0, heights[i][0] });
				heap.push(Cell{ i, colCount - 1, heights[i][colCount-1] });
			}

			for (int i = 0; i < colCount; i++)
			{
				heap.push(Cell{ 0, i, heights[0][i] });
				heap.push(Cell{ rowCount - 1, i, heights[rowCount - 1][i] });
			}

			int trap = 0;
			vector<pair<int, int>> offsets = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
			while (!heap.empty())
			{
				Cell c = heap.top();
				heap.pop();
				visited[c.row][c.col] = true;

				for (pair<int, int> offset : offsets)
				{
					int nextRow = c.row + offset.first;
					int nextCol = c.col + offset.second;
					if (nextRow < 0 || nextRow >= rowCount || nextCol < 0 || nextCol >= colCount || visited[nextRow][nextCol]) { continue; }
					visited[nextRow][nextCol] = true;

					heap.push(Cell{ nextRow, nextCol, max(c.height, heights[nextRow][nextCol])});
					trap += max(0, c.height - heights[nextRow][nextCol]);
				}
			}
			return trap;
		}
     
        void Main()
        {
         
        }
    }
}
   
    