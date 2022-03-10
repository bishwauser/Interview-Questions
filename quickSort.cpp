#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int> &v, int l, int r)
{
    int pivot = v[r];
    int i = l-1;
    for(int j=l; j<r; j++)
    {
        if(v[j]<pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return i+1;
}

void quickSort(vector<int> &v, int i, int j)
{
    if(i>j)
    {
        return;
    }
    int pivot = partition(v,i,j);
    quickSort(v, 0, pivot-1);
    quickSort(v, pivot+1, j);
}

void print(vector<int> &v)
{
    for(auto x:v) cout<<x<<" ";
    cout<<endl;
}


int main()
{
    vector<int> v = {2,5,1,23,14,99,2,55};
    quickSort(v, 0, v.size()-1);
    print(v);
}