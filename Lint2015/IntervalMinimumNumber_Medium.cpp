#include "stdafx.h"

//Given an integer array(index from 0 to n - 1, where n is the size of this array), and an query list.
//Each query has two integers[start, end].For each query, calculate the minimum number between index 
//start and end in the given array, return the result list.
//
//Example
//For array[1, 2, 7, 8, 5], and queries[(1, 2), (0, 4), (2, 4)], return[2, 1, 5]
//
//Note
//We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.
//
//Challenge
//O(logN) time for each query

namespace LintSolution1
{
    namespace IntervalMinimumNumber_Medium
    {
     
		struct Node
		{
			int start, end, min;
			Node* left;
			Node* right;
			Node(int s, int e)
			{
				start = s;
				end = e;
				left = right = NULL;
				min = INT_MAX;
			}
		};

		Node* build(vector<int>& A, int start, int end)
		{
			if (start > end) { return NULL; }
			Node* newNode = new Node(start, end);
			if (start == end) { newNode->min = A[start]; return newNode; }

			int mid = start + (end - start) / 2;
			newNode->left = build(A, start, mid);
			newNode->right = build(A, mid + 1, end);
			newNode->min = min(newNode->left ? newNode->left->min : INT_MAX, newNode->right ? newNode->right->min : INT_MAX);
			return newNode;
		}

		int query(Node* root, int start, int end)
		{
			if (!root || end < root->start || start > root->end) { return INT_MAX; }

			if (root->start >= start && root->end<= end) { return root->min; }

			int left = query(root->left, start, end);
			int right = query(root->right, start, end);
			int result =  min(left, right);
			return result;
		}


		/**
		*@param A, queries: Given an integer array and an query list
		*@return: The result list
		*/
		vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
			vector<int> result;
			int len = A.size();
			if (len == 0) { return result; }

			Node* root = build(A, 0, len - 1);
			for (Interval q : queries)
			{
				result.push_back(query(root, q.start, q.end));
			}
			return result;
		}
     
     
        void Main()
        {
			vector<int> A = { 1, 2, 7, 8, 5 };
			vector<Interval> queries = { {1, 2}, {0, 4}, {2, 4} };
			print(intervalMinNumber(A, queries));
        }
    }
}
   
    