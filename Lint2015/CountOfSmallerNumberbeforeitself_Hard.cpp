#include "stdafx.h"

//Give you an integer array(index from 0 to n - 1, where n is the size of this array, value from 0 to 10000) .
//For each element Ai in the array, count the number of element before this element Ai is smaller than it and return count number array.
//
//Example
//For array[1, 2, 7, 8, 5], return[0, 1, 2, 3, 2]
//
//Note
//We suggest you finish problem Segment Tree Build, Segment Tree Query II and Count of Smaller Number before itself I first.

namespace LintSolution1
{
    namespace CountOfSmallerNumberbeforeitself_Hard
    {
		struct Node
		{
			Node* left;
			Node* right;
			int value, leftCount;
			Node(int v)
			{
				left = right = NULL;
				value = v;
				leftCount = 0;
			}			
		};

		void insertNode(Node*& root, int a)
		{
			Node* newNode = new Node(a);
			if (!root) { root = newNode; return; }

			Node* cur = root;
			while (cur)
			{
				if (a < cur->value)
				{
					cur->leftCount++;
					if (cur->left) { cur = cur->left; }
					else { cur->left = newNode; break; }
				}
				else if (a >= cur->value)
				{
					if (cur->right) { cur = cur->right; }
					else { cur->right = newNode; break; }
				}
			}
		}

		int queryCount(Node* root, int a)
		{
			Node* cur = root;
			int count = 0;
			while (cur)
			{
				if (a < cur->value)
				{
					cur = cur->left;
				}
				else if (a > cur->value)
				{
					count += 1 + cur->leftCount;
					cur = cur->right;
				}
				else
				{
					count += cur->leftCount;
					break;
				}
			}
			return count;
		}

		vector<int> countOfSmallerNumberII(vector<int> &A) {			
			vector<int> result;
			int len = A.size();
			if (len == 0) { return result; }

			Node* root = NULL;
			for (int a : A)
			{
				insertNode(root, a);
				result.push_back(queryCount(root, a));
			}
			return result;
		}


		namespace SegmentTree{
			struct SegNode
			{
				int start, end, count, max, min;
				SegNode* left;
				SegNode* right;
				SegNode(vector<int>& A, int s, int e)
				{
					start = s;
					end = e;
					count = e - s + 1;
					max = INT_MIN;
					min = INT_MAX;
					left = right = NULL;
				}
			};

			SegNode* build(vector<int>&A, int start, int end)
			{
				if (start > end) { return NULL; }
				SegNode* newNode = new SegNode(A, start, end);
				if (start == end)
				{
					newNode->max = A[start];
					newNode->min = A[start];
					return newNode;
				}

				int mid = start + (end - start) / 2;
				newNode->left = build(A, start, mid);
				newNode->right = build(A, mid + 1, end);

				int leftMin = INT_MAX;
				int rightMin = INT_MAX;
				int leftMax = INT_MIN;
				int rightMax = INT_MIN;
				if (newNode->left) { leftMin = newNode->left->min; leftMax = newNode->left->max; }
				if (newNode->right) { rightMin = newNode->right->min; rightMax = newNode->right->max; }
				newNode->min = min(leftMin, rightMin);
				newNode->max = max(leftMax, rightMax);
				return newNode;
			}

			int countSmallerBeforeSelf(vector<int>&A, SegNode* node, int i)
			{
				if (!node || node->start >= i) { return 0; }
				if (node->max < A[i]) { return node->count; }
				if (node->min >= A[i]) { return 0; }

				int left = countSmallerBeforeSelf(A, node->left, i);
				int right = countSmallerBeforeSelf(A, node->right, i);
				return left + right;
			}

			/**
			* @param A: An integer array
			* @return: Count the number of element before this element 'ai' is
			*          smaller than it and return count number array
			*/
			vector<int> countOfSmallerNumberII(vector<int> &A) {
				vector<int> result;
				int len = A.size();
				SegNode* root = build(A, 0, len - 1);
				for (int i = 0; i < len; i++)
				{
					result.push_back(countSmallerBeforeSelf(A, root, i));
				}
				return result;
			}
		}
     
        void Main()
        {
			print(countOfSmallerNumberII(createVector({ 26, 78, 27, 100, 33, 67, 90, 23, 66, 5, 38, 7, 35, 23, 52, 22, 83, 51, 98, 69, 81, 32, 78, 28, 94, 13, 2, 97, 3, 76, 99, 51, 9, 21, 84, 66, 65, 36, 100, 41 })));
			print(countOfSmallerNumberII(createVector({ 1, 2, 7, 8, 5 })));
        }
    }
}
   
    