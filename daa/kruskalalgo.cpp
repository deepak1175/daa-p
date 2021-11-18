#include<bits/stdc++.h>
using namespace std;
vector<int> r(100000);
vector<int> parent(1000000);
struct node
{
    int u;
    int v;
    int weight;
    node(int a,int b,int c)
    {
        u=a;
        v=b;
        weight=c;
    }
};
int comp(node a,node b)
{
    return a.weight<b.weight;
}
int findparent(int n)
{
    if(n==parent[n])
    {
        return n;
    }
    return parent[n]=findparent(parent[n]);
}
void uni(int u,int v)
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
    vector<node> temp;
    vector<pair<int,int>> ans;
    int n,e,i; //n=node  e=edges
    cin>>n>>e;
    for(i=0;i<e;i++)
    {   
        int u,v,weight;
        cin>>u>>v>>weight;
        temp.push_back(node(u,v,weight));
    }
    sort(temp.begin(),temp.end(),comp);
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
        r[i]=0;
    }
    int totalweight=0;
    for(auto x:temp)
    {
        if(findparent(x.u)!=findparent(x.v))
        {
            totalweight+=x.weight;
            ans.push_back(make_pair(x.u,x.v));
            uni(x.u,x.v);
        }
    }
    cout<<"total wieght: "<<totalweight<<endl;
    for(auto x:ans)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}