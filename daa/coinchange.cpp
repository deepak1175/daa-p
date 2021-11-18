#include<bits/stdc++.h>
using namespace std;
int coinsum(int idx,int n,vector<int> v,int sum,vector<vector<int>> &dp)
{   
    if(sum<0)
    {
        return 0;
    }
    if(idx>=n)
    {
        return 0;
    }
    if(sum==0)
    {
        return 1;
    }
    if(dp[idx][sum]!=-1)
    {
        return dp[idx][sum];
    }
    int left=coinsum(idx,n,v,sum-v[idx],dp);
    int right=coinsum(idx+1,n,v,sum,dp);
    return dp[idx][sum]=left+right;
}
int main()
{   
    int n,i,sum;
    cin>>n;
    vector<int> v;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    cin>>sum;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    cout<<coinsum(0,n,v,sum,dp);
    return 0;
}