#include "stdafx.h"

//Given number n.Print number from 1 to n.But:
//
//when number is divided by 3, print "fizz".
//when number is divided by 5, print "buzz".
//when number is divided by both 3 and 5, print "fizz buzz".
//
//Example
//If n = 15, you should return:
//
//["1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizz buzz"]

namespace LintSolution1
{
    namespace FizzBuzz_Easy
    {     
		/**
		* param n: As description.
		* return: A list of strings.
		*/
		vector<string> fizzBuzz(int n) {
			vector<string> result;
			if (n == 0) { return result; }

			for (int i = 1; i <= n; i++)
			{
				if (i % 15 == 0) { result.push_back("fizz buzz"); }
				else if (i % 3) { result.push_back("fizz"); }
				else if (i % 5) { result.push_back("buzz"); }
				else { result.push_back(to_string(i)); }
			}
			return result;
		}
     
        void Main()
        {
         
        }
    }
}
   
    