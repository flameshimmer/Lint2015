#include "stdafx.h"

//Given an expression string array, return the final result of this expression
//
//Example
//For the expression 2 * 6 - (23 + 7) / (1 + 2), input is
//
//[
//	"2", "*", "6", "-", "(",
//	"23", "+", "7", ")", "/",
//	(", "1", " + ", "2", ")"
//],
//return 2
//
//Note
//The expression contains only integer, +, -, *, / , (, ).

namespace LintSolution1
{
    namespace ExpressionEvaluation_Hard
    {
		int strToInt(string s)
		{
			int result = 0;
			int i = 0;
			bool isNeg = false;
			if (s[0] == '-') { isNeg = true; i++; }
			while (i < s.length())
			{
				result = result * 10 + s[i] - '0';
				i++;
			}
			if (isNeg) { result *= -1; }			
			return result;
		}

		void calc(stack<int>& ops, stack<string>& s)
		{
			int op1 = ops.top(); ops.pop();
			int op2 = ops.top(); ops.pop();
			string op = s.top(); s.pop();

			if (op == "+") { ops.push(op2 + op1); }
			else if (op == "-") { ops.push(op2 - op1); }
			else if (op == "*") { ops.push(op2 * op1); }
			else if (op == "/") { ops.push(op2 / op1); }
		}


		/**
		* @param expression: a vector of strings;
		* @return: an integer
		*/
		int evaluateExpression(vector<string> &exp) {
			int result = 0;
			int len = exp.size();
			if (len == 0) { return result; }
			
			stack<int> ops;
			stack<string> s;
			unordered_map<string, int> pri;
			pri["+"] = 1;
			pri["-"] = 1;
			pri["*"] = 2;
			pri["/"] = 2;

			for (string cur : exp)
			{
				if (cur != "+" && cur != "-" &&cur != "*" &&cur != "/" &&cur != ")" &&cur != "(")
				{
					ops.push(strToInt(cur));
				}
				else
				{
					if (cur == "(") { s.push(cur); }
					else if (cur == ")")
					{
						while (s.top() != "(")
						{
							calc(ops, s);
						}
						s.pop();
					}
					else
					{
						while (!s.empty() && s.top() != "(" && pri[s.top()] >= pri[cur])
						{
							calc(ops, s);
						}
						s.push(cur);
					}
				}
			}
			while (!s.empty()) { calc(ops, s); }
			return ops.top();
		}

		void Main()
		{
			vector<string> input;

			input = { "(", "999", "/", "3", "/", "3", "/", "3", ")", "+", "(", "1", "+", "9", "/", "3", ")" };
			print(evaluateExpression(input));

			input = { "1", "+", "99" };
			print(evaluateExpression(input));

			input = {"2", "*", "6", "-", "(", "23", "+", "7", ")", "/", "(", "1", " + ", "2", ")" };
			print(evaluateExpression(input));
         
        }
    }
}
   
    