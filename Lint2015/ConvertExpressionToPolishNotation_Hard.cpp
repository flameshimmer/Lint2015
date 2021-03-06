#include "stdafx.h"

//Given an expression string array, return the Polish notation of this expression. (remove the parentheses)
//
//Have you met this question in a real interview ? Yes
//Example
//For the expression[(5 − 6) * 7](which represented by["(", "5", "−", "6", ")", "*", "7"]), 
//the corresponding polish notation is[*-5 6 7](which the return value should be["*", "−", "5", "6", "7"]).
//
//Clarification
//Definition of Polish Notation :
//
//http ://en.wikipedia.org/wiki/Polish_notation
//http ://baike.baidu.com/view/7857952.htm

namespace LintSolution1
{
    namespace ConvertExpressionToPolishNotation_Hard
    {
     
		namespace logged{
			/**
			* @param expression: A string array
			* @return: The Polish notation of this expression
			*/
			vector<string> convertToPN(vector<string> &exp) {
				vector<string> result;
				int len = exp.size();

				if (len == 0) { return result; }
				stack<string> s;
				unordered_map<string, int> pri;
				pri["+"] = 1;
				pri["-"] = 1;
				pri["*"] = 2;
				pri["/"] = 2;

				for (int i = len - 1; i >= 0; i--)
				{
					string cur = exp[i];
					if (cur[0] - '0' >= 0 && cur[0] - '0' <= 9)
					{
						cout << "prefix result with " << cur << "\n";
						result.insert(result.begin(), cur);
					}
					else if (cur == ")")
					{
						cout << "pushing )\n";
						s.push(cur);
					}
					else if (cur == "(")
					{
						while (s.top() != ")")
						{
							cout << "prefix result with " << s.top() << "\n";
							result.insert(result.begin(), s.top());
							cout << "popping " << s.top() << "\n";
							s.pop();
						}
						cout << "popping " << s.top() << "\n";
						s.pop();
					}
					else
					{
						while (!s.empty() && pri[cur] < pri[s.top()] && s.top() != ")")
						{
							cout << "prefix result with " << s.top() << "\n";
							result.insert(result.begin(), s.top());
							cout << "popping " << s.top() << "\n";
							s.pop();
						}
						cout << "pushing " << cur << "\n";
						s.push(cur);
					}
				}
				while (!s.empty())
				{
					cout << "prefix result with " << s.top() << "\n";
					result.insert(result.begin(), s.top());
					cout << "popping " << s.top() << "\n";
					s.pop();
				}
				return result;
			}
		}
     

		vector<string> convertToPN(vector<string> &exp) {
			vector<string> result;
			int len = exp.size();
			if (len == 0) { return result; }

			unordered_map<string, int> pri;
			pri["+"] = 1;
			pri["-"] = 1;
			pri["*"] = 2;
			pri["/"] = 2;

			stack<string> s;
			for (int i = len - 1; i >= 0; i--)
			{
				string cur = exp[i];
				if (cur[0] - '0' >= 0 && cur[0] - '0' <= 9)
				{
					result.insert(result.begin(), cur);
				}
				else if (cur == ")")
				{
					s.push(cur);
				}
				else if (cur == "(")
				{
					while (s.top() != ")")
					{
						result.insert(result.begin(), s.top());
						s.pop();
					}
					s.pop();
				}
				else
				{
					while (!s.empty() && s.top()!= ")" && pri[cur] < pri[s.top()])
					{
						result.insert(result.begin(), s.top());
						s.pop();
					}
					s.push(cur);
				}
			}
			while (!s.empty())
			{
				result.insert(result.begin(), s.top());
				s.pop();
			}
			return result;
		}

        void Main()
        {
			vector<string> input;

			input = { "(", "999", "/", "3", "/", "3", "/", "3", ")", "+", "(", "1", "+", "9", "/", "3", ")" };
			print(convertToPN(input));
			cout << "Expecting: [\"+\", \"/\", \"/\", \"/\", \"999\", \"3\", \"3\", \"3\", \"+\", \"1\", \"/\", \"9\", \"3\"]\n";

			//input = { "2", "*", "6", "-", "(", "23", "+", "7", ")", "/", "(", "1", "+", "2", ")" };
			//print(convertToPN(input));
			
			//input = { "(", "(", "1", "+", "(", "2", ")", ")", "*", "3", "+", "(", "4", "/", "2", ")", "-", "5", ")" };
			//print(convertToPN(input));


			//input = { "(", "5", "-", "6", ")", "*", "7" };
			//print(convertToPN(input));

        }
    }
}
   
    