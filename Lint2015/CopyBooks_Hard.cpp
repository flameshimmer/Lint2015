#include "stdafx.h"

//Given an array A of integer with size of n(means n books and number of pages of each book) and k people to copy the book.
//You must distribute the continuous id books to one people to copy. (You can give book A[1], A[2] to one people, 
//but you cannot give book A[1], A[3] to one people, because book A[1] and A[3] is not continuous.) 
//Each person have can copy one page per minute.Return the number of smallest minutes need to copy all the books.
//
//Example
//Given array A = [3, 2, 4], k = 2.
//
//Return 5(First person spends 5 minutes to copy book 1 and book 2 and second person spends 4 minutes to copy book 3.)
//
//Challenge
//Could you do this in O(n*k) time ?

namespace LintSolution1
{
    namespace CopyBooks_Hard
    {
		bool valid(vector<int>& pages, int k, int x)
		{
			int people = 0;
			int sum = 0;
			int len = pages.size();

			for (int i = 0; i < len && people < k; i++)
			{
				if (sum + pages[i] > x)
				{
					sum = 0;
					people++;
				}
				sum += pages[i];
			}
			return people < k && sum <= x;
		}

		int binarySearch(vector<int>& pages, int k, int start, int end)
		{
			while (start <= end)
			{
				int mid = start + (end - start) / 2;
				if (valid(pages, k, mid))
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			return start;
		}
     
		/**
		* @param pages: a vector of integers
		* @param k: an integer
		* @return: an integer
		*/
		int copyBooks(vector<int> &pages, int k) {
			int len = pages.size();
			if (k >= len)
			{
				return *max_element(pages.begin(), pages.end());
			}

			int sum = 0;
			for (int page : pages)
			{
				sum += page;
			}

			if (k == 1) { return sum; }

			int average = sum / k;
			return binarySearch(pages, k, average, sum);
		}

        void Main()
        {
			//print(copyBooks(createVector({ 3, 2, 4 }), 2));
			print(copyBooks(createVector({ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }), 6));
        }
    }
}
   
    