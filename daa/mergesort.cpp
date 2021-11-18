#include<bits/stdc++.h>
using namespace std;
vector<int> mergesort(vector<int> v,int lo,int high)
{   
    if(lo==high)
    {
        vector<int> temp;
        temp.push_back(v[lo]);
        return temp;
    }
    int mid=lo+(high-lo)/2;
    int i=0,j=0;
    vector<int> v1,v2;
    v1=mergesort(v,lo,mid);
    v2=mergesort(v,mid+1,high);
    vector<int> res;
    while(i<v1.size()&&j<v2.size())
    {
        if(v1[i]<v2[j])
        {
            res.push_back(v1[i]);
            i++;
        }
        else
        {
            res.push_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size())
    {
        res.push_back(v1[i]);
        i++;
    }
    while(j<v2.size())
    {
        res.push_back(v2[j]);
        j++;
    }
    return res;
}
int main()
{   
    int n,i;
    cin>>n;
    vector<int> v,v1;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    v1=mergesort(v,0,n-1);
    set<int> s;
    for(auto x:v1)
    {
        cout<<x<<" ";
    }
    // for(auto x:s)
    // {
    //     cout<<x<<" ";
    // }
    cout<<endl;
    return 0;
}