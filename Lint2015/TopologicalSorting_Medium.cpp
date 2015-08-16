#include "stdafx.h"

//Given an directed graph, a topological order of the graph nodes is defined as follow :
//
//For each directed edge A->B in graph, A must before B in the order list.
//The first node in the order can be any node in the graph with no nodes direct to it.
//Find any topological order for the given graph.
//
//
//The topological order can be :
//
//[0, 1, 2, 3, 4, 5]
//[0, 2, 3, 1, 5, 4]
//...
//Note
//You can assume that there is at least one topological order in the graph.
//
//Challenge
//Can you do it in both BFS and DFS ?

namespace LintSolution1
{
    namespace TopologicalSorting_Medium
    {
		//Definition for Directed graph.
		struct DirectedGraphNode {
			int label;
			vector<DirectedGraphNode *> neighbors;
			DirectedGraphNode(int x) : label(x) {};
		};


		namespace BFS
		{
			/**
			* @param graph: A list of Directed graph node
			* @return: Any topological order for the given graph.
			*/
			vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
				vector<DirectedGraphNode*> result;
				unordered_map<DirectedGraphNode*, int> inDegree;


				for (DirectedGraphNode* node : graph)
				{
					if (inDegree.find(node) == inDegree.end()) { inDegree[node] = 0; } // Don't forget about this step!!!
					for (DirectedGraphNode* child : node->neighbors)
					{
						inDegree[child]++;
					}
				}

				queue<DirectedGraphNode*> q;
				for (auto p : inDegree)
				{
					if (p.second == 0) { q.push(p.first); }
				}

				while (!q.empty())
				{
					DirectedGraphNode* cur = q.front();
					q.pop();
					result.push_back(cur);
					for (DirectedGraphNode* child : cur->neighbors)
					{
						inDegree[child]--;
						if (inDegree[child] == 0) { q.push(child); }
					}
				}
				return result;
			}
		}


		void findParents(DirectedGraphNode* node, unordered_set<DirectedGraphNode*>& visited, unordered_map<DirectedGraphNode*, vector<DirectedGraphNode*>>& parents)
		{
			if (visited.insert(node).second)
			{
				for (DirectedGraphNode* child : node->neighbors)
				{
					parents[child].push_back(node);
					findParents(child, visited, parents);
				}
			}		
		}

		void topSortDFS(DirectedGraphNode* node, unordered_map<DirectedGraphNode*, vector<DirectedGraphNode*>>& parents, unordered_set<DirectedGraphNode*>& visited, vector<DirectedGraphNode*>& result)
		{
			if (visited.insert(node).second)
			{
				for (DirectedGraphNode* parent : parents[node])
				{
					topSortDFS(parent, parents, visited, result);
				}

				result.push_back(node);
			}
		}


		vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph)
		{
			vector<DirectedGraphNode*>result;
			unordered_set<DirectedGraphNode*> visited;
			unordered_map<DirectedGraphNode*, vector<DirectedGraphNode*>> parents;

			for (DirectedGraphNode* node : graph)
			{
				findParents(node, visited, parents);			
			}

			visited.clear();
			for (DirectedGraphNode* node : graph)
			{
				topSortDFS(node, parents, visited, result);
			}
			return result;
		}


		vector<DirectedGraphNode*> createGraph(vector<vector<int>> input);
        void Main()
        {
			vector<DirectedGraphNode*> graph = createGraph({ { 0, 1, 2, 3, 4 }, { 1, 3, 4 }, { 2, 1, 4 }, { 3, 4 }, { 4 } });
			topSort(graph);
        }

		vector<DirectedGraphNode*> createGraph(vector<vector<int>> input)
		{
			unordered_map<int, DirectedGraphNode*> map;
			for (vector<int> data : input)
			{
				if (map.find(data[0]) == map.end()) 
				{
					map[data[0]] = new DirectedGraphNode(data[0]);
				}
				for (int i = 1; i < data.size(); i++)
				{
					if (map.find(data[i]) == map.end())
					{
						map[data[i]] = new DirectedGraphNode(data[i]);
					}
					map[data[0]]->neighbors.push_back(map[data[i]]);
				}
			}
			
			vector<DirectedGraphNode*> result;
			for (auto p : map) { result.push_back(p.second); }
			return result;
		}
    }
}
   
    