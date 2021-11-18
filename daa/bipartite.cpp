#include<bits/stdc++.h>
using namespace std;
bool bipartitedfs(int node,vector<int> graph[],vector<int> colour)
{   
    if(colour[node]==-1)
    {
        colour[node]=1;
    }
    for(auto x:graph[node])
    {
        if(colour[x]==-1)
        {
            colour[x]=1-colour[node];
            if(!bipartitedfs(x,graph,colour))
            {
                return false;
            }
        }
        else if(colour[x]==colour[node])
        {
            return false;
        }
    }
    return true;
}
bool checkbipartite(int n,vector<int> colour,vector<int> graph[])
{
    for(int i=0;i<n;i++)
    {
        if(colour[i]==-1)
        {
            if(!bipartitedfs(i,graph,colour))
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{   
    int n,m,i;
    cin>>n>>m;
    vector<int> graph[n];
    for(i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> colour(n,-1);
    if(checkbipartite(n,colour,graph))
    {
        cout<<"BIPARTITE GRAPH"<<endl;
    }
    else
    {
        cout<<"NOT BIPARTITE"<<endl;
    }
    return 0;
}