#include<bits/stdc++.h>
using namespace std;
int func(int ind,int weight,vector<int> &value,vector<int> &wt,int n,vector<vector<int>> &dp)
{
    if(weight==0)
    {
        return 0;
    }
    if(ind>=n)
    {
        return 0;
    } 
    if(dp[ind][weight]!=-1)
    {
        return dp[ind][weight];
    }
    if(wt[ind]<=weight)
    {
        int left=value[ind]+ func(ind+1,weight-wt[ind],value,wt,n,dp);
        int right=func(ind+1,weight,value,wt,n,dp);
        return dp[ind][weight]=max(left,right);
    }
    else
    {
        return dp[ind][weight]=func(ind+1,weight,value,wt,n,dp);
    }
}
int main()
{   
    int n,i,weight;
    cout<<"enter no of items: ";
    cin>>n;
    vector<int> value(n),wt(n);
    cout<<"Enter values and the weights of items"<<endl;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        value.push_back(a);
        wt.push_back(b);
    }
    cout<<"Enter weight of bag: ";
    cin>>weight;
    vector<vector<int>> dp(n+1,vector<int>(weight+1,-1));
    int ans=func(0,weight,value,wt,n,dp);
    cout<<ans<<endl;
    return 0;
}