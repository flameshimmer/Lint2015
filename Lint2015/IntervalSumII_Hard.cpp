#include "stdafx.h"

//Given an integer array in the construct method, implement two methods query(start, end) and modify(index, value) :
//
//For query(start, end), return the sum from index start to index end in the given array.
//For modify(index, value), modify the number in the given index to value
//
//Example
//Given array A = [1, 2, 7, 8, 5].
//
//query(0, 2), return 10.
//modify(0, 4), change A[0] from 1 to 4.
//query(0, 1), return 6.
//modify(2, 1), change A[2] from 7 to 1.
//query(2, 4), return 14.
//
//Note
//We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.
//
//Challenge
//O(logN) time for query and modify.

namespace LintSolution1
{
    namespace IntervalSumII_Hard
    { 
		class Solution {
		public:
			/* you may need to use some attributes here */
			struct Node{
				int start, end;
				long long sum;
				Node* left;
				Node* right;
				Node(int s, int e)
				{
					start = s;
					end = e;
					left = right = NULL;
					sum = 0;
				}
			};
			
			Node* build(vector<int>& A, int start, int end)
			{
				if (start > end) { return NULL; }
				Node* newNode = new Node(start, end);
				if (start == end) { newNode->sum = A[start]; return newNode;}

				int mid = start + (end - start) / 2;
				newNode->left = build(A, start, mid);
				newNode->right = build(A, mid + 1, end);

				newNode->sum = (newNode->left ? newNode->left->sum : 0) + (newNode->right ? newNode->right->sum : 0);
				return newNode;
			}

			long long query(Node* node, int start, int end)
			{
				if (!node || end < node->start || start > node->end) { return 0; }

				if (start <= node->start && node->end <= end) { return node->sum; }
				return query(node->left, start, end) + query(node->right, start, end);
			}

			void modify(Node* node, int index, int value)
			{
				if (!node || index < node->start || index > node->end) { return; }
				if (node->start == index && node->end == index)
				{
					node->sum = value;
					return;
				}

				modify(node->left, index, value);
				modify(node->right, index, value);
				node->sum = (node->left ? node->left->sum : 0) + (node->right ? node->right->sum : 0);
			}

			Node* root;
			/**
			* @param A: An integer vector
			*/
			Solution(vector<int> A) {
				int len = A.size();
				if (len == 0) { root = NULL;}
				else {
					root = build(A, 0, len - 1);
				}
			}

			/**
			* @param start, end: Indices
			* @return: The sum from start to end
			*/
			long long query(int start, int end) {
				return query(root, start, end);
			}

			/**
			* @param index, value: modify A[index] to value.
			*/
			void modify(int index, int value) {
				return modify(root, index, value);
			}
		};


        void Main()
        {
			vector<int> A = { 1, 2, 7, 8, 5 };
			Solution* sol = new Solution(A);
			print(sol->query(0, 2));
			sol->modify(0, 4);
			print(sol->query(0, 1));
			sol->modify(2, 1);
			print(sol->query(2, 4));
        }
    }
}
   
    