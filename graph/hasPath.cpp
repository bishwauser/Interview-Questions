/*
Write a function, hasPath, that takes in an unordered map representing the adjacency list of a directed acyclic graph and two nodes (src, dst).
The function should return a boolean indicating whether or not there exists a directed path between the source and destination nodes.

Hey. This is our first graph problem, so you should be liberal with watching the Approach and Walkthrough. Be productive, not stubborn. -AZ

test_00:

std::unordered_map<std::string, std::vector<std::string>> graph {
  { "f", {"g", "i"} },
  { "g", {"h"} },
  { "h", {} },
  { "i", {"g", "k"} },
  { "j", {"i"} },
  { "k", {} }
};

hasPath(graph, "f", "k"); // 1 (true)
test_01:

std::unordered_map<std::string, std::vector<std::string>> graph {
  { "f", { "g", "i" } },
  { "g", {"h"} },
  { "h", {} },
  { "i", {"g", "k"} },
  { "j", {"i"} },
  { "k", {} }
};

hasPath(graph, "f", "j"); // 0 (false)
test_02:

std::unordered_map<std::string, std::vector<std::string>> graph {
  { "f", {"g", "i"} },
  { "g", {"h"} },
  { "h", {} },
  { "i", {"g", "k"} },
  { "j", {"i"} },
  { "k", {} }
};

hasPath(graph, "i", "h"); // 1 (true)
test_03:

std::unordered_map<std::string, std::vector<std::string>> graph {
  { "v", {"x", "w"} },
  { "w", {} },
  { "x", {} },
  { "y", {"z"} },
  { "z", {} } 
};

hasPath(graph, "v", "w"); // 1 (true)
test_04:

std::unordered_map<std::string, std::vector<std::string>> graph {
  { "v", {"x", "w"} },
  { "w", {} },
  { "x", {} },
  { "y", {"z"} },
  { "z", {} } 
};

hasPath(graph, "v", "z"); // 0 (false)
*/

#include <unordered_map>
#include <vector>
#include <string>
#include<iostream>
using namespace std;


bool hasPath(std::unordered_map<std::string, std::vector<std::string>> graph, std::string src, std::string dst) {
  //cout<<"hello"<<endl;
    if(dst.compare(src) == 0)
        return true;
    for(auto neighbour:graph[src])
    {
        if(hasPath(graph, neighbour, dst)) return true;
    }
    return false;
}



int main {
    std::unordered_map<std::string, std::vector<std::string>> graph {
        { "v", {"x", "w"} },
        { "w", {} },
        { "x", {} },
        { "y", {"z"} },
        { "z", {} } 
    };
    hasPath(graph, "v", "z"); // 0 (false)  
}
