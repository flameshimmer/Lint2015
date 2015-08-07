#include "stdafx.h"

//Give you an integer array(index from 0 to n - 1, where n is the size of this array, value from 0 to 10000)
//and an query list.For each query, give you an integer, return the number of element in the array that are smaller that the given integer.
//
//Example
//For array[1, 2, 7, 8, 5], and queries[1, 8, 5], return[0, 4, 2]
//
//Note
//We suggest you finish problem Segment Tree Build and Segment Tree Query II first.
//
//Challenge
//Could you use three ways to do it.
//
//Just loop
//Sort and binary search
//Build Segment Tree and Search.


namespace LintSolution1
{
    namespace CountOfSmallerNumber_Medium
    {
		
		struct SegNode
		{
			int start, end, count;
			SegNode* left;
			SegNode* right;

			SegNode(vector<int>& A, int s, int e)
			{
				start = A[s];
				end = A[e];
				count = e - s + 1;
				left = right = NULL;
			}
		};

		SegNode* build(vector<int>& A, int start, int end)
		{			
			if (start > end) { return NULL; }
			SegNode* newNode = new SegNode(A, start, end);
			if (start == end) { return newNode; }

			int mid = start + (end - start) / 2;
			newNode->left = build(A, start, mid);
			newNode->right = build(A, mid + 1, end);
			return newNode;
		}

		int getSmallerThan(SegNode* node, int q)
		{
			if (!node || q <= node->start) { return 0; }
			if (q > node->end) { return node->count; }

			int left = getSmallerThan(node->left, q);
			int right = getSmallerThan(node->right, q);
			return left + right;
		}

		/**
		* @param A: An integer array
		* @return: The number of element in the array that
		*          are smaller that the given integer
		*/
		vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
			sort(A.begin(), A.end());
			SegNode* root = build(A, 0, A.size() - 1);
			vector<int> result;
			
			for (int q : queries)
			{
				result.push_back(getSmallerThan(root, q));
			}
			return result;
		}




		namespace JustLoop
		{
			vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
				vector<int> result;

				for (int q : queries)
				{
					int count = 0;
					for (int v : A)
					{
						if (v < q) { count++; }
					}
					result.push_back(count);
				}
				return result;
			}
		}

		namespace SortAndBinarySearch		
		{
			vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
				vector<int> result;
				sort(A.begin(), A.end());
				int len = A.size();
				for (int q : queries)
				{
					int start = 0;
					int end = len - 1; 
					while (start <= end)
					{
						int mid = start + (end - start) / 2;
						if (A[mid] < q)
						{
							start = mid + 1;
						}
						else
						{
							end = mid - 1;
						}
					}
					result.push_back(start);
				}
				return result;
			}
		}
     
        void Main()
        {
			print(countOfSmallerNumber(createVector({ 1, 2, 7, 8, 5 }), createVector({ 1, 8, 5 })));
			print(SortAndBinarySearch::countOfSmallerNumber(createVector({ 1, 2, 7, 8, 5 }), createVector({ 1, 8, 5 })));
        }
    }
}
   
    