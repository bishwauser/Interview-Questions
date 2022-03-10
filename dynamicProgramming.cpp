#include<iostream>
#include<map>
using namespace std;

//find the no of possible paths from top left corner to bottom-rignt corner of a matrix
//allowed traversal: down or right

int countPath(int n, int m, map<string, int> &memo)
{
    string key = to_string(n)+","+to_string(m);
    if(memo.find(key) != memo.end()) return memo[key];
    if(n==1 && m==1) return 1;
    if(n==0 || m==0) return 0;
    memo[key] = countPath(n-1, m, memo) + countPath(n, m-1, memo);
    return memo[key];
}


//fibonacci series
int fibonacci(int pos, map<int, int> &memo)
{
    if(memo.find(pos) != memo.end()) return memo[pos];
    if(pos <= 2)return 1;
    memo[pos] = fibonacci(pos-1, memo)+fibonacci(pos-2, memo);
    return memo[pos];
}

int main()
{
    //cout<<fibonacci(37, *(new map<int,int>()))<<endl;
    cout<<countPath(18,18,*(new map<string,int>()))<<endl;
    return 0;
}