/*
Question: 
    1. Given a 2D matrix javing 0s and 1s only.
    2. Concider all 1's as land and all 0's as water.
    3. An island is a group of 1s adjescent to each other(not diagonally)
    4. remove all islands that are not connected to the edge

Algo:
    1. iterate all the elements on the edge and record them in another 2D array of same size
    2. while iterating also find all the connected 1s using recursion and record in the above array
    3. iterate over the array and check of the element is 1 and visited and change it to 0
*/



#include <iostream>
#include <vector>
using namespace std;

//utility function to print the matrix
void print(const vector<vector<int> > &matrix, const int &n, const int &m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<matrix[i][j]<< " ";
        }
        cout<<endl;
    }
}

//records all the connected 1s in visited[][]
void recordMainLands(const vector<vector<int> > &matrix,
                    vector<vector<bool> > &visited,
                    const int &n, const int &m,
                    int i, int j)
{
    //return if out of bounds or already visited or is '0'
    if((i<0 || j<0 || i > n-1 || j > m-1) ||
        visited[i][j] ||
        !matrix[i][j])
    {
        return;
    }
    //set visited
    visited[i][j] = true;
    //check recursively all other connected 1s
    recordMainLands(matrix, visited, n, m, i+1, j);
    recordMainLands(matrix, visited, n, m, i, j+1);
    recordMainLands(matrix, visited, n, m, i-1, j);
    recordMainLands(matrix, visited, n, m, i, j-1);
}

//removes all isolated group of 1s
void removeClosedIsland(vector<vector<int> > &matrix, const int &n, const int &m)
{
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            //only for the edge elements
            if((i*j==0 || i==n-1 || j==m-1) &&
                !visited[i][j] &&
                matrix[i][j])
            {
                recordMainLands(matrix, visited, n, m, i, j);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!visited[i][j] && matrix[i][j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    // Given size of Matrix
    int N = 5, M = 8;
 
    // Given Matrix
    vector<vector<int> > matrix
        = { { 0, 1, 0, 0, 0, 0, 0, 1 },
            { 0, 1, 1, 1, 0, 1, 0, 1 },
            { 0, 1, 0, 0, 1, 0, 0, 1 },
            { 0, 1, 1, 1, 0, 0, 1, 0 },
            { 0, 0, 0, 0, 0, 1, 0, 1 } };

    print(matrix, N, M);
    cout<<endl;
    removeClosedIsland(matrix, N, M);
    print(matrix, N, M);
    return 0;
}

