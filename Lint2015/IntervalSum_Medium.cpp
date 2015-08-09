#include "stdafx.h"

//Given an integer array(index from 0 to n - 1, where n is the size of this array), 
//and an query list.Each query has two integers[start, end].For each query, calculate
//the sum number between index start and end in the given array, return the result list.
//Example
//For array[1, 2, 7, 8, 5], and queries[(0, 4), (1, 2), (2, 4)], return[23, 9, 20]
//
//Note
//We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.
//
//Challenge
//O(logN) time for each query


namespace LintSolution1
{
    namespace IntervalSum_Medium
    {
		struct Node{
			int start, end;
			long long sum;
			Node* left;
			Node* right;
			Node(int s, int e){
				left = right = NULL;
				start = s;
				end = e;
				sum = 0;
			}
		};

		Node* build(vector<int>& A, int start, int end)
		{
			if (start > end) { return NULL; }
			Node* newNode = new Node(start, end);
			if (start == end) { newNode->sum = A[start]; return newNode; }

			int mid = start + (end - start) / 2;
			newNode->left = build(A, start, mid);
			newNode->right = build(A, mid + 1, end);

			newNode->sum = (newNode->left ? newNode->left->sum : 0) + (newNode->right ? newNode->right->sum : 0);
			return newNode;
		}

		long long query(Node* node, int start, int end)
		{
 			if (!node || node->start > end || node->end < start) { return 0; }
			if (start <= node->start && node->end <= end) { return node->sum; }

			return query(node->left, start, end) + query(node->right, start, end);		
		}

		/**
		*@param A, queries: Given an integer array and an query list
		*@return: The result list
		*/
		vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
			vector<long long> result;
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
			vector<Interval> queries = { { 1, 2 }, { 0, 4 }, { 2, 4 } };
			print(intervalSum(A, queries));
        }

    }
}
   
    