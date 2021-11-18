#include<bits/stdc++.h>
using namespace std;
vector<int> r(100000);
vector<int> parent(100000);
int findparent(int n)
{
    if(n==parent[n])
    {
        return n;
    }
    return parent[n]=findparent(parent[n]);
}
void un(int u,int v)
{
    u=findparent(u);
    v=findparent(v);
    if(r[u]==r[v])
    {
        parent[v]=u;
        r[u]++;
    }
    else if(r[u]<r[v])
    {
        parent[u]=v;
    }
    else
    {
        parent[v]=u;
    }
}

int main()
{   
    int n,i,uni;
    cout<<"Enter no of nodes: ";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
        r[i]=0;
    }
    cout<<"Enter no of union operations: ";
    cin>>uni;
    for(i=0;i<uni;i++)
    {
        int u,v;
        cin>>u>>v;
        un(u,v);
    }
    for(i=1;i<=n;i++)
    {
        cout<<findparent(i)<<" ";
    }
    return 0;
}