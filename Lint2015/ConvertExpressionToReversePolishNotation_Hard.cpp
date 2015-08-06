#include "stdafx.h"

//Given an expression string array, return the Reverse Polish notation of this expression. (remove the parentheses)
//
//Example
//
//For the expression[3 - 4 + 5](which denote by["3", "-", "4", "+", "5"]), return[3 4 - 5 + ](which denote by["3", "4", "-", "5", "+"])

namespace LintSolution1
{
    namespace ConvertExpressionToReversePolishNotation_Hard
    {
     
     
		/**
		* @param expression: A string array
		* @return: The Reverse Polish notation of this expression
		*/
		vector<string> convertToRPN(vector<string> &exp) {
			vector<string> result;
			int len = exp.size();
			if (len == 0) { return result; }

			stack<string> s;
			unordered_map<string, int> pri;
			pri["+"] = 1;
			pri["-"] = 1;
			pri["*"] = 2;
			pri["/"] = 2;

			for (string cur : exp)
			{
				if (cur[0] - '0' >= 0 && cur[0] - '0' <= 9)
				{
					result.push_back(cur);
				}
				else if (cur == "(")
				{
					s.push(cur);
				}
				else if (cur == ")")
				{
					while (s.top() != "(")
					{
						result.push_back(s.top());
						s.pop();
					}
					s.pop();
				}
				else
				{
					while (!s.empty() && s.top() != "(" && pri[cur] <= pri[s.top()])
					{
						result.push_back(s.top());
						s.pop();
					}
					s.push(cur);
				}
			}

			while (!s.empty())
			{
				result.push_back(s.top());
				s.pop();
			}
			return result;
		}
     
        void Main()
        {
			vector<string> input;

			//input = { "2", "*", "6", "-", "(", "23", "+", "7", ")", "/", "(", "1", "+", "2", ")" };
			//print(convertToRPN(input));

			input = { "3", "-", "4", "+", "5" };
			print(convertToRPN(input));
        }
    }
}
   
    