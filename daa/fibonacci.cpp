#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,i=0;
    cin>>n;
    int a=0,b=1;
    cout<<a<<" "<<b<<" ";
    while(i<n-2)
    {   
        int c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
        i++;
    }
    return 0;
}