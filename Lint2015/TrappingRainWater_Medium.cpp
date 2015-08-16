#include "stdafx.h"


//Given n non - negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//Example
//Given[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1], return 6.
//
//Challenge
//O(n) time and O(1) memory
//
//O(n) time and O(n) memory is also acceptable.


namespace LintSolution1
{
    namespace TrappingRainWater_Medium
    {
     
		/**
		* @param heights: a vector of integers
		* @return: a integer
		*/
		int trapRainWater(vector<int> &heights) {
			int len = heights.size();
			if (len < 3) { return 0; }
			
			stack<int> s;
			int sum = 0;
			for (int i = 0; i < len; i++)
			{
				if (!s.empty() && heights[i] >= heights[s.top()])
				{
					int base = heights[s.top()];
					s.pop();

					while (!s.empty() && heights[i] >= heights[s.top()])
					{
						sum += (heights[s.top()] - base) * (i - s.top() - 1);
						base = heights[s.top()];
						s.pop();
					}
					if (!s.empty())
					{
						sum += (heights[i] - base) * (i - s.top() - 1);
					}
				}
				s.push(i);
			}
			return sum;
		}
     
/* What if 0 means leaking water??? Below are the two modified way of solving the problem:


public class TrappingRainWater {

	public int trapI(int[] A) {
		if (A == null)
			return 0;
		int len = A.length;
		if (len < 3)
			return 0;
		int[] left = new int[len];
		int right = 0, sum = 0;
		for (int i = 1; i < len; i++) {
			if (A[i] == 0)
				left[i] = 0;
			else if (left[i - 1] == 0 && A[i - 1] <= A[i])==========> leak, set left side max to 0
				left[i] = 0;
			else
				left[i] = A[i - 1] >= left[i - 1]? A[i - 1]: left[i - 1];
		}
		for (int i = len - 2; i >= 0; i--) {
			if (A[i] == 0)
				right = 0;
			else if (right == 0 && A[i] >= A[i + 1])--------------> leak, set right side max to 0
				right = 0;
			else
				right = A[i + 1] >= right? A[i + 1]: right;
			int height = left[i] <= right? left[i]: right;
			int area = A[i] >= height? 0: height - A[i];
			sum += area;
		}
		return sum;
	}
	
	public int trapII(int[] A) {
		if (A == null)
			return 0;
		int len = A.length;
		if (len < 3)
			return 0;
		Stack<Integer> stack = new Stack<Integer>();
		int sum = 0;
		for (int i = 0; i < len;) {
			if (A[i] == 0) {
				while (!stack.isEmpty()) ================> find 0, then blow away all data in the stack
					stack.pop();
				while (i < len - 1 && A[i] <= A[i + 1])
					i++; =====================================> fast forward cur index i outside from the sink
				if (i == len - 1)
					break;
				continue;
			} else {
				if (!stack.isEmpty() && A[stack.peek()] <= A[i]) {
					int base = A[stack.peek()];
					stack.pop();
					while (!stack.isEmpty() && A[stack.peek()] <= A[i]) {
						sum += (A[stack.peek()] - base) * (i - stack.peek() - 1);
						base = A[stack.pop()];
					}
					sum += stack.isEmpty()? 0: (A[i] - base) * (i - stack.peek() - 1);
				}
				stack.push(i++);	
			}
		}
		return sum;
	}
		
		*/
        void Main()
        {
         
        }
    }
}
   
    