#include<bits/stdc++.h>
using namespace std;
void bubblesort(vector<int> v)
{   
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i]>v[j])
            {
                int temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
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
    bubblesort(v);
    return 0;
}