#include "stdafx.h"

//Calculate the a^n % b where a, b and n are all 32bit integers.
//
//Example
//For 2^31 % 3 = 2
//
//For 100^1000 % 1000 = 0
//
//Challenge
//O(logn)

namespace LintSolution1
{
    namespace FastPower_Medium
    {
     
		long long fastPowerImpl(int a, int b, int n)
		{
			// (a * c) % b = (a%b * c%b) % b
			if (n == 0) { return 1 % b; }
			if (n == 1) { return a % b; }

			long long result = fastPowerImpl(a, b, n / 2);
			result = (result * result) % b;
			if (n % 2 == 1) { result = (result * a% b) % b; }
			return result;		
		}

		/*
		* @param a, b, n: 32bit integers
		* @return: An integer
		*/
		int fastPower(int a, int b, int n) {
			return (int)fastPowerImpl(a, b, n);
		}
     
        void Main()
        {
			print(fastPower(2, 3, 31));
			print(fastPower(100, 1000, 1000));
			print(fastPower(2, 2147483647, 2147483647));
        }
    }
}
   
    