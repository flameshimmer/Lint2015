#include "stdafx.h"

//Design an iterator over a binary search tree with the following rules :
//
//Elements are visited in ascending order(i.e.an in - order traversal)
//next() and hasNext() queries run in O(1) time in average.
//Example
//For the following binary search tree, in - order traversal by using iterator is[1, 6, 10, 11, 12]
//
//			10
//		  /    \
//		1       11
//	     \       \
//		  6       12
//Challenge
//Extra memory usage O(h), h is the height of the tree.
//
//Super Star : Extra memory usage O(1)

/**
* Example of iterate a tree:
* Solution iterator = Solution(root);
* while (iterator.hasNext()) {
*    TreeNode * node = iterator.next();
*    do something for node
*/
namespace LintSolution1
{
    namespace BinarySearchTreeIterator_Hard
    {
     
		class Solution {
			stack<TreeNode*> m_stack;
			TreeNode* cur;
		public:
			//@param root: The root of binary tree.
			Solution(TreeNode *root) {
				cur = root;
			}

			//@return: True if there has next node, or false
			bool hasNext() {
				return !m_stack.empty() || cur;
			}

			//@return: return next node
			TreeNode* next() {
				while (!m_stack.empty() || cur)
				{
					if (cur)
					{
						m_stack.push(cur);
						cur = cur->left;
					}
					else
					{
						TreeNode* top = m_stack.top();
						m_stack.pop();
						cur = top->right;
						return top;
					}
				}
				return NULL;
			}
		};

     
     
        void Main()
        {
         
        }
    }
}
   
    