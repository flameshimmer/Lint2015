#include "stdafx.h"

//Write a function that add two numbers A and B.You should not use + or any arithmetic operators.
//
//Have you met this question in a real interview ? Yes
//Example
//Given a = 1 and b = 2 return 3
//
//Note
//There is no need to read data from standard input stream.Both parameters are given in function 
//aplusb, you job is to calculate the sum and return it.
//
//Challenge
//Of course you can just return a + b to get accepted.But Can you challenge not do it like that ?
//
//Clarification
//Are a and b both 32 - bit integers ?
//
//Yes.
//Can I use bit operation ?
//
//Sure you can.

namespace LintSolution1
{
    namespace APlusBProblem_Medium
    {
		/*
		* @param a: The first integer
		* @param b: The second integer
		* @return: The sum of a and b
		*/
		int aplusb(int a, int b) {

			int carry = 0;
			int a2 = a;
			int b2 = b;
			int result = 0;
			if (a2 < 0) { a2 = ~a2 + 1; }
			if (b2 < 0) { b2 = ~b2 + 1; }
			int i = 0;
			while (i<32 && (a2 || b2 || carry))
			{
				int sum = (a2 & 1) + (b2 & 1) + carry;
				carry = sum / 2;
				result |= (sum % 2) << i;
				a2 >>= 1;
				b2 >>= 1;
				i++;
			}
			return result;
		}
     
     
        void Main()
        {
			print(aplusb(1, 2));
			print(aplusb(1, -2));
        }
    }
}
   
    