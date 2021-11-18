#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,e,i,j;
    cin>>n>>e;
    vector<pair<int,int>> graph[n];
    for(i=0;i<e;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        graph[u].push_back(make_pair(v,weight));
        graph[v].push_back(make_pair(u,weight));
    }
    bool mst[n];
    int key[n];
    int parent[n];
    for(i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mst[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    int answeight=0;
    int u;
    for(i=0;i<e-1;i++)
    {
        int m=INT_MAX;
        for(j=0;j<n;j++)
        {
            if(mst[j]==false&&m>key[j])
            {
                m=key[j];
                u=j;
            }
        }
        mst[u]=true;
        for(auto x:graph[u])
        {
            int v=x.first;
            int w=x.second;
            if(mst[v]==false&&w<key[v])
            {
                key[v]=w;
                parent[v]=u;
            }
        }

        for(i=1;i<n;i++)
        {
            cout<<parent[i]<<" "<<i<<endl;
        }
    }
    return 0;
}