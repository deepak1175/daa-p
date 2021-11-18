#include<bits/stdc++.h>
using namespace std;
void ssum(int ind,int sum,int n,vector<int> v,vector<int> &ans)
{   
    if(ind==n)
    {
        ans.push_back(sum);
        return;
    }
    ssum(ind+1,sum+v[ind],n,v,ans);
    ssum(ind+1,sum,n,v,ans);
}
int main()
{   
    int n,i;
    cin>>n;
    vector<int> v(n),ans;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    ssum(0,0,n,v,ans);
    sort(ans.begin(),ans.end());
    for(auto x:ans)
    {
        cout<<x<<" ";
    }
    return 0;
}