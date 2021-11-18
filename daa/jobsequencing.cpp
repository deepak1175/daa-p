#include<bits/stdc++.h>
using namespace std;
struct job
{
    int job_id;
    int deadline;
    int profit;
    job(int a,int b,int c)
    {
        job_id=a;
        deadline=b;
        profit=c;
    }
};
int compare(job a,job b)
{
    return a.profit>b.profit;
}
int main()
{       
    int n,i,j;
    cout<<"Enter no of jobs: ";
    cin>>n;
    vector<job> v;
    for(i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(job(a,b,c));
    }
    sort(v.begin(),v.end(),compare);
    int m=INT_MIN;
    for(i=0;i<n;i++)
    {
        m=max(m,v[i].deadline);
    }
    vector<int> ans(m+1,-1);
    int noofjobs=0;
    int pro=0;
    for(i=0;i<n;i++)
    {
        int a;
        a=v[i].deadline;
        for(j=a;j>0;j--)
        {
            if(ans[j]==-1)
            {
                ans[j]=i;
                pro+=v[i].profit;
                noofjobs++;
                break;
            }
        }
    }
    cout<<"No of jobs: "<<noofjobs<<endl;
    cout<<"Total profit: "<<pro<<endl;
    return 0;
}