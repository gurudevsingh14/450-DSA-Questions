#include<iostream>
using namespace std;

void rearrange(int a[],int n)
{
    int left=0,right=n-1;
    while(left<=right)
    {
        if(a[left]<0&&a[right]<0){
            left++;
        }
        else if(a[left]<0&&a[right]>=0){
            left++;
            right--;
        }
        else if(a[left]>=0&&a[right]<0){
            swap(a[left],a[right]);
            left++;
            right--;
        }
        else{
            right--;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    rearrange(a,n);

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
