#include<bits/stdc++.h>
using namespace std;
void insertionsort(vector<int> v)
{   
    int j=0;
    for(int i=1;i<v.size();i++)
    {   
        int element=v[i];
        j=i-1;
        while(v[j]>element&&j>=0)
        {
            int temp=v[j];
            v[j]=v[j+1];
            v[j+1]=temp;
            j--;
        }
        v[j+1]=element;
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
    insertionsort(v);
    return 0;
}