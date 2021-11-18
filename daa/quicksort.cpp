#include<bits/stdc++.h>
using namespace std;
void quicksort(int* a,int l,int r)
{       
    if(l>=r)
    {
        return;
    }
    int i=0,j=0;
    int pivot=a[r];
    while(i<=r)
    {
        if(a[i]<=pivot)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    quicksort(a,0,j-1-1);
    quicksort(a,j,r);
}
int main()
{   
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}