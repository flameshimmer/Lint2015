#include "stdafx.h"

//You have two every large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. 
//Create an algorithm to decide if T2 is a subtree of T1.
//
//Have you met this question in a real interview? Yes
//Example
//T2 is a subtree of T1 in the following case:
//
//       1                3
//      / \              / 
//T1 = 2   3      T2 =  4
//        /
//       4
//T2 isn't a subtree of T1 in the following case:
//
//       1               3
//      / \               \
//T1 = 2   3       T2 =    4
//        /
//       4
//Note
//A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. 
//That is, if you cut off the tree at node n, the two trees would be identical.

namespace LintSolution1
{
	namespace Subtree_Easy
	{

		bool isSameTree(TreeNode* T1, TreeNode* T2)
		{
			if (!T1 && !T2) { return true; }
			if (!T1 || !T2) { return false; }
			return (T1->val == T2->val) && isSameTree(T1->left, T2->left) && isSameTree(T1->right, T2->right);
		}

		/**
		* @param T1, T2: The roots of binary tree.
		* @return: True if T2 is a subtree of T1, or false.
		*/
		bool isSubtree(TreeNode *T1, TreeNode *T2) {
			if (!T1 && !T2) { return true; }
			if (!T1 || !T2) { return !T2 ? true : false; }

			return isSameTree(T1, T2) || isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
		}
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(1);
			TreeNode* n2 = new TreeNode(2);
			TreeNode* n3 = new TreeNode(3);
			TreeNode* n4 = new TreeNode(4);
			n1->left = n2;
			n1->right = n3;
			n3->left = n4;

			TreeNode* n3_2 = new TreeNode(3);
			TreeNode* n4_2 = new TreeNode(4);
			n3_2->left = n4_2;
        
			print(isSubtree(n1, n3_2));
		}
    }
}
   
    