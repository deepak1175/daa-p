#include<bits/stdc++.h>
using namespace std;
struct meeting
{
    int starttime;
    int endtime;
    int no;
    meeting(int a,int b,int c)
    {
        starttime=a;
        endtime=b;
        no=c;
    }
};
int compare(meeting a,meeting b)
{   
    if(a.endtime==b.endtime)
    {
        return a.no<b.no;
    }
    return a.endtime<b.endtime;
}
int main()
{   
    int n,i;
    cout<<"Enter no of meetings: ";
    cin>>n;
    vector<meeting> v;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(meeting(a,b,i+1));
    }
    sort(v.begin(),v.end(),compare);
    vector<int> ans;
    int e=v[0].endtime;
    ans.push_back(v[0].no);
    for(i=1;i<n;i++)
    {
        if(v[i].starttime>e)
        {
            ans.push_back(v[i].no);
            e=v[i].endtime;
        }
    }
    for(i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}