#include<iostream>

using namespace std;

const int MAX = 10;




void merge(int arr[],int l,int m,int r)
{
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1],R[n2];

	for(int i =0;i<n1;i++)
		L[i] = arr[i+l];
	for(int i = 0;i<n2;i++)
		R[i] = arr[m+1+i];

	int i,j,k;

	for(i=j=0,k=l;i<n1 && j<n2 ;)
	{
		if(L[i]<= R[j])
		{
			arr[k++] = L[i++];
		}else
		    arr[k++] = R[j++];

		    if(i == n1 || j == n2)
		    	break;

	}

	for( ; i<n1 ; )
		arr[k++] = L[i++];
	for(; j<n2 ;)
		arr[k++] = R[j++];


}

void mergeSort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m = l +(r-1)/2;

		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}

int main()
{
	int n;
   cin>>n;

   int arr[n];

   for(int i=0;i<n;i++)
	   cin>>arr[i];

	cout<<"\nunsorted array: \n";

	for(int i=0;i<n;i++)
	   cout<<arr[i]<<" ";
    
    mergeSort(arr,0,n-1);

	cout<<"\n Sorted array: \n";
	 for(int i=0;i<n;i++)
	   cout<<arr[i]<<" "; 	
	return 0;
}