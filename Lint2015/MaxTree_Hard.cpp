#include "stdafx.h"

//Given an integer array with no duplicates. A max tree building on this array is defined as follow:
//
//The root is the maximum number in the array
//The left subtree and right subtree are the max trees of the subarray divided by the root number.
//Construct the max tree by the given array.
//
//Example
//Given [2, 5, 6, 0, 3, 1], the max tree constructed by this array is:
//
//    6
//   / \
//  5   3
// /   / \
//2   0   1
//
//Challenge
//O(n) time and memory.

namespace LintSolution1
{
    namespace MaxTree_Hard
    {     
		/**
		* @param A: Given an integer array with no duplicates.
		* @return: The root of max tree.
		*/
		TreeNode* maxTree(vector<int> A) {
			int len = A.size();
			if (len == 0) { return NULL; }

			stack<TreeNode*> stack;
			stack.push(new TreeNode(A[0]));

			for (int i = 1; i < len; i++)
			{
				int cur = A[i];
				if (cur <= stack.top()->val)
				{
					stack.push(new TreeNode(cur));
				}
				else
				{
					TreeNode* node = stack.top();
					stack.pop();
					while (!stack.empty() && cur > stack.top()->val)
					{
						stack.top()->right = node;
						node = stack.top();
						stack.pop();
					}
					TreeNode* newNode = new TreeNode(cur);
					newNode->left = node;
					stack.push(newNode);
				}
			}

			TreeNode* node = stack.top();
			stack.pop();
			while (!stack.empty())
			{
				stack.top()->right = node;
				node = stack.top();
				stack.pop();
			}
			return node;
		}
     
        void Main()
        {
         
        }
    }
}
   
    