#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e,i,j,source;
    cin>>n>>e;
    vector<pair<int,int>> g[n+1];
    for(i=0;i<e;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        g[u].push_back(make_pair(v,weight));
        g[v].push_back(make_pair(u,weight));
    }
    cin>>source;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
    p.push(make_pair(0,source));
    vector<int> dist(n+1,INT_MAX);
    dist[source]=0;
    while(!p.empty())
    {
        int dis=p.top().first;
        int node=p.top().second;
        p.pop();
        for(auto x:g[node])
        {   
            int v=x.first;
            int weight=x.second;
            if(dist[v]>weight+dis)
            {
                dist[v]=weight+dis;
                p.push(make_pair(dist[v],v));
            }
        }
    }
    cout<<"The distance from "<< source<<" are :\n";
    for(i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
}