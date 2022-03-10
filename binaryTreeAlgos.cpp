//BinaryTree ALGO
#include <iostream>
#include <queue>
using namespace std;

class BT;

class node
{
    int data;
    node *left;
    node *right;
    public:
    node(int val = 0, node *l = NULL, node *r = NULL)
    {
        data = val;
        left = l;
        right = r;
    }
    friend class BT;
};

class BT
{
    node *root;
    public:
    BT(node *r = NULL)
    {
        root = r;
    }
    //tree creation in level order fashion from array
    void createBTFromArray(vector<int> arr)
    {
        queue<node*> q;
        node* temp;
        for(auto val:arr)
        {
            temp = new node(val);
            if(!root)
            {
                root = temp;
            }
            else if(!q.front()->left)
            {
                q.front()->left = temp;
            }
            else
            {
                q.front()->right = temp;
                q.pop();
            }
            q.push(temp);
        }
    }
    void levelOrder()
    {
        if(!root)
        {
            return;
        }
        queue<node*> q;
        q.push(root);
        while(!q.empty())
        {
            cout<<q.front()->data<<" ";
            if(q.front()->left)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
        }
        cout<<endl;
    }

    void mirrorTree()
    {
        mirrorUtil(root);
    }
    void printKthLevel(int k)
    {
        printKthLevelUtil(root, 1, k);
        cout<<endl;
    }

    void testFunc()
    {
        if(!root)
        {
            return;
        }
        queue<node*> q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            int len = q.size();
            int count = 1;
            bool found = false;
            while(len)
            {
                if(count == level)
                {
                    cout<<q.front()->data<<endl;
                    found = true;
                }
                if(q.front()->left)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right)
                {
                    q.push(q.front()->right);
                }
                q.pop();
                len--;
                count++;
            }
            if(!found)
            {
                cout<<"-1"<<endl;
            }
            level++;
        }
    }

    private:
    void mirrorUtil(node *r)
    {
        if(!r)
        {
            return;
        }
        mirrorUtil(r->left);
        mirrorUtil(r->right);
        node* temp = r->left;
        r->left = r->right;
        r->right = temp;
    }

    void printKthLevelUtil(node* r, int level, int k)
    {
        if(!r || level>k)
        {
            return;
        }
        printKthLevelUtil(r->left, level+1, k);
        printKthLevelUtil(r->right, level+1, k);
        if(level == k)
        {
            cout<<r->data<<" ";
        }
    }
};

int main()
{
    BT tree;
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    tree.createBTFromArray(arr);
    tree.levelOrder();
    //tree.mirrorTree();
    //tree.levelOrder();
    //tree.printKthLevel(3);
    tree.testFunc();
}
