#include<iostream>
using namespace std;

bool ispossible(int arr[],int m,int n,int mid){
    int painterscount=0;
    int blockcount=0;
    for (int i = 0; i < n; i++)
    {
        if (blockcount+arr[i]<=mid)
        {
            blockcount+=arr[i];
        }
        else{
            painterscount++;
            if (painterscount>m || arr[i]>mid)
            {
               return false;
            }
            blockcount=arr[i];
        }
    }
    return true;
}
int findpartion(int arr[],int n,int m){
    int s=0,sum=0,ans=-1;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int mid=s+(e-s)/2;
    while (s<e)
    {
        if(ispossible(arr,m,n,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int arr[5]={5,5,5,5,5};
    int a=findpartion(arr,5,2);
    cout<<a<<endl;
return 0;
}