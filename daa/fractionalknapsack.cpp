#include<bits/stdc++.h>
using namespace std;
struct knapsack
{
    int value;
    int weight;
    int one;
    knapsack(int a,int b,double c)
    {
        value=a;
        weight=b;
        one=c;
    }
};
int compare(knapsack a,knapsack b)
{
    return a.one>b.one;
}
int main()
{   
    int n,i,w;
    cout<<"Enter no of items and weight of knapsack: ";
    cin>>n>>w;
    vector<knapsack> v;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        double c=(double)a/b;
        v.push_back(knapsack(a,b,c));
    }
    sort(v.begin(),v.end(),compare);
    int currentweight=0;
    double ansvalue=0.0;
    for(i=0;i<n;i++)
    {
        if(currentweight+v[i].weight<=w)
        {
            currentweight+=v[i].weight;
            ansvalue+=v[i].value;
        }
        else
        {
            int remaining=w-currentweight;
            ansvalue+=(v[i].one*remaining);
            break;
        }
    }
    cout<<ansvalue<<endl;
    return 0;
}