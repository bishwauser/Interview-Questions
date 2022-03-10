/*
Write a function, minimumIsland, that takes in a grid containing Ws and Ls. W represents water and L represents land.
The function should return the size of the smallest island.
An island is a vertically or horizontally connected region of land.

You may assume that the grid contains at least one island.

test_00:
std::vector<std::vector<char>> grid {
  {'W', 'L', 'W', 'W', 'W'},
  {'W', 'L', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'L', 'W'},
  {'W', 'W', 'L', 'L', 'W'},
  {'L', 'W', 'W', 'L', 'L'},
  {'L', 'L', 'W', 'W', 'W'}
};
minimumIsland(grid); // -> 2

test_01:
std::vector<std::vector<char>> grid {
  {'L', 'W', 'W', 'L', 'W'},
  {'L', 'W', 'W', 'L', 'L'},
  {'W', 'L', 'W', 'L', 'W'},
  {'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'L', 'L', 'L'}
};
minimumIsland(grid); // -> 1

test_02:
std::vector<std::vector<char>> grid {
  {'L', 'L', 'L'},
  {'L', 'L', 'L'},
  {'L', 'L', 'L'}
};
minimumIsland(grid); // -> 9

test_03:
std::vector<std::vector<char>> grid {
  {'W', 'W'},
  {'L', 'L'},
  {'W', 'W'},
  {'W', 'L'}
};
minimumIsland(grid); // -> 1
*/



#include <vector>
#include <limits.h>
#include <iostream>
using namespace std;

int dfs(std::vector<std::vector<char>> grid, int i, int j, int row, int col, vector< vector<bool> > &visited)
{
    if(i>=row || i<0 || j>=col || j<0 || grid[i][j] == 'W') return 0;
    if(visited[i][j]) return 0;
    //cout<<i<<" "<<j<<" "<<grid[i][j]<<endl;
    visited[i][j] = true;
    int size = 1;
    size += dfs(grid, i+1, j, row, col, visited);
    size += dfs(grid, i, j+1, row, col, visited);
    size += dfs(grid, i-1, j, row, col, visited);
    size += dfs(grid, i, j-1, row, col, visited);
    return size;
}
int minimumIsland(std::vector<std::vector<char>> grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector< vector<bool> > visited(row,vector(col,false));
    int count = 0, minCount = INT_MAX;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j] != 'W' && !visited[i][j])
            {
                count = dfs(grid, i, j, row, col, visited);
                //cout<<count<<endl;
                if(count<minCount)
                {
                    minCount = count;
                }
            }
        }
    }
    return minCount;
}


void run() {
  std::vector<std::vector<char>> grid {
    {'L', 'W', 'W', 'L', 'W'},
    {'L', 'W', 'W', 'L', 'L'},
    {'W', 'L', 'W', 'L', 'W'},
    {'W', 'W', 'W', 'W', 'W'},
    {'W', 'W', 'L', 'L', 'L'}
  };
  cout<<minimumIsland(grid);
}
