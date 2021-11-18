#include<bits/stdc++.h>
using namespace std;
int lcs(int i,int j,string s,string s1)
{
    int dp[s.length()][s1.length()];
    for(int a=0;a<s.length();a++)
    {
        for(int b=0;b<s1.length();b++)
        {
            dp[a][b]=-1;
        }
    }
    if(i>=s.length()||j>=s1.length())
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==s1[j])
    {
        return dp[i][j]=1+lcs(i+1,j+1,s,s1);
    }
    else
    {
        int left=lcs(i+1,j,s,s1);
        int right=lcs(i,j+1,s,s1);
        return dp[i][j]=max(left,right);
    }
}
int main()
{   
    string s,s1;
    cout<<"Enter the strings"<<endl;
    cin>>s>>s1;
    int ans=lcs(0,0,s,s1);
    cout<<ans<<endl;
    return 0;
}