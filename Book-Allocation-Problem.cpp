#include<iostream>
#include<vector>
using namespace std;

int IsValid(vector <int>arr,int n,int m,int mid)
{ 
  
  int students=1,pages=0;
  for(int i=0;i<n;i++)
  { 
    if(arr[i]>mid)
    {
      return false;
    }
    if(pages+arr[i]<=mid)
    {
      pages+=arr[i];
    }
    else{
      students++;
      pages=arr[i];
    }
  }
  return students >m ? false : true;
  
}


int AllocateBooks(vector <int>arr,int n ,int m)
{  
  int sum=0,ans=-1;
  for(int i=0;i<n;i++)
  {
    sum+=arr[i];
  }
   int st=0,end=sum;
   while(st<=end)
   {
    int mid=st+(end-st)/2;
    if(IsValid(arr,n,m,mid))
    { ans=mid;
      end=mid-1;
    }
    else{
      st=mid+1;
    }
   }
   return ans;
}




int main()
{                
  vector<int> arr={2,1,3,4};
  int n=4,m=2;
  cout<< AllocateBooks(arr,n,m)<<endl;
  return 0;
}
