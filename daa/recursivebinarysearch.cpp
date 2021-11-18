#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> v,int l,int r,int key)
{   
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        if(v[mid]==key)
        {
            return mid+1;
        }
        else if(v[mid]>key)
        {
            return binary_search(v,l,mid-1,key);
        }
        else
        {
            return binary_search(v,mid+1,r,key);
        }
    }
    return -1;
}
int main()
{   
    int n,i;
    cin>>n;
    vector<int> v;
    for(i=0;i<n;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    int key;
    cin>>key;
    int ans=binary_search(v,0,n,key);
    if(ans==-1)
    {
        cout<<"NOT FOUND"<<endl;
    }
    else
    {
        cout<<"FOUND AT LOCATION "<<ans<<endl;
    }
    return 0;
}