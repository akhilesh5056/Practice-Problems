
//problem statement 
/* There are paint n boards of length {l1,l2...ln} and there are k painters available.Each painter take 1 unit of time to paint 1 unit of the board .
The board is found to find the minimum time to get this job under the constraints that any painter will only paint continuous sections of boards*/


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
