/*
Write a function, connectedComponentsCount, that takes in an unordered map respresenting the adjacency list for an undirected graph. The function should return the number of connected components within the graph.

test_00:

std::unordered_map<int, std::vector<int>> graph {
  { 0, { 8, 1, 5 } },
  { 1, { 0 } },
  { 5, { 0, 8 } },
  { 8, { 0, 5 } },
  { 2, { 3, 4 } },
  { 3, { 2, 4 } },
  { 4, { 3, 2 } }
};
connectedComponentsCount(graph); // -> 2
test_01:

std::unordered_map<int, std::vector<int>> graph {
  { 1, { 2 } },
  { 2, { 1, 8 } },
  { 6, { 7 } },
  { 9, { 8 } },
  { 7, { 6, 8 } },
  { 8, { 9, 7, 2 } }
};
connectedComponentsCount(graph); // -> 1
test_02:

std::unordered_map<int, std::vector<int>> graph {
  { 3, { } },
  { 4, { 6 } },
  { 6, { 4, 5, 7, 8 } },
  { 8, { 6 } },
  { 7, { 6 } },
  { 5, { 6 } },
  { 1, { 2 } },
  { 2, { 1 } }
};
connectedComponentsCount(graph); // -> 3
test_03:

std::unordered_map<int, std::vector<int>> graph;
connectedComponentsCount(graph); // -> 0
test_04:

std::unordered_map<int, std::vector<int>> graph {
  { 0, { 4, 7 } },
  { 1, { } },
  { 2, { } },
  { 3, { 6 } },
  { 4, { 0 } },
  { 6, { 3 } },
  { 7, { 0 } },
  { 8, { } },
};
connectedComponentsCount(graph); // -> 5
*/


#include <unordered_map>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

void print(set<int> s)
{
    for(auto val:s)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}


bool dfs(std::unordered_map<int, std::vector<int>> graph, int node, set<int> &visited)
{
    //print(visited);
    if(visited.find(node) != visited.end()) return false;
    visited.insert(node);
    for(auto neighbour:graph[node])
    {
        dfs(graph, neighbour, visited);
    }
    return true;
}

int connectedComponentsCount(std::unordered_map<int, std::vector<int>> graph) 
{
    set<int> visited;
    int count = 0;
    for(auto node:graph)
    {
        count += dfs(graph, node.first, visited);
    }
    return count;
}

void run() {
    std::unordered_map<int, std::vector<int>> graph {
        { 0, { 8, 1, 5 } },
        { 1, { 0 } },
        { 5, { 0, 8 } },
        { 8, { 0, 5 } },
        { 2, { 3, 4 } },
        { 3, { 2, 4 } },
        { 4, { 3, 2 } }
    };
    connectedComponentsCount(graph);
}
