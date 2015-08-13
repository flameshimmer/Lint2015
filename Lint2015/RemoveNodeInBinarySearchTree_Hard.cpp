#include "stdafx.h"


//Given a root of Binary Search Tree with unique value for each node.  Remove the node with given value. 
//If there is no such a node with given value in the binary search tree, do nothing. 
//You should keep the tree still a binary search tree after removal.
//
//Example
//Given binary search tree:
//
//          5
//
//       /    \
//
//    3          6
//
// /    \
//
//2       4
//
//Remove 3, you can either return:
//
//          5
//
//       /    \
//
//    2          6
//
//      \
//
//         4
//
//or :
//
//          5
//
//       /    \
//
//    4          6
//
// /   
//
//2
namespace LintSolution1
{
    namespace RemoveNodeInBinarySearchTree_Hard
    {
     
		/**
		* @param root: The root of the binary search tree.
		* @param value: Remove the node with given value.
		* @return: The root of the binary search tree after removal.
		*/
		TreeNode* removeNode(TreeNode* root, int value) {
			if (!root) { return NULL; }
			TreeNode* cur = root;
			TreeNode* parent = NULL;
			while (cur)
			{
				if (cur->val == value) { break; }
				else if (value < cur->val) { parent = cur;  cur = cur->left; }
				else { parent = cur;  cur = cur->right; }
			}
			if (!cur) { return root; }

			if (!cur->left && !cur->right)
			{
				delete cur;
				if (!parent) { return NULL; }
				if (parent->left == cur) { parent->left = NULL; }
				else { parent->right = NULL; }
				return root;
			}
			else if (!cur->left || !cur->right)
			{
				TreeNode* child = cur->left ? cur->left : cur->right;
				delete cur;
				
				if (!parent) { return child; }
				if (parent->left == cur) { parent->left = child; }
				else { parent->right = child; }
				return root;
			}
			else
			{
				TreeNode* predecessor = cur->left;
				while (predecessor->right)
				{
					predecessor = predecessor->right;
				}

				int temp = cur->val;
				cur->val = predecessor->val;
				predecessor->val = temp;
				cur->left = removeNode(cur->left, value);
				return root;
			}
		}
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(20);
			TreeNode* n2 = new TreeNode(1);
			TreeNode* n3 = new TreeNode(40);
			TreeNode* n4 = new TreeNode(35);
			
			n1->left = n2;
			n1->right = n3;
			n3->left = n4;

			removeNode(n1, 20);
         
        }
    }
}
   
    