#include<iostream>

using namespace std;

struct node
{
    int left, right;
};

void build(node *tree, int n){
    for (int i = 1; i < n; i++)
    {
        cin >> (tree + i)->left >> (tree + i)->right;
    }
}

int dfs(node *tree, int x){
    if (x==0)
        return 0;
    return max(dfs(tree, tree[x].left), dfs(tree, tree[x].right))+1;
}

int main(){
    int depth;
    cin >> depth;
    node *tree = new node[depth + 1];
    build(tree, depth);
    cout << dfs(tree, 1)<<endl;
}