#include<bits/stdc++.h>
using namespace std;
int mcm(int i,int j,vector<int> v,vector<vector<int>> &dp)
{
    int ans=INT_MAX;
    int k;
    int count;
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    for(k=i;k<j;k++)
    {
        count=mcm(i,k,v,dp)+mcm(k+1,j,v,dp)+v[i-1]*v[k]*v[j];
        if(count<ans)
        {
            ans=count;
        }
    }
    return dp[i][j]=ans;
}
int main()
{   
    int n,i,j;
    cout<<"enter no of matrixes: ";
    cin>>n;
    vector<int> v;
    for(i=0;i<n+1;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    vector<vector<int>> dp(n,vector<int>(n+2,-1));
    long long int ans=mcm(1,n,v,dp);
    cout<<ans<<endl;
    return 0;
}