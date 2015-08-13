#include "stdafx.h"

//Given a set of n nuts of different sizes and n bolts of different sizes.
//There is a one - one mapping between nuts and bolts.Comparison of a nut to 
//another nut or a bolt to another bolt is not allowed.It means nut can only 
//be compared with bolt and bolt can only be compared with nut to see which one is bigger / smaller.
//
//We will give you a compare function to compare nut with bolt.
//
//Example
//Given nuts = ['ab', 'bc', 'dd', 'gg'], bolts = ['AB', 'GG', 'DD', 'BC'].
//
//Your code should find the matching bolts and nuts.
//
//one of the possible return:
//
//nuts = ['ab', 'bc', 'dd', 'gg'], bolts = ['AB', 'BC', 'DD', 'GG'].
//
//we will tell you the match compare function.If we give you another compare function.
//
//the possible return is the following :
//
//nuts = ['ab', 'bc', 'dd', 'gg'], bolts = ['BC', 'AA', 'DD', 'GG'].
//
//So you must use the compare function that we give to do the sorting.
//
//The order of the nuts or bolts does not matter.You just need to find the matching bolt for each nut.

namespace LintSolution1
{
    namespace NutsAndBoltsProblem_Medium
    {
		/*
		You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
		if "a" is bigger than "b", it will return 1, else if they are equal,
		it will return 0, else if "a" is smaller than "b", it will return -1.
		When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
		*/
		class Comparator {
		public:
			bool isLower(string a)
			{
				for (char c : a)
				{
					if (!islower(c)) { return false; }
				}
				return true;
			}

			int cmp(string a, string b)
			{
				bool isALower = isLower(a);
				bool isBLower = isLower(b);
				if (! (isALower && !isBLower)) { return 2; }
				
				transform(a.begin(), a.end(), a.begin(), tolower);
				transform(b.begin(), b.end(), b.begin(), tolower);
				if (a < b)
				{
					return -1;
				}
				else if (a > b)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}
		};

		int partition(vector<string>& A, Comparator compare, string target, int start, int end)
		{
			int slow = start;
			int fast = start;
			while (fast < end)
			{
				int compareResult = compare.cmp(A[fast], target);
				if (compareResult < 0 || compareResult == 2 && compare.cmp(target, A[fast]) > 0)
				{
					swap(A[slow], A[fast]);
					slow++;
				}
				else if (compareResult == 0 || compareResult == 2 && compare.cmp(target, A[fast]) == 0)
				{
					swap(A[fast], A[end]);
					fast--;
				}
				fast++;
			}
			swap(A[slow], A[end]);
			return slow;
		}

		void sortImpl(vector<string>& nuts, vector<string>& bolts, Comparator compare, int start, int end)
		{
			if (start >= end) { return; }

			string target = bolts[start + (end - start) / 2];
			int pivot = partition(nuts, compare, target, start, end);
			partition(bolts, compare, nuts[pivot], start, end);

			sortImpl(nuts, bolts, compare, start, pivot - 1);
			sortImpl(nuts, bolts, compare, pivot + 1, end);		
		}

		/**
		* @param nuts: a vector of integers
		* @param bolts: a vector of integers
		* @param compare: a instance of Comparator
		* @return: nothing
		*/
		void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
			int len = nuts.size();
			if (len < 2) { return; }

			sortImpl(nuts, bolts, compare, 0, len - 1);
		}

     
		void Main()
		{
			vector<string> nuts;
			vector<string> bolts;
			Comparator compare;


			nuts = { "ab", "bc", "dd", "gg" };
			bolts = { "AB", "GG", "DD", "BC" };
			sortNutsAndBolts(nuts, bolts, compare);
			print(nuts);
			print(bolts);
        }
    }
}
   
    