#include "stdafx.h"


//Given string A representative a positive integer which has N digits, remove any k digits of the number,
//the remaining digits are arranged according to the original order to become a new positive integer.
//
//Find the smallest integer after remove k digits.
//
//N <= 240 and k <= N,
//
//Example
//Given an integer A = "178542", k = 4
//
//return a string "12"


namespace LintSolution1
{
    namespace DeleteDigits_Medium
    {
     
		/**
		*@param A: A positive integer which has N digits, A is a string.
		*@param k: Remove k digits.
		*@return: A string
		*/
		string DeleteDigits(string A, int k) {
			string result;
			int count = 0;
			for (char c : A)
			{
				while (!result.empty() && result.back() > c && count < k)
				{
					result.pop_back();
					count++;
				}
				result.push_back(c);
			}

			while (count < k)
			{
				result.pop_back(); 
				count++;
			}

			int cur = 0;
			while (cur < result.length() && result[cur] == '0') { cur++; }
			return result.substr(cur);
		}
     
     
        void Main()
        {
			print(DeleteDigits("90249", 2));
			print(DeleteDigits("178542", 4));
        }
    }
}
   
    