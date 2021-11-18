#include<bits/stdc++.h>
using namespace std;
vector<int> visited(1000005,0);
vector<int> adj[100000];
void dfs(int node)
{
    cout<<node<<" ";
    visited[node]=1;
    for(auto x:adj[node])
    {
        if(visited[x]==0)
        {
            dfs(x);
        }
    }
}
int main()
{   
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    return 0;
}