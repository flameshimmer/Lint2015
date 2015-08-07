#include "stdafx.h"

//Determine the number of bits required to flip if you want to convert integer n to integer m.
//
//Example
//Given n = 31 (11111), m = 14 (01110), return 2.
//
//Note
//Both n and m are 32 - bit integers.
namespace LintSolution1
{
	namespace FlipBits_Easy
	{

		/**
		*@param a, b: Two integer
		*return: An integer
		*/
		int bitSwapRequired(int a, int b) {
		}

		namespace CountXORBits
		{
			int bitSwapRequired(int a, int b) {
				int c = a^b;
				int count = 0;
				while (c)
				{
					count++;
					c &= c - 1;
				}
				return count;
			}
		}
		
		namespace CastingToUnsigned
		{
			int bitSwapRequired(int a0, int b0) {
				unsigned int a = a0;
				unsigned int b = b0;
				int count = 0;
				while (a != b)
				{
					if ((a & 1) != (b & 1)) { count++; }
					a >>= 1;
					b >>= 1;
				}
				return count;
			}
		}


		void Main()
		{
			print(bitSwapRequired(1, -1));
			print(bitSwapRequired(31, 14));
		}
	}
}

