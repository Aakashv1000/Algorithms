#include<iostream>

using namespace std;

const int MAX = 20;

int split(int arr[],int lower,int upper)
{
   int p,q,t,i;

   p = lower+1;
   q=upper;
   i = lower;

   while(q>=p)
   {
      while(arr[i]>arr[p])
      	p++;
      while(arr[i]<arr[q])
      	q--;
      if(q>p){
       t = arr[p];
       arr[p] = arr[q];
       arr[q] = t;
      }
   }

   t = arr[lower];
   arr[lower] = arr[q];
   arr[q] = t;

   return q;
}


void quicksort(int arr[],int lower,int upper)
{
   if(upper >= lower)
   {
   	int i = split(arr,lower,upper);
   	quicksort(arr,lower,i-1);
   	quicksort(arr,i+1,upper);
   }
}

int main(){

int arr[MAX];

int n;
cin>>n;

for(int i=0;i<n;i++)
    cin>>arr[i];

cout<<"Unsorted array: \n";
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

quicksort(arr,0,n-1);

cout<<"\nSorted array: \n";
for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

}