#include "stdafx.h"

//Given a binary search tree and a new tree node, insert the node into the tree. 
//You should keep the tree still be a valid binary search tree.
//
//Example
//Given binary search tree as follow, after Insert node 6, the tree should be:
//
//  2             2
// / \           / \
//1   4   -->   1   4
//   /             / \ 
//  3             3   6
//
//Challenge
//Can you do it without recursion?

namespace LintSolution1
{
    namespace InsertNodeInABinarySearchTree_Easy
    {     
		/**
		* @param root: The root of the binary search tree.
		* @param node: insert this node into the binary search tree
		* @return: The root of the new binary search tree.
		*/
		TreeNode* insertNode(TreeNode* root, TreeNode* node) {
			if (!root) { return node; }

			TreeNode* cur = root;
			while (cur)
			{
				if (node->val < cur->val)
				{
					if (cur->left) { cur = cur->left; }
					else { cur->left = node; break; }
				}
				else
				{
					if (cur->right) { cur = cur->right; }
					else { cur->right = node; break; }
				}
			}
			return root;
		}

		namespace recursion
		{
			void insertImpl(TreeNode*& root, TreeNode* node)
			{
				if (!root) { root = node; return;}

				if (node->val < root->val) { insertImpl(root->left, node); }
				else { insertImpl(root->right, node); }
			}

			TreeNode* insertNode(TreeNode* root, TreeNode* node) {
				insertImpl(root, node);
				return root;
			}

		}
     
        void Main()
        {
         
        }
    }
}
   
    