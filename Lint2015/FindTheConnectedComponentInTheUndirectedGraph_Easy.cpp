#include "stdafx.h"

//Find the number connected component in the undirected graph. 
//Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) 
//of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, 
//and which is connected to no additional vertices in the supergraph.)
//
//Example
//Given graph:
//
//A------B  C
// \     |  | 
//  \    |  |
//   \   |  |
//    \  |  |
//      D   E
//Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}

namespace LintSolution1
{
	namespace FindTheConnectedComponentInTheUndirectedGraph_Easy
	{
		//Definition for Undirected graph.
		struct UndirectedGraphNode {
			int label;
			vector<UndirectedGraphNode *> neighbors;
			UndirectedGraphNode(int x) : label(x) {};
		};


		/**
		* @param nodes a array of Undirected graph node
		* @return a connected set of a Undirected graph
		*/
		vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
			vector<vector<int>> results;
			int len = nodes.size();
			if (len == 0) return results;

			unordered_set<UndirectedGraphNode*> visited;
			queue<UndirectedGraphNode*> q;
			vector<int> result;

			for (UndirectedGraphNode* cur : nodes)
			{
				if (visited.find(cur) == visited.end())
				{
					result.clear();
					q.push(cur);
					visited.insert(cur);

					while (!q.empty())
					{
						UndirectedGraphNode* top = q.front();
						q.pop();
						result.push_back(top->label);
						for (UndirectedGraphNode* child : top->neighbors)
						{
							if (visited.find(child) == visited.end())
							{
								visited.insert(child);
								q.push(child);
							}
						}
					}
					sort(result.begin(), result.end());
					results.push_back(result);
				}
			}
			return results;
		}

		namespace DFS
		{
			void dfs(UndirectedGraphNode* node, unordered_set<UndirectedGraphNode*>& visited, vector<int>& result)
			{
				visited.insert(node);
				result.push_back(node->label);
				for (UndirectedGraphNode* child : node->neighbors)
				{
					if (visited.find(child) != visited.end()) { continue; }
					visited.insert(child);					
					dfs(child, visited, result);
				}
			}

			vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
				vector<vector<int>> results;
				int len = nodes.size();
				if (len == 0) { return results; }

				unordered_set<UndirectedGraphNode*> visited;
				vector<int> result;
				for (UndirectedGraphNode* cur : nodes)
				{
					if (visited.find(cur) != visited.end()) { continue; }
					result.clear();
					dfs(cur, visited, result);
					sort(result.begin(), result.end());
					results.push_back(result);
				}
				return results;
			}
		}

		void Main()
		{
			UndirectedGraphNode* n1 = new UndirectedGraphNode(1);
			UndirectedGraphNode* n2 = new UndirectedGraphNode(2);
			UndirectedGraphNode* n4 = new UndirectedGraphNode(4);


			UndirectedGraphNode* n3 = new UndirectedGraphNode(3);
			UndirectedGraphNode* n5 = new UndirectedGraphNode(5);

			n4->neighbors.push_back(n2);
			n2->neighbors.push_back(n4);

			n1->neighbors.push_back(n2);
			n2->neighbors.push_back(n1);

			n4->neighbors.push_back(n1);
			n1->neighbors.push_back(n4);

			n3->neighbors.push_back(n5);
			n5->neighbors.push_back(n3);

			vector<UndirectedGraphNode*> input = { n1, n2, n3, n4, n5 };

			print(connectedSet(input));
		}
	}
}

