#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10006];
vector<int> visited(10000,0);
stack<int> s;
void topologicalsort(int node)
{      
    visited[node]=1;
    for(auto x:graph[node])
    {
        if(visited[x]==0)
        {   
            visited[x]=1;
            topologicalsort(x);
        }
    }
    s.push(node);
}
int main()
{   
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }   
    for(i=0;i<n;i++)
    {   
        if(visited[i]==0)
        {   
            topologicalsort(i);
        }
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}