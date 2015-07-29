#include "stdafx.h"

//Design an algorithm and write code to serialize and deserialize a binary tree.
//Writing the tree to a file is called 'serialization' and reading back from the
//file to reconstruct the exact same binary tree is 'deserialization'.
//
//There is no limit of how you deserialize or serialize a binary tree, you only need 
//to make sure you can serialize a binary tree to a string and deserialize this string to the original structure.
//
//Have you met this question in a real interview ? Yes
//Example
//An example of testdata : Binary tree{ 3, 9, 20, #, #, 15, 7 }, denote the following structure :
//
//		3
//	   / \
//	  9  20
//		 / \
//		15   7
//Our data serialization use bfs traversal.This is just for when you got wrong answer and want to debug the input.
//
//You can use other method to do serializaiton and deserialization.

namespace LintSolution1
{
    namespace BinaryTreeSerialization_Medium
    {
		/**
		* This method will be invoked first, you should design your own algorithm
		* to serialize a binary tree which denote by a root node to a string which
		* can be easily deserialized by your own "deserialize" method later.
		*/
		string serialize(TreeNode *root) {
			if (!root) { return ""; }
			string result;
			stack<TreeNode*> s;
			s.push(root);

			while (!s.empty())
			{
				TreeNode* top = s.top();
				s.pop();
				if (!top) { result += "# "; }
				else {
					result += to_string(top->val) + " ";
					s.push(top->right);
					s.push(top->left);
				}
			}
			int end = result.size() - 1;
			while (end >= 0 && (result[end] == '#' || result[end] == ' ')) { end--; }
			result = result.substr(0, end + 1);			
			return result;
		}

		/**
		* This method will be invoked second, the argument data is what exactly
		* you serialized at method "serialize", that means the data is not given by
		* system, it's given by your own serialize method. So the format of data is
		* designed by yourself, and deserialize it here as you serialize it in
		* "serialize" method.
		*/
		TreeNode* deImpl(string& data, int& i)
		{
			int len = data.size();
			if (i == len) { return NULL; }

			int start = i;
			while (start < len && data[start] == ' ') { start++; }
			int end = start + 1;
			while (end < len && (data[end] != ' ')) { end++; }
			end--;
			i = end + 1;

			string d = data.substr(start, end - start + 1);
			if (d == "#") { return NULL; }
			long long val = 0;
			for (char c : d)
			{
				val = val * 10 + c - '0';
			}
			TreeNode* node = new TreeNode(val);
			node->left = deImpl(data, i);
			node->right = deImpl(data, i);
			return node;
		}

		TreeNode *deserialize(string data) {
			int len = data.size();
			if (len == 0) { return NULL; }
			int i = 0;
			return deImpl(data, i);
		}

     
     
     
        void Main()
        {
			TreeNode* n1 = new TreeNode(1);
			TreeNode* n2 = new TreeNode(2);
			n1->right = n2;

			string data = serialize(n1);
			print(data);
			TreeNode* head = deserialize(data);
			print(serialize(head));
        }
    }
}
   
    