/*
undirected path

Write a function, undirectedPath, that takes in a vector of edges for an undirected graph and two nodes (nodeA, nodeB).
The function should return a boolean indicating whether or not there exists a path between nodeA and nodeB.

test_00:

std::vector<std::tuple<std::string, std::string>> edges {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges, "j", "m"); // -> 1 (true)
test_01:

std::vector<std::tuple<std::string, std::string>> edges {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges, "m", "j"); // -> 1 (true)
test_02:

std::vector<std::tuple<std::string, std::string>> edges {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges, "l", "j"); // -> 1 (true)
test_03:

std::vector<std::tuple<std::string, std::string>> edges {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges, "k", "o"); // -> 0 (false)
test_04:

std::vector<std::tuple<std::string, std::string>> edges {
  {"i", "j"},
  {"k", "i"},
  {"m", "k"},
  {"k", "l"},
  {"o", "n"}
};

undirectedPath(edges, "i", "o"); // -> 0 (false)
test_05:

std::vector<std::tuple<std::string, std::string>> edges {
  {"b", "a"},
  {"c", "a"},
  {"b", "c"},
  {"q", "r"},
  {"q", "s"},
  {"q", "u"},
  {"q", "t"}
};


undirectedPath(edges, "a", "b"); // -> 1 (true)
test_06:

std::vector<std::tuple<std::string, std::string>> edges {
  {"b", "a"},
  {"c", "a"},
  {"b", "c"},
  {"q", "r"},
  {"q", "s"},
  {"q", "u"},
  {"q", "t"}
};

undirectedPath(edges, "a", "c"); // -> 1 (true)
test_07:

std::vector<std::tuple<std::string, std::string>> edges {
  {"b", "a"},
  {"c", "a"},
  {"b", "c"},
  {"q", "r"},
  {"q", "s"},
  {"q", "u"},
  {"q", "t"}
};

undirectedPath(edges, "r", "t"); // -> 1 (true)
test_08:

std::vector<std::tuple<std::string, std::string>> edges {
  {"b", "a"},
  {"c", "a"},
  {"b", "c"},
  {"q", "r"},
  {"q", "s"},
  {"q", "u"},
  {"q", "t"}
};

undirectedPath(edges, "r", "b"); // -> 0 (false)
test_09:

std::vector<std::tuple<std::string, std::string>> edges {
  {"s", "r"},
  {"t", "q"},
  {"q", "r"}
};

undirectedPath(edges, "r", "t"); // -> 1 (true)
*/

#include <vector>
#include <tuple>
#include <string>
#include <map>
#include <set>
using namespace std;

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

bool hasPath(map<string, vector<string> > graph, string src, string dst, set<string> s)
{
    if(dst.compare(src) == 0) return true;
    if(s.find(src) != s.end()) return false;
    s.insert(src);
    for(auto neighbour : graph[src])
    {
        if(hasPath(graph, neighbour, dst, s)) return true;
    }
    return false;
}
bool undirectedPath(std::vector<std::tuple<std::string, std::string>> edges, std::string src, std::string dst) {
    map<string, vector<string> > graph;
    getAdjacencyList(edges, graph);
    set<string> s;
    return hasPath(graph, src, dst, s);
}



int main() {
    std::vector<std::tuple<std::string, std::string>> edges {
        {"b", "a"},
        {"c", "a"},
        {"b", "c"},
        {"q", "r"},
        {"q", "s"},
        {"q", "u"},
        {"q", "t"}
    };
}
