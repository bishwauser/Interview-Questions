#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
using namespace std;

map< char, vector<char> > graph = {
    {'f', {'g', 'i'}},
    {'g', {'h'}},
    {'h', {}},
    {'i', {'g', 'k'}},
    {'j', {'i'}},
    {'k', {}}
};

void bfs(const char &n, map< char, vector<char> > graph)
{
    queue<char> q;
    q.push(n);
    while(!q.empty())
    {
        char cur = q.front();
        cout<<cur<<" ";
        q.pop();
        for(char neighbour : graph[cur])
        {
            q.push(neighbour);
        }
    }
    cout<<endl;
}

void dfsUsingIteration(const char &n, map< char, vector<char> > graph)
{
    stack<char> s;
    s.push(n);
    while(!s.empty())
    {
        char cur = s.top();
        cout<<cur<<" ";
        s.pop();
        for(char neighbour : graph[cur])
        {
            s.push(neighbour);
        }
    }
    cout<<endl;
}

void dfsUsingRecursion(const char &n, map< char, vector<char> > graph)
{
    cout<<n<<" ";
    for(char neighbour : graph[n])
    {
        dfsUsingRecursion(neighbour, graph);
    }
    //cout<<endl;
}

int main()
{
    bfs('f', graph);
    dfsUsingRecursion('f', graph);
    cout<<endl;
    dfsUsingIteration('f', graph);
    return 0;
}
