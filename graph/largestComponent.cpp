/*
largest component

Write a function, largestComponent, that takes in an unordered_map representing the adjacency list of an undirected graph. The function should return the size of the largest connected component in the graph.

test_00:

std::unordered_map<int, std::vector<int>> graph {
  { 0, {8, 1, 5} },
  { 1, {0} },
  { 5, {0, 8} },
  { 8, {0, 5} },
  { 2, {3, 4} },
  { 3, {2, 4} },
  { 4, {3, 2} }
};
largestComponent(graph); // -> 4
test_01:

std::unordered_map<int, std::vector<int>> graph {
  { 1, {2} },
  { 2, {1, 8} },
  { 6, {7} },
  { 9, {8} },
  { 7, {6, 8} },
  { 8, {9, 7, 2} }
};
largestComponent(graph); // -> 6
test_02:

std::unordered_map<int, std::vector<int>> graph {
  { 3, {} },
  { 4, {6} },
  { 6, {4, 5, 7, 8} },
  { 8, {6} },
  { 7, {6} },
  { 5, {6} },
  { 1, {2} },
  { 2, {1} }
};
largestComponent(graph); // -> 5
test_03:

std::unordered_map<int, std::vector<int>> graph;
largestComponent(graph); // -> 0
test_04:

std::unordered_map<int, std::vector<int>> graph {
  { 0, {4, 7} },
  { 1, {} },
  { 2, {} },
  { 3, {6} },
  { 4, {0} },
  { 6, {3} },
  { 7, {0} },
  { 8, {} }
};
largestComponent(graph); // -> 3
*/


#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int dfs(std::unordered_map<int, std::vector<int>> graph, int node, set<int> &visited)
{
    if(visited.find(node) != visited.end()) return 0;
    visited.insert(node);
    int size = 1;
    for(auto neighbour:graph[node])
    {
        size += dfs(graph, neighbour, visited);
    }
    return size;
}
int largestComponent(std::unordered_map<int, std::vector<int>> graph) 
{
    set<int> visited;
    int maxSize = 0;
    int curSize = 0;
    for(auto node:graph)
    {
        curSize = dfs(graph, node.first, visited);
        if(maxSize < curSize) maxSize = curSize;
    }
    return maxSize;
}

int main() {
    std::unordered_map<int, std::vector<int>> graph {
        { 3, {} },
        { 4, {6} },
        { 6, {4, 5, 7, 8} },
        { 8, {6} },
        { 7, {6} },
        { 5, {6} },
        { 1, {2} },
        { 2, {1} }
    };
    largestComponent(graph); // -> 5
}
