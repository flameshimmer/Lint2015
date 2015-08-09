#include "stdafx.h"

//Given an array with positive and negative integers.Re - range it to interleaving with positive and negative integers.
//
//Example
//Given[-1, -2, -3, 4, 5, 6], after re - range, it will be[-1, 5, -2, 4, -3, 6] or any other reasonable answer.
//
//Note
//You are not necessary to keep the original order of positive integers or negative integers.
//
//Challenge
//Do it in - place and without extra memory.
//

namespace LintSolution1
{
    namespace InterleavingPositiveAndNegativeNumbers_Medium
    {
     
		/**
		* @param A: An integer array.
		* @return: void
		*/
		
		void rerange(vector<int> &A) {
			int len = A.size();
			if (len < 2) { return; }

			int negCount = 0;
			for (int a : A) { if (a < 0) { negCount++; } }
			bool isNeg = negCount > len / 2;
			int nextNeg = -1;
			int nextPos = -1;

			for (int i = 0; i < len; i++)
			{
				if (nextNeg <= i)
				{
					nextNeg = i + 1;
					while (nextNeg < len && A[nextNeg] > 0) { nextNeg++; }
				}

				if (nextPos <= i)
				{
					nextPos = i + 1;
					while (nextPos < len && A[nextPos] < 0) { nextPos++; }
				}

				if (isNeg && A[i] > 0 && nextNeg < len) { swap(A[i], A[nextNeg]); nextNeg = -1; }
				else if (!isNeg && A[i] < 0 && nextPos < len) { swap(A[i], A[nextPos]); nextPos = -1; }
				isNeg = !isNeg;
			}
		}




		namespace other{
			void rerange(vector<int> &A) {
				int len = A.size();
				if (len < 2) { return; }

				int negCount = 0;
				for (int a : A) { if (a < 0) { negCount++; } }
				bool isNeg = negCount > len / 2;
				int nextNeg = -1;
				int nextPos = -1;

				for (int i = 0; i < len; i++)
				{
					if ((A[i] < 0 && isNeg) || (A[i] > 0 && !isNeg)) { isNeg = !isNeg; continue; }
					if (isNeg)
					{
						if (nextNeg != -1 && nextNeg > i) { swap(A[nextNeg], A[i]); nextNeg = -1; }
						else
						{
							int nextNeg = i + 1;
							while (nextNeg < len && A[nextNeg] > 0) { nextNeg++; }
							if (nextNeg < len) {
								swap(A[nextNeg], A[i]);
							}
						}
					}
					else
					{
						if (nextPos != -1 && nextPos > i) { swap(A[nextPos], A[i]); nextPos = -1; }
						else
						{
							int nextPos = i + 1;
							while (nextPos < len && A[nextPos] < 0) { nextPos++; }
							if (nextPos < len) {
								swap(A[nextPos], A[i]);
							}
						}
					}
					isNeg = !isNeg;
				}
			}
		}
     


        void Main()
        {
			vector<int> input = { 28, 2, -22, -27, 2, 9, -33, -4, -18, 26, 25, 34, -35, -17, 2, -2, 32, 35, -8 };
			rerange(input);
			print(input);
        }
    }
}
   
    