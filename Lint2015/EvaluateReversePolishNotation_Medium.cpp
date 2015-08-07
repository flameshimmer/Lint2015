#include "stdafx.h"

//Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//Valid operators are + , -, *, / .Each operand may be an integer or another expression.
//
//Example
//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

namespace LintSolution1
{
    namespace EvaluateReversePolishNotation_Medium
    {
     
		int strToInt(string tokens)
		{
			bool isNeg = false;
			int i = 0;
			if (tokens[0] == '-') { isNeg = true; i++; }
			int result = 0;
			while (i < tokens.length())
			{
				result = result * 10 + tokens[i] - '0';
				i++;
			}
			if (isNeg) { result *= -1; }
			return result;
		}

		/**
		* @param tokens The Reverse Polish Notation
		* @return the value
		*/
		int evalRPN(vector<string>& tokens) {
			int result = 0;
			stack<int> s;

			for (string cur : tokens)
			{
				if (cur != "+" && cur != "-" && cur != "*" && cur != "/")
				{
					s.push(strToInt(cur));
				}
				else
				{
					int op1 = s.top();
					s.pop();
					int op2 = s.top();
					s.pop();
					if (cur == "+") { s.push(op2 + op1); }
					else if (cur == "-") { s.push(op2 - op1); }
					else if (cur == "*") { s.push(op2 * op1); }
					else if (cur == "/") { s.push(op2 / op1); }
				}
			}
			return s.top();
		}
     
        void Main()
        {
         
        }
    }
}
   
    