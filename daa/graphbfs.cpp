#include<bits/stdc++.h>
using namespace std;
vector<int> visited(1000005,0);
vector<int> adj[100000];
void bfs(int node)
{
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty())
    {   
        int n=q.front();
        cout<<n<<" ";
        q.pop();
        for(auto x:adj[n])
        {
            if(visited[x]==0)
            {
                q.push(x);
                visited[x]=1;
            }
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
            bfs(i);
        }
    }
    return 0;
}