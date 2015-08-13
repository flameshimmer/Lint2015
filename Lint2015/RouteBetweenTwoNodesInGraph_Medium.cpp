#include "stdafx.h"


//Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
//
//Example
//Given graph:
//
//A----->B----->C
// \     |
//  \    |
//   \   |
//    \  v
//     ->D----->E
//for s = B and t = E, return true
//
//for s = D and t = C, return false

namespace LintSolution1
{
    namespace RouteBetweenTwoNodesInGraph_Medium
    {
		//Definition for Directed graph.
		struct DirectedGraphNode {
			int label;
			vector<DirectedGraphNode *> neighbors;
			DirectedGraphNode(int x) : label(x) {};
		};
     
		/**
		* @param graph: A list of Directed graph node
		* @param s: the starting Directed graph node
		* @param t: the terminal Directed graph node
		* @return: a boolean value
		*/
		bool hasRoute(vector<DirectedGraphNode*> graph, DirectedGraphNode* s, DirectedGraphNode* t) {
			unordered_set<DirectedGraphNode*> set;
			for (DirectedGraphNode* node : graph) { set.insert(node); }

			queue<DirectedGraphNode*> q;
			q.push(s);

			while (!q.empty())
			{
				DirectedGraphNode* cur = q.front();
				q.pop();
				if (cur == t) { return true; } // note: check cur instead of the child
				set.erase(cur);
				for (DirectedGraphNode* child : cur->neighbors)
				{
					if (set.find(child) == set.end()) { continue; }
					q.push(child);
				}
			}
			return false;
		}
     
        void Main()
        {
         
        }
    }
}
   
    