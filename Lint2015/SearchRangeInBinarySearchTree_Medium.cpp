#include "stdafx.h"

//Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. 
//Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and 
//x is a key of given BST. Return all the keys in ascending order.
//
//Example
//If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].
//
//    20
//   /  \
//  8   22
// / \
//4   12

namespace LintSolution1
{
    namespace SearchRangeInBinarySearchTree_Medium
    {     

		namespace recursive
		{
			void search(TreeNode* root, int k1, int k2, vector<int>& result)
			{
				if (!root) { return; }
				if (root->val >= k1 && root->val <= k2)
				{
					search(root->left, k1, k2, result);
					result.push_back(root->val);
					search(root->right, k1, k2, result);
				}
				else if (root->val < k1)
				{
					search(root->right, k1, k2, result);
				}
				else
				{
					search(root->left, k1, k2, result);
				}
			}
			/**
			* @param root: The root of the binary search tree.
			* @param k1 and k2: range k1 to k2.
			* @return: Return all keys that k1<=key<=k2 in ascending order.
			*/
			vector<int> searchRange(TreeNode* root, int k1, int k2) {
				vector<int> result;
				search(root, k1, k2, result);
				return result;
			}
		}
     
		namespace iterative1
		{
			vector<int> searchRange(TreeNode* root, int k1, int k2) {
				vector<int> result;

				TreeNode* cur = root;
				stack<TreeNode*> s;

				while (!s.empty() || cur)
				{
					if (cur)
					{
						s.push(cur);
						cur = cur->left;
					}
					else
					{
						TreeNode* top = s.top();
						s.pop();
						if (top->val >= k1 && top->val <= k2) { result.push_back(top->val); }
						cur = top->right;
					}
				}
				return result;
			}
		}


		void pushLeft(stack<TreeNode*>&s, TreeNode* root, int k1)
		{
			while (root)
			{
				s.push(root);
				if (root->val < k1) { break; }
				root = root->left;
			}
		}

		vector<int> searchRange(TreeNode* root, int k1, int k2) {
			vector<int> result;
			stack<TreeNode*> s;

			pushLeft(s, root, k1);
			while (!s.empty())
			{
				TreeNode* top = s.top();
				s.pop();

				if (top->val >= k1 && top->val <= k2)
				{
					result.push_back(top->val);
				}

				if (top->val <= k2) // note here
				{
					pushLeft(s, top->right, k1); // top's right, not root's right
				}
			}
			return result;
		}

        void Main()
        {
			TreeNode* n1 = new TreeNode(2);
			TreeNode* n2 = new TreeNode(1);
			n1->left = n2;
			print(searchRange(n1, 0, 4));
        }
    }
}
   
    