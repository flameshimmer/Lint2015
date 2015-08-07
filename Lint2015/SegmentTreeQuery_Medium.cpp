#include "stdafx.h"

//For an integer array (index from 0 to n-1, where n is the size of this array), in the corresponding SegmentTree, 
//each node stores an extra attribute max to denote the maximum number in the interval of the array (index from start to end).
//
//Design a query method with three parameters root, start and end, find the maximum number in the interval [start, end] by the given root of segment tree.
//
//Example
//For array [1, 4, 2, 3], the corresponding Segment Tree is:
//
//                  [0, 3, max=4]
//                 /             \
//          [0,1,max=4]        [2,3,max=3]
//          /         \        /         \
//   [0,0,max=1] [1,1,max=4] [2,2,max=2], [3,3,max=3]
//
//query(root, 1, 1), return 4
//
//query(root, 1, 2), return 4
//
//query(root, 2, 3), return 3
//
//query(root, 0, 2), return 4
//
//Note
//It is much easier to understand this problem if you finished Segment Tree Build first.
namespace LintSolution1
{
    namespace SegmentTreeQuery_Medium
    {    
		//Definition of SegmentTreeNode:
		class SegmentTreeNode {
		public:
			int start, end, max;
			SegmentTreeNode *left, *right;
			SegmentTreeNode(int start, int end, int max) {
				this->start = start;
				this->end = end;
				this->max = max;
				this->left = this->right = NULL;
			}
		};

		/**
		*@param root, start, end: The root of segment tree and
		*                         an segment / interval
		*@return: The maximum number in the interval [start, end]
		*/
		int query(SegmentTreeNode *root, int start, int end) {
			if (!root || end<root->start || start > root->end) { return INT_MIN; }

			if (root->start >= start && root->end <= end) { return root->max; }

			int left = query(root->left, start, end);
			int right = query(root->right, start, end);
			return max(left, right);
		}
     
        void Main()
        {
			SegmentTreeNode* n1 = new SegmentTreeNode(0, 3, 4);
			SegmentTreeNode* n2 = new SegmentTreeNode(0, 1, 4);
			SegmentTreeNode* n3 = new SegmentTreeNode(2, 3, 3);
			SegmentTreeNode* n4 = new SegmentTreeNode(0, 0, 1);
			SegmentTreeNode* n5 = new SegmentTreeNode(1, 1, 4);
			SegmentTreeNode* n6 = new SegmentTreeNode(2, 2, 2);
			SegmentTreeNode* n7 = new SegmentTreeNode(3, 3, 3);

			n1->left = n2;
			n1->right = n3;

			n2->left = n4;
			n2->right = n5;

			n3->left = n6;
			n3->right = n7;

			print(query(n1, 1, 1));
			print(query(n1, 1, 2));
			print(query(n1, 2, 3));
			print(query(n1, 0, 2));
        }
    }
}
   
    