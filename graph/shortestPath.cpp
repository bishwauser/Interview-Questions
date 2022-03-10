/*
Write a function, shortestPath, that takes in a vector of edges for an undirected graph and two nodes (nodeA, nodeB). The function should return the length of the shortest path between A and B. Consider the length as the number of edges in the path, not the number of nodes. If there is no path between A and B, then return -1.

test_00:

std::vector<std::tuple<std::string, std::string>> edges {
  {"w", "x"},
  {"x", "y"},
  {"z", "y"},
  {"z", "v"},
  {"w", "v"}
};
shortestPath(edges, "w", "z"); // -> 2
test_01:

std::vector<std::tuple<std::string, std::string>> edges {
  {"w", "x"},
  {"x", "y"},
  {"z", "y"},
  {"z", "v"},
  {"w", "v"}
};
shortestPath(edges, "y", "x"); // -> 1
test_02:

std::vector<std::tuple<std::string, std::string>> edges {
  {"a", "c"},
  {"a", "b"},
  {"c", "b"},
  {"c", "d"},
  {"b", "d"},
  {"e", "d"},
  {"g", "f"}
};
shortestPath(edges, "a", "e"); // -> 3
test_03:

std::vector<std::tuple<std::string, std::string>> edges {
  {"a", "c"},
  {"a", "b"},
  {"c", "b"},
  {"c", "d"},
  {"b", "d"},
  {"e", "d"},
  {"g", "f"}
};
shortestPath(edges, "e", "c"); // -> 2
test_04:

std::vector<std::tuple<std::string, std::string>> edges {
  {"a", "c"},
  {"a", "b"},
  {"c", "b"},
  {"c", "d"},
  {"b", "d"},
  {"e", "d"},
  {"g", "f"}
};
shortestPath(edges, "b", "g"); // -> -1
test_05:

std::vector<std::tuple<std::string, std::string>> edges {
  {"c", "n"},
  {"c", "e"},
  {"c", "s"},
  {"c", "w"},
  {"w", "e"},
};
shortestPath(edges, "w", "e"); // -> 1
test_06:

std::vector<std::tuple<std::string, std::string>> edges {
  {"c", "n"},
  {"c", "e"},
  {"c", "s"},
  {"c", "w"},
  {"w", "e"},
};
shortestPath(edges, "n", "e"); // -> 2
test_07:

std::vector<std::tuple<std::string, std::string>> edges {
  {"m", "n"},
  {"n", "o"},
  {"o", "p"},
  {"p", "q"},
  {"t", "o"},
  {"r", "q"},
  {"r", "s"}
};
shortestPath(edges, "m", "s"); // -> 6
*/

#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

void print(set<string> s)
{
    for(auto val:s)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}

void print(map<string, vector<string> > graph)
{
    for(auto node:graph)
    {
        cout<<node.first<<": ";
        for(auto neighbour:node.second)
        {
            cout<<neighbour<<" ";
        }
        cout<<endl;
    }
}

void getAdjacencyList(std::vector<std::tuple<std::string, std::string>> edges, map<string, vector<string> > &graph)
{
    for(auto edge:edges)
    {
        if(graph.find(get<0>(edge)) != graph.end())
        {
            graph[get<0>(edge)].push_back(get<1>(edge));
        }
        else
        {
            graph[get<0>(edge)] = vector<string>(1, get<1>(edge));
        }
        if(graph.find(get<1>(edge)) != graph.end())
        {
            graph[get<1>(edge)].push_back(get<0>(edge));
        }
        else
        {
            graph[get<1>(edge)] = vector<string>(1, get<0>(edge));
        }
    }
}

int bfs(map<string, vector<string> > graph, string src, string dst, set<string> &visited)
{
    queue<pair<string, int> > q;
    q.push(pair<string, int>(src, 0));
    while(!q.empty())
    {
        pair<string, int> curNode = q.front();
        q.pop();
        if(dst.compare(curNode.first) == 0) return curNode.second;
        visited.insert(curNode.first);
        for(auto neighbour:graph[curNode.first])
        {
            //cout<<"src: "<<curNode.first<<", neighbour: "<<neighbour<<endl;
            //print(visited);
            if(visited.find(neighbour) == visited.end())
            {
              q.push(pair<string, int>(neighbour, curNode.second+1));
            }
        }
    }
    return -1;
}

int shortestPath(std::vector<std::tuple<std::string, std::string>> edges, std::string nodeA, std::string nodeB) 
{
    map<string, vector<string> > graph;
    getAdjacencyList(edges, graph);
    //print(graph);
    set<string> visited;
    return bfs(graph, nodeA, nodeB, visited);
}



void run() {
    std::vector<std::tuple<std::string, std::string>> edges {
      {"w", "x"},
      {"x", "y"},
      {"z", "y"},
      {"z", "v"},
      {"w", "v"}
    };
    shortestPath(edges, "w", "z");
}
