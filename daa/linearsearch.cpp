#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,i,f=0;
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
    for(i=0;i<n;i++)
    {
        if(v[i]==key)
        {
            f=1;
            break;
        }
    }
    if(f==0)
    {
        cout<<"NOT FOUND"<<endl;
    }
    else
    {
        cout<<"FOUND AT LOCATION "<<i+1<<endl;
    }
    return 0;
}