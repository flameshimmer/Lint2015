#include "stdafx.h"

//The structure of Expression Tree is a binary tree to evaluate certain expressions.
//All leaves of the Expression Tree have an number string value. All non-leaves of the Expression Tree have an operator string value.
//
//Now, given an expression array, build the expression tree of this expression, return the root of this expression tree.
//
//Example
//For the expression (2*6-(23+7)/(1+2)) (which can be represented by ["2" "*" "6" "-" "(" "23" "+" "7" ")" "/" "(" "1" "+" "2" ")"]). 
//The expression tree will be like
//
//                 [ - ]
//             /          \
//        [ * ]              [ / ]
//      /     \           /         \
//    [ 2 ]  [ 6 ]      [ + ]        [ + ]
//                     /    \       /      \
//                   [ 23 ][ 7 ] [ 1 ]   [ 2 ] .
//                   
//After building the tree, you just need to return root node [-].

namespace LintSolution1
{
    namespace ExpressionTreeBuild_Hard
    {

		//Definition of ExpressionTreeNode:
		class ExpressionTreeNode {
		public:
			string symbol;
			ExpressionTreeNode *left, *right;
			ExpressionTreeNode(string symbol) {
				this->symbol = symbol;
				this->left = this->right = NULL;
			}
		};

		void buildTree(stack<ExpressionTreeNode*>& ops, stack<string>& s)
		{
			ExpressionTreeNode* op1 = ops.top(); 
			ops.pop();
			ExpressionTreeNode* op2 = ops.top();
			ops.pop();

			ExpressionTreeNode* op = new ExpressionTreeNode(s.top());
			s.pop();

			op->left = op2;
			op->right = op1;
			ops.push(op);
		}

		/**
		* @param expression: A string array
		* @return: The root of expression tree
		*/
		ExpressionTreeNode* build(vector<string> &exp) {
			int len = exp.size();
			if (len == 0) { return NULL; }

			stack<ExpressionTreeNode*> ops;
			stack<string> s;
			unordered_map<string, int> pri;
			pri["+"] = 1;
			pri["-"] = 1;
			pri["*"] = 2;
			pri["/"] = 2;
			for (string cur : exp)
			{
				if (cur != "+" && cur != "-" && cur != "*" && cur != "/" && cur != "(" && cur != ")")
				{
					ops.push(new ExpressionTreeNode(cur));
				}
				else
				{
					if (cur == "(") 
					{ 
						s.push(cur); 
					}
					else if (cur == ")")
					{
						while (s.top() != "(")
						{
							buildTree(ops, s);
						}
						s.pop();
					}
					else
					{
						while (!s.empty() && s.top() != "(" && pri[s.top()] >= pri[cur])
						{
							buildTree(ops, s);
						}
						s.push(cur);
					}
				}
			}
			while (!s.empty()) { buildTree(ops, s); }
			return ops.empty() ? NULL : ops.top();
		}
     
     
        void Main()
        {
			vector<string> input;
			
			input = { "(", "(", "(", "(", "(", ")", ")", ")", ")", ")" };
			build(input);
			
			
			input = { "2", "*", "6", "-", "(", "23", "+", "7", ")", "/", "(", "1", "+", "2", ")" };
			build(input);         


        }
    }
}
   
    