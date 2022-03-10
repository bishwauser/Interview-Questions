/*
Write a function, islandCount, that takes in a grid containing Ws and Ls. W represents water and L represents land. The function should return the number of islands on the grid. An island is a vertically or horizontally connected region of land.

test_00:

std::vector<std::vector<char>> grid {
  {'W', 'L', 'W', 'W', 'W'},
  {'W', 'L', 'W', 'W', 'W'},
  {'W', 'W', 'W', 'L', 'W'},
  {'W', 'W', 'L', 'L', 'W'},
  {'L', 'W', 'W', 'L', 'L'},
  {'L', 'L', 'W', 'W', 'W'}
};
islandCount(grid); // -> 3
test_01:

std::vector<std::vector<char>> grid {
  {'L', 'W', 'W', 'L', 'W'},
  {'L', 'W', 'W', 'L', 'L'},
  {'W', 'L', 'W', 'L', 'W'},
  {'W', 'W', 'W', 'W', 'W'},
  {'W', 'W', 'L', 'L', 'L'}
};
islandCount(grid); // -> 4
test_02:

std::vector<std::vector<char>> grid {
  {'L', 'L', 'L'},
  {'L', 'L', 'L'},
  {'L', 'L', 'L'}
};
islandCount(grid); // -> 1
test_03:

std::vector<std::vector<char>> grid {
  {'W', 'W'},
  {'W', 'W'},
  {'W', 'W'}
};
islandCount(grid); // -> 0
*/

#include <vector>
#include <iostream>
using namespace std;

bool dfs(std::vector<std::vector<char>> grid, int i, int j, int row, int col, vector< vector<bool> > &visited)
{
    if(i>=row || i<0 || j>=col || j<0 || grid[i][j] == 'W') return true;
    if(visited[i][j]) return false;
    cout<<i<<" "<<j<<" "<<grid[i][j]<<endl;
    visited[i][j] = true;
    // if(dfs(grid, i+1, j, row, col, visited) &&
    //   dfs(grid, i, j+1, row, col, visited) &&
    //   dfs(grid, i-1, j, row, col, visited) &&
    //   dfs(grid, i, j-1, row, col, visited) )
    dfs(grid, i+1, j, row, col, visited);
    dfs(grid, i, j+1, row, col, visited);
    dfs(grid, i-1, j, row, col, visited);
    dfs(grid, i, j-1, row, col, visited);
    return true;
}

int islandCount(std::vector<std::vector<char>> grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector< vector<bool> > visited(row,vector(col,false));
    int count = 0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j] != 'W')
            {
                count += dfs(grid, i, j, row, col, visited);
                cout<<"count = "<<count<<endl;
            }
        }
    }
    return count;
}


int main() {
    std::vector<std::vector<char>> grid {
      {'W', 'L', 'W', 'W', 'W'},
      {'W', 'L', 'W', 'W', 'W'},
      {'W', 'W', 'W', 'L', 'W'},
      {'W', 'W', 'L', 'L', 'W'},
      {'L', 'W', 'W', 'L', 'L'},
      {'L', 'L', 'W', 'W', 'W'}
    };islandCount(grid);
}
