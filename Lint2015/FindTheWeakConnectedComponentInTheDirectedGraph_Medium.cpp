#include "stdafx.h"

//Find the number Weak Connected Component in the directed graph. Each node in the graph contains a label and a list of its neighbors.
//(a connected set of a directed graph is a subgraph in which any two vertices are connected by direct edge path.)
//
//Example
//Given graph:
//
//A----->B  C
// \     |  | 
//  \    |  |
//   \   |  |
//    \  v  v
//     ->D  E <- F
//Return {A,B,D}, {C,E,F}. Since there are two connected component which are {A,B,D} and {C,E,F}
//
//Note
//Sort the element in the set in increasing order
//

namespace LintSolution1
{
    namespace FindTheWeakConnectedComponentInTheDirectedGraph_Medium
    {
		//Definition for Directed graph.
		struct DirectedGraphNode {
			int label;
			vector<DirectedGraphNode *> neighbors;
			DirectedGraphNode(int x) : label(x) {};
		};
     

		int findParent(unordered_map<int, int>& parent, int v)
		{
			if (parent.find(v) == parent.end()) { parent[v] = v; return v; }

			while (v != parent[v]) { v = parent[v]; }
			return v;
		}


		vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes)
		{
			vector<vector<int>> results;
			int len = nodes.size();
			if (len == 0) { return results; }

			unordered_map<int, int> parent;
			for (auto node : nodes)
			{
				int pA = findParent(parent, node->label);
				for (auto child : node->neighbors)
				{
					pA = findParent(parent, node->label);
					int pB = findParent(parent, child->label);					
					parent[max(pA, pB)] = min(pA, pB);
				}
			}

			// Create a map of components, push each nodes into their belonging components
			unordered_map<int, vector<int>> comp; // component root node Id, component nodes array
			for (auto node : nodes)
			{
				int p = findParent(parent, node->label);
				comp[p].push_back(node->label);
			}

			// Sort the nodes inside each group to satisfy the output criteria
			for (auto p : comp)
			{
				sort(p.second.begin(), p.second.end());
				results.push_back(p.second);
			}
			return results;
		}


        void Main()
        {
			DirectedGraphNode* n1 = new DirectedGraphNode(1);
			DirectedGraphNode* n2 = new DirectedGraphNode(2);
			DirectedGraphNode* n4 = new DirectedGraphNode(4);


			DirectedGraphNode* n3 = new DirectedGraphNode(3);
			DirectedGraphNode* n5 = new DirectedGraphNode(5);

			n4->neighbors.push_back(n2);
			n2->neighbors.push_back(n4);

			n1->neighbors.push_back(n2);
			n2->neighbors.push_back(n1);

			n4->neighbors.push_back(n1);
			n1->neighbors.push_back(n4);

			n3->neighbors.push_back(n5);
			n5->neighbors.push_back(n3);

			vector<DirectedGraphNode*> input = { n1, n2, n3, n4, n5 };

			print(connectedSet2(input));
        }
    }
}
   
    